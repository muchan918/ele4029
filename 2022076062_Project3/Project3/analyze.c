/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;
static ScopeList globalScope = NULL;
static ScopeList currentScope = NULL;
static BucketList funcBucket = NULL;
static FuncInfo info = NULL;
int func_flag = 0;
/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL) {
    preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t)
{ t->scope = currentScope;
  switch (t->nodekind)
  { case StmtK:
      switch (t->kind.stmt)
      { case CompK:
            if(func_flag){
                func_flag = 0;
            } else {
                currentScope = insertScope("block", currentScope);
            }
            break;
        case VarK:
            if(st_lookup(currentScope, t->attr.name) == -1){
                /* not yet in table, so treat as new definition */
                char * parentType = return_bucket_type_recursive(currentScope->parent, t->attr.name);
                if(parentType != NULL){
                    t->typestring = parentType;
                    currentScope = st_insert(currentScope, t->attr.name, t->lineno, location++, t->typestring);
                } else {
                    t->typestring = "none";
                    currentScope = st_insert(currentScope, t->attr.name, t->lineno, location++, "undeclared");
                }
            } else {
                char * str = return_bucket_type(currentScope, t->attr.name);
                t->typestring = str;
                currentScope = st_insert(currentScope, t->attr.name, t->lineno, 0, t->typestring);
            }
            break;
        case AssignK:
          break;
        case RetK:
            break;
        case WhileK:
            break;
        case SelectK:
            break;
        default:
            break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case OpK:
            break;
        case ConstK:
            t->typestring = "int";
            break;
        case IdK:
            break;
        case FuncDK:
            if (st_lookup(currentScope, t->attr.name) == -1) {
                func_flag = 1;
                currentScope = st_insert(currentScope, t->attr.name, t->lineno, location++, t->typestring);
                funcBucket = st_lookup_bucket(globalScope, t->attr.name);
                funcBucket->func = (FuncInfo)malloc(sizeof(struct FuncInfoRec));
                funcBucket->type = t->typestring;
                funcBucket->func->param_num = 0;
                for(int i=0; i<SIZE; i++)
                    funcBucket->func->params[i] = NULL;
                currentScope = insertScope(t->attr.name, currentScope);
            }
            break;
        case TypeK:
            break;
        case VarDK:  
            if (st_lookup(currentScope, t->attr.name) == -1){
            /* not yet in table, so treat as new definition */
                currentScope = st_insert(currentScope, t->attr.name,t->lineno,location++,t->typestring);
            }
            else {
                currentScope = st_insert(currentScope, t->attr.name,t->lineno,0,t->typestring);
            }
            break;
        case ParamK:
            char * funcName = currentScope->name; // 현재 scope의 부모가 함수 scope
            funcBucket = st_lookup_bucket(globalScope, funcName);
            info = funcBucket->func;
            if(info->param_num < SIZE){
                Param param = (Param)malloc(sizeof(struct ParamRec));
                param->name = t->attr.name;
                param->typestring = t->typestring;
                info->params[info->param_num] = param;
                info->param_num++;
            }

            if (st_lookup(currentScope, t->attr.name) == -1){
                /* not yet in table, so treat as new definition */
                currentScope = st_insert(currentScope, t->attr.name,t->lineno,location++,t->typestring);
            } else
            /* already in table, so ignore location, 
                add line number of use only */ 
                currentScope = st_insert(currentScope, t->attr.name,t->lineno,0,t->typestring);
            break;
        case CallK:
            if(st_lookup(globalScope, t->attr.name) == -1){
                /* not yet in table, so treat as new definition */
                t->typestring = "none";
                currentScope = st_insert(globalScope, t->attr.name, t->lineno, location++, "undeclared");
            } else {
                char * str = return_bucket_type(globalScope, t->attr.name);
                t->typestring = str;
                if(st_lookup(currentScope, t->attr.name) == -1){
                    currentScope = st_insert(currentScope, t->attr.name,t->lineno,location++,t->typestring);
                } else {
                    currentScope = st_insert(currentScope, t->attr.name, t->lineno, 0, t->typestring);
                }               
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
  }
}
static void leaveScope(TreeNode *t) {
    if (t->nodekind == StmtK && t->kind.stmt == CompK) {
        if (currentScope->parent != NULL) {
            currentScope = currentScope->parent;
        }
    }
    if (t->nodekind == ExpK && t->kind.exp == FuncDK) {
        if (currentScope->parent != NULL) {
            currentScope = currentScope->parent;
        }
    }
}


/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  globalScope = insertScope("global",NULL);
  globalScope = st_insert(globalScope, "input", 0, location++, "int");
  globalScope = st_insert(globalScope, "output", 0, location++, "void");
  currentScope = globalScope;
  currentScope = insertScope("input",globalScope);
  currentScope = exitScope(currentScope);
  currentScope = insertScope("output",globalScope);
  currentScope = st_insert(currentScope, "value", 0, location++, "int");
  currentScope = exitScope(currentScope);
  traverse(syntaxTree,insertNode,leaveScope);
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(globalScope, listing);
  }
}

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ switch (t->nodekind)
  { case ExpK:
      switch (t->kind.exp)
      { case OpK:
            if(strcmp(t->child[0]->typestring,"int")!=0 || strcmp(t->child[1]->typestring,"int")!=0){
                fprintf(listing, "Error: invalid operation at line %d\n", t->child[0]->lineno);
                t->typestring = "undeclared";
            } else t->typestring = "int";
            break;
        case ConstK:
            break;
        case IdK:
            break;
        case FuncDK:
            break;
        case TypeK:
            break;
        case VarDK:  
            if(strcmp(t->typestring, "void") == 0)
                fprintf(listing, "Error: The void-type variable is declared at line %d (name : \"%s\")\n", t->lineno, t->attr.name);
            if(st_lookup(t->scope, t->attr.name) != -1){
                BucketList bucket = st_lookup_bucket(t->scope, t->attr.name);
                LineList bucketLine = bucket->lines;
                if(t->lineno != bucketLine->lineno){
                    fprintf(listing, "Error: Symbol \"%s\" is redefined at line %d (already defined at line ", t->attr.name, t->lineno);
                    // Program to sequentially print all the line numbers
                    while(t->lineno > bucketLine->lineno){
                        printf("%d ",bucketLine->lineno);
                        bucketLine = bucketLine->next;
                    }
                    fprintf(listing, ")\n");
                }
            }
            break;
        case ParamK:
            break;
        case CallK:
            funcBucket = st_lookup_bucket(globalScope, t->attr.name);
            if(strcmp(t->typestring,"none") == 0) {
                fprintf(listing, "Error: undeclared function \"%s\" is called at line %d\n", t->attr.name, t->lineno);
                fprintf(listing, "Error: Invalid function call at line %d (name : \"%s\")\n", t->lineno, t->attr.name);
            }
            else if (strcmp(t->typestring,"undeclared") == 0){
                fprintf(listing, "Error: Invalid function call at line %d (name : \"%s\")\n", t->lineno, t->attr.name);
            }
            else if(strcmp(funcBucket->name, "output")==0){
                if(t->child[0]){
                    if((strcmp(t->child[0]->typestring,"int") != 0) || t->child[0]->sibling){
                        fprintf(listing, "Error: Invalid function call at line %d (name : \"%s\")\n", t->lineno, t->scope->name);
                    }
                }
                else{
                    fprintf(listing, "Error: Invalid function call at line %d (name : \"%s\")\n", t->lineno, t->scope->name);
                }
            }
            else{
                TreeNode * tmp;
                int flag = 0;
                int num = 0;
                if(t->child[0]){
                    tmp = t->child[0];
                    while(tmp){
                        if(num == funcBucket->func->param_num) {
                            flag = 1;
                            break;
                        }
                        if(strcmp(tmp->typestring,funcBucket->func->params[num]->typestring) != 0){
                            flag = 1;
                            break;
                        }
                        tmp = tmp->sibling;
                        num++;
                    }
                    if(flag){
                        fprintf(listing, "Error: Invalid function call at line %d (name : \"%s\")\n", t->lineno, t->attr.name);
                    }
                }
            }
            break;
        default:
            break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { case CompK:
            break;
        case VarK:
            if(strcmp(t->typestring,"none")==0){
                fprintf(listing, "Error: undeclared variable \"%s\" is used at line %d\n", t->attr.name, t->lineno);
            }
            else if((strcmp(t->typestring, "int[]") == 0) && t->child[0]){
                if(strcmp(t->child[0]->typestring,"int") != 0){
                    fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indicies should be integer\n",
                    t->lineno, t->attr.name);
                }
                t->typestring = "int";
            }
            else if(strcmp(t->typestring, "int") == 0) {
                if(t->child[0])
                    fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indexing can only allowed for int[] variables\n",
                    t->lineno, t->attr.name);
            }
            break;
        case AssignK:
            if(strcmp(t->child[0]->typestring, t->child[1]->typestring) != 0){
                fprintf(listing, "Error: invalid assignment at line %d\n", t->lineno);
            } else t->typestring = t->child[0]->typestring;
            break;
        case RetK:
            if(t->child[0]){
                char * str = return_bucket_type(globalScope, t->scope->name);
                if(t->child[0]->kind.exp == ConstK) str = "int";
                if (strcmp(str, t->child[0]->typestring) != 0)
                    fprintf(listing, "Error: Invalid return at line %d\n", t->lineno);
            }
            break;
        case WhileK:
            if(strcmp(t->child[0]->typestring,"int") != 0)
                fprintf(listing, "Error: invalid condition at line %d\n", t->child[1]->lineno);
            break;
        case SelectK:
            if(strcmp(t->child[0]->typestring,"int") != 0)
                fprintf(listing, "Error: invalid condition at line %d\n", t->child[1]->lineno);
            break;
        default:
            break;
      }
      break;
    default:
      break;
  }
}
/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode *syntaxTree) {
    // Traverse the tree with scope management
    traverse(syntaxTree, nullProc, checkNode);
}

