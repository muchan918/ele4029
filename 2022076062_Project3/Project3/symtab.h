/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

/* SIZE is the size of the hash table */
#define SIZE 211

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct ParamRec
   { char * typestring; 
     char * name;
   } * Param;

typedef struct FuncInfoRec
   { char * typestring;
     int param_num;
     Param params[SIZE];
   } * FuncInfo;

typedef struct BucketListRec
   { char * name;
     LineList lines;
     int memloc ; /* memory location for variable */
     char * type;
     struct FuncInfoRec * func;
     struct BucketListRec * next;
     struct ScopeListRec * scope;
   } * BucketList;
   
typedef struct ScopeListRec
   { char * name;
     BucketList buckets[SIZE];
     struct ScopeListRec * parent; 
     struct ScopeListRec * children;
     struct ScopeListRec * sibling;
   } * ScopeList;

typedef struct {
    int memloc;
    char * type;
} SymbolInfo;

/* scope 관련 함수들 */
ScopeList insertScope(char * name, ScopeList parent);

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
ScopeList st_insert( ScopeList scope, char * name, int lineno, int loc, char * type);
ScopeList exitScope(ScopeList scope);
SymbolInfo st_lookup_recursive(ScopeList scope, char *name);
char * return_bucket_type(ScopeList scope, char *name);
char * return_bucket_name(ScopeList scope, char *name);
char * return_bucket_type_recursive(ScopeList scope, char *name);
/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( ScopeList scope, char * name );
BucketList st_lookup_bucket(ScopeList scope, char * name);

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab( ScopeList scope, FILE * listing);

#endif
