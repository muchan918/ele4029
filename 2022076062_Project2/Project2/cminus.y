/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex

%}

%token IF WHILE RETURN INT VOID ELSE
%token ID NUM 
%token ASSIGN EQ NE LT LE GT GE LPAREN RPAREN LBRACE RBRACE LCURLY RCURLY SEMI COMMA
%token ERROR 

%nonassoc IFX
%nonassoc ELSE
%left PLUS MINUS
%left TIMES OVER


%% /* Grammar for TINY */
program             : declaration_list
                         { savedTree = $1;} 
                    ;
declaration_list    : declaration_list declaration
                        { 
                            YYSTYPE t = $1;
                            if (t != NULL) {
                                while (t->sibling != NULL) {
                                    t = t->sibling;
                                }
                                t->sibling = $2;
                                $$ = $1;
                            } else {
                                $$ = $2;
                            }
                        }
                    | declaration { $$ = $1; }
                    ;
declaration         : var_declaration { $$ = $1; }
                    | fun_declaration { $$ = $1; }
                    ;
var_declaration     : type_specifier identifier SEMI
                     {
                        $$ = newExpNode(VarDK);
                        $$->type = $1->type;
                        $$->typestring = $1->typestring;
                        $$->attr.name = $2->attr.name;
                     }
                    | type_specifier identifier LBRACE number RBRACE SEMI
                     {
                        $$ = newExpNode(VarDK);
                        if ($1->type == Integer) {
                            $$->type = IntegerArr;
                            $$->typestring = "int[]";
                        }
                        else if ($1->type == Void) {
                            $$->type = VoidArr;
                            $$->typestring = "void[]";
                        }
                        else $$->type = None;
                        $$->attr.name = $2->attr.name;
                        $$->child[0] = $4;
                        $$->lineno = $2->lineno;
                     }
                    ;
type_specifier      : INT 
                     { 
                        $$ = newExpNode(TypeK);
                        $$->lineno = lineno;
                        $$->type = Integer;
                        $$->typestring = "int";
                     }
                    | VOID
                     {
                        $$ = newExpNode(TypeK);
                        $$->lineno = lineno;
                        $$->type = Void;
                        $$->typestring = "void";
                     }
                    ;
fun_declaration     : type_specifier identifier LPAREN params RPAREN compound_stmt
                    {
                        $$ = newExpNode(FuncDK);
                        $$->type = $1->type;
                        $$->typestring = $1->typestring;
                        $$->attr.name = $2->attr.name;
                        $$->lineno = $2->lineno;
                        $$->child[0] = $4;
                        $$->child[1] = $6;
                    }
                    ;
params              : param_list { $$ = $1; }
                    | VOID
                     {
                        $$ = newExpNode(TypeK);
                        $$->lineno = lineno;
                        $$->type = Void;
                        $$->typestring = "void";
                     }
                    ;
param_list          : param_list COMMA param
                    { 
                        YYSTYPE t = $1;
                        if (t != NULL) {
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = $3;
                            $$ = $1;
                        } else {
                            $$ = $3;
                        }
                    }
                    | param { $$ = $1; }
                    ;
param               : type_specifier identifier
                    {
                        $$ = newExpNode(ParamK);
                        $$->type = $1->type;
                        $$->typestring = $1->typestring;
                        $$->attr.name = $2->attr.name;
                        $$->lineno = $2->lineno;
                    }
                    | type_specifier identifier LBRACE RBRACE
                    {
                        $$ = newExpNode(ParamK);
                        if ($1->type == Integer) {
                            $$->type = IntegerArr;
                            $$->typestring = "int[]";
                        }
                        else if ($1->type == Void) {
                            $$->type = VoidArr;
                            $$->typestring = "void[]";
                        }
                        else $$->type = None;
                        $$->attr.name = $2->attr.name;
                        $$->lineno = $2->lineno;
                    }
                    ;
compound_stmt       : LCURLY local_declarations statement_list RCURLY
                    {
                        $$ = newStmtNode(CompK);
                        $$->child[0] = $2;
                        $$->child[1] = $3;
                    }
                    ;
local_declarations  : local_declarations var_declaration
                    {
                        if ($1 != NULL) {
                            YYSTYPE t = $1;
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = $2;
                            $$ = $1;
                        } else {
                            $$ = $2;
                        }
                    }
                    | empty
                    ;
