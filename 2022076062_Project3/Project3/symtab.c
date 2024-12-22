/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the hash table */
static BucketList hashTable[SIZE];

/* scope 관련 함수들 */
ScopeList insertScope(char *name, ScopeList parent) {
    ScopeList scope = (ScopeList)malloc(sizeof(struct ScopeListRec));
    scope->name = strdup(name);
    scope->parent = parent;
    scope->children = NULL;
    scope->sibling = NULL;
    for (int i = 0; i < SIZE; i++) {
        scope->buckets[i] = NULL;
    }
    if (parent != NULL) {
        if (parent->children == NULL) {
            parent->children = scope;
        } else {
            ScopeList temp = parent->children;
            while (temp->sibling != NULL) {
                temp = temp->sibling;
            }
            temp->sibling = scope;
        }
    }
    return scope;
}

ScopeList exitScope(ScopeList scope){
    return scope->parent;
}

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
ScopeList st_insert( ScopeList scope, char * name, int lineno, int loc, char * type)
{ int h = hash(name);
  BucketList l =  scope->buckets[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    if (type == NULL) {
        SymbolInfo parentInfo = st_lookup_recursive(scope->parent, name);
        l->type = parentInfo.type ? strdup(parentInfo.type) : NULL;
    } else {
        l->type = strdup(type);
    }
    l->lines->next = NULL;
    l->next = scope->buckets[h];
    scope->buckets[h] = l; }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
    l->scope = scope;
  }
  return scope;
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
// 현재 scope에 있는 bucket에서 lookup하기
// 없으면 이후 다른곳에서 exit 호출 후 다시 lookup
int st_lookup ( ScopeList scope, char * name )
{ int h = hash(name);
  BucketList l =  scope->buckets[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->memloc;
}

BucketList st_lookup_bucket(ScopeList scope, char * name) {
    for (int i = 0; i < SIZE; i++) {
        BucketList l = scope->buckets[i];
        while (l != NULL) {
            if (strcmp(l->name, name) == 0)
                return l;
            l=l->next;
        }
    }
}

SymbolInfo st_lookup_recursive(ScopeList scope, char *name) {
    int h = hash(name);
    BucketList l = scope->buckets[h];
    while (l != NULL) {
        if (strcmp(name, l->name) == 0) {
            return (SymbolInfo){l->memloc, l->type};
        }
        l = l->next;
    }
    return st_lookup_recursive(scope->parent, name);
}

char * return_bucket_type(ScopeList scope, char *name) {
    for (int i = 0; i < SIZE; i++) {
        BucketList l = scope->buckets[i];
        while (l != NULL) {
            if (strcmp(l->name, name) == 0)
                return l->type;
            l=l->next;
        }
    }
}

char * return_bucket_name(ScopeList scope, char *name) {
    for (int i = 0; i < SIZE; i++) {
        BucketList l = scope->buckets[i];
        while (l != NULL) {
            if (strcmp(l->name, name) == 0)
                return l->name;
            l=l->next;
        }
    }
}

char * return_bucket_type_recursive(ScopeList scope, char *name) {
    if (scope == NULL) {
        return NULL;
    }
    for (int i = 0; i < SIZE; i++) {
        BucketList l = scope->buckets[i];
        while (l != NULL) {
            if (strcmp(l->name, name) == 0) {
                return l->type;
            }
            l = l->next;
        }
    }
    return return_bucket_type_recursive(scope->parent, name);
}

void printScope(ScopeList scope, FILE *listing) {
    if (!scope) return;

    // 현재 스코프 이름 출력
    fprintf(listing, "\nScope: %s\n", scope->name);
    fprintf(listing, "Name       Type       Location   Line Numbers\n");
    fprintf(listing, "----       ----       --------   ------------\n");

    // 현재 스코프의 심볼 테이블 출력
    for (int i = 0; i < SIZE; i++) {
        BucketList l = scope->buckets[i];
        while (l != NULL) {
            LineList t = l->lines;
            fprintf(listing, "%-10s %-10s %-10d ", l->name, l->type, l->memloc);
            while (t != NULL) {
                fprintf(listing, "%d ", t->lineno);
                t = t->next;
            }
            fprintf(listing, "\n");
            l = l->next;
        }
    }
    // 자식 스코프 출력 (재귀적으로 호출)
    if (scope->children) {
        printScope(scope->children, listing);
    }
    // 형제 스코프 출력
    if (scope->sibling) {
        printScope(scope->sibling, listing);
    }
}
void printSymTab(ScopeList globalScope, FILE *listing) {
    if (!globalScope) {
        fprintf(stderr, "Error: NULL globalScope passed to printSymTab.\n");
        return;
    }
    fprintf(listing, "Printing Symbol Table:\n");
    printScope(globalScope, listing);
}