statement_list      : statement_list statement
                    {
                        if ($1 != NULL) {
                            YYSTYPE t = $1;
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = $2;
                            $$ = $1;
                        } else {
                            $$ = $2;
                        }
                    }
                    | empty
                    ;
statement           : expression_stmt
                    { $$ = $1; }
                    | compound_stmt
                    { $$ = $1; }
                    | selection_stmt
                    { $$ = $1; }
                    | iteration_stmt
                    { $$ = $1; }
                    | return_stmt
                    { $$ = $1; }
                    ;
expression_stmt     : expression SEMI { $$ = $1; }
                    | SEMI { $$ = NULL; }
                    ;
selection_stmt      : IF LPAREN expression RPAREN statement %prec IFX
                    {
                        $$ = newStmtNode(SelectK);
                        $$->attr.name = "If";
                        $$->child[0] = $3;
                        $$->child[1] = $5;
                    }
                    | IF LPAREN expression RPAREN statement ELSE statement
                    {
                        $$ = newStmtNode(SelectK);
                        $$->attr.name = "If-Else";
                        $$->child[0] = $3;
                        $$->child[1] = $5;
                        $$->child[2] = $7;
                    }
                    ;
iteration_stmt      : WHILE LPAREN expression RPAREN statement
                    {
                        $$ = newStmtNode(WhileK);
                        $$->child[0] = $3;
                        $$->child[1] = $5;
                    }
                    ;
return_stmt         : RETURN SEMI
                    { $$ = newStmtNode(RetK); }
                    | RETURN expression SEMI
                    {
                        $$ = newStmtNode(RetK);
                        $$->child[0] = $2;
                        $$->type = $2->type;
                        $$->attr.name = $2->attr.name;
                    }
                    ;
expression          : var ASSIGN expression 
                    {
                        $$ = newStmtNode(AssignK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                    }
                    | simple_expression { $$ = $1; }
                    ;
var                 : identifier
                    {
                        $$ = newStmtNode(VarK);
                        $$->attr.name = $1->attr.name;
                    }
                    | identifier LBRACE expression RBRACE
                    {
                        $$ = newStmtNode(VarK);
                        $$->attr.name = $1->attr.name;
                        $$->child[0] = $3;
                    }
                    ;
simple_expression   : additive_expression LE additive_expression
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = LE;
                    }
                    | additive_expression LT additive_expression
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = LT;
                    }
                    | additive_expression GT additive_expression
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = GT;
                    }
                    | additive_expression GE additive_expression
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = GE;
                    }
                    | additive_expression EQ additive_expression
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = EQ;
                    }
                    | additive_expression NE additive_expression
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = NE;
                    }
                    | additive_expression { $$ = $1; }
                    ;
additive_expression : additive_expression PLUS term
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = PLUS;
                    }
                    | additive_expression MINUS term
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = MINUS;
                    }
                    | term { $$ = $1; }
                    ;
term                : term TIMES factor
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = TIMES;
                    }
                    | term OVER factor
                    {
                        $$ = newExpNode(OpK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                        $$->attr.op = OVER;
                    }
                    | factor { $$ = $1; }
factor              : LPAREN expression RPAREN { $$ = $2; }
                    | var { $$ = $1; }
                    | call { $$ = $1; }
                    | number { $$ = $1; }
                    ;
call                : identifier LPAREN args RPAREN
                    {
                        $$ = newExpNode(CallK);
                        $$->child[0] = $3;
                        $$->attr.name = $1->attr.name;
                    }
                    ;
args                : arg_list { $$ = $1; }
                    | empty
                    ;
arg_list            : arg_list COMMA expression
                    {
                        if ($1 != NULL) {
                            YYSTYPE t = $1;
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = $3;
                            $$ = $1;
                        } else {
                            $$ = $3;
                        }
                    }
                    | expression { $$ = $1; }
                    ;
identifier          : ID
                    {
                        $$ = newExpNode(IdK);
                        $$->lineno = lineno;
                        $$->attr.name = copyString(tokenString);
                    }
                    ;
number              : NUM
                    {
                        $$ = newExpNode(ConstK);
                        $$->lineno = lineno;
                        $$->attr.val = atoi(tokenString);
                    }
                    ;
empty               : {$$ = NULL;}
                    ;

%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

