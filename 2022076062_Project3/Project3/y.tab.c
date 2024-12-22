/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "cminus.y"

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


#line 87 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    WHILE = 259,                   /* WHILE  */
    RETURN = 260,                  /* RETURN  */
    INT = 261,                     /* INT  */
    VOID = 262,                    /* VOID  */
    ELSE = 263,                    /* ELSE  */
    ID = 264,                      /* ID  */
    NUM = 265,                     /* NUM  */
    ASSIGN = 266,                  /* ASSIGN  */
    EQ = 267,                      /* EQ  */
    NE = 268,                      /* NE  */
    LT = 269,                      /* LT  */
    LE = 270,                      /* LE  */
    GT = 271,                      /* GT  */
    GE = 272,                      /* GE  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    LCURLY = 277,                  /* LCURLY  */
    RCURLY = 278,                  /* RCURLY  */
    SEMI = 279,                    /* SEMI  */
    COMMA = 280,                   /* COMMA  */
    ERROR = 281,                   /* ERROR  */
    IFX = 282,                     /* IFX  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    TIMES = 285,                   /* TIMES  */
    OVER = 286                     /* OVER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define WHILE 259
#define RETURN 260
#define INT 261
#define VOID 262
#define ELSE 263
#define ID 264
#define NUM 265
#define ASSIGN 266
#define EQ 267
#define NE 268
#define LT 269
#define LE 270
#define GT 271
#define GE 272
#define LPAREN 273
#define RPAREN 274
#define LBRACE 275
#define RBRACE 276
#define LCURLY 277
#define RCURLY 278
#define SEMI 279
#define COMMA 280
#define ERROR 281
#define IFX 282
#define PLUS 283
#define MINUS 284
#define TIMES 285
#define OVER 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_WHILE = 4,                      /* WHILE  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_LCURLY = 22,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 23,                    /* RCURLY  */
  YYSYMBOL_SEMI = 24,                      /* SEMI  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_ERROR = 26,                     /* ERROR  */
  YYSYMBOL_IFX = 27,                       /* IFX  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_MINUS = 29,                     /* MINUS  */
  YYSYMBOL_TIMES = 30,                     /* TIMES  */
  YYSYMBOL_OVER = 31,                      /* OVER  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_declaration_list = 34,          /* declaration_list  */
  YYSYMBOL_declaration = 35,               /* declaration  */
  YYSYMBOL_var_declaration = 36,           /* var_declaration  */
  YYSYMBOL_type_specifier = 37,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 38,           /* fun_declaration  */
  YYSYMBOL_params = 39,                    /* params  */
  YYSYMBOL_param_list = 40,                /* param_list  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_compound_stmt = 42,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 43,        /* local_declarations  */
  YYSYMBOL_statement_list = 44,            /* statement_list  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_expression_stmt = 46,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 47,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 48,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 49,               /* return_stmt  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simple_expression = 52,         /* simple_expression  */
  YYSYMBOL_additive_expression = 53,       /* additive_expression  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_factor = 55,                    /* factor  */
  YYSYMBOL_call = 56,                      /* call  */
  YYSYMBOL_args = 57,                      /* args  */
  YYSYMBOL_arg_list = 58,                  /* arg_list  */
  YYSYMBOL_identifier = 59,                /* identifier  */
  YYSYMBOL_number = 60,                    /* number  */
  YYSYMBOL_empty = 61                      /* empty  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    38,    51,    53,    54,    56,    64,    81,
      88,    96,   107,   108,   116,   129,   131,   139,   155,   162,
     175,   177,   190,   192,   194,   196,   198,   200,   203,   204,
     206,   213,   222,   229,   231,   239,   245,   247,   252,   259,
     266,   273,   280,   287,   294,   301,   303,   310,   317,   319,
     326,   333,   334,   335,   336,   337,   339,   346,   347,   349,
     362,   364,   371,   378
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "WHILE",
  "RETURN", "INT", "VOID", "ELSE", "ID", "NUM", "ASSIGN", "EQ", "NE", "LT",
  "LE", "GT", "GE", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LCURLY",
  "RCURLY", "SEMI", "COMMA", "ERROR", "IFX", "PLUS", "MINUS", "TIMES",
  "OVER", "$accept", "program", "declaration_list", "declaration",
  "var_declaration", "type_specifier", "fun_declaration", "params",
  "param_list", "param", "compound_stmt", "local_declarations",
  "statement_list", "statement", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "additive_expression", "term", "factor", "call",
  "args", "arg_list", "identifier", "number", "empty", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,   -72,   -72,     6,    15,   -72,   -72,     3,   -72,   -72,
     -72,   -72,   -13,    57,    39,   -72,    42,     3,    66,    51,
     -72,   -72,    69,    71,    72,    15,    73,    74,   -72,   -72,
     -72,   -72,   -72,    15,   -72,   -72,     3,     5,   -72,    36,
      78,    80,    41,     8,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,    75,    89,   -72,    29,    53,   -72,   -72,    35,
     -72,     8,     8,   -72,    77,    83,   -72,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
      84,    85,   -72,   -72,   -72,   -72,    58,    58,    58,    58,
      58,    58,    53,    53,   -72,   -72,   -72,    86,    81,   -72,
      87,    30,    30,   -72,     8,   -72,    99,   -72,   -72,    30,
     -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    61,     0,     0,     0,     7,    10,     0,     0,    12,
      15,    62,     0,    16,     0,     0,     0,     0,    63,    11,
      14,     8,    17,    63,    20,    19,     0,     0,    22,     0,
       0,     0,     0,     0,    18,    29,    24,    21,    23,    25,
      26,    27,     0,    53,    36,    45,    48,    51,    54,    37,
      55,     0,     0,    33,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,    34,    52,    35,    53,    43,    44,    40,    39,
      41,    42,    46,    47,    49,    50,    60,     0,    57,    58,
       0,     0,     0,    56,     0,    38,    30,    32,    59,     0,
      31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   105,    79,    -9,   -72,   -72,   -72,    88,
      90,   -72,   -72,   -71,   -72,   -72,   -72,   -72,   -42,    -2,
     -72,     9,    14,    16,   -72,   -72,   -72,    -4,    96,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      46,    33,    37,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    97,    98,    59,    60,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    65,    38,    12,    17,    13,     9,    14,    40,    41,
      42,    15,    11,    23,    11,    21,    17,    11,    21,    80,
      81,     1,     2,    43,    36,    84,    43,    28,    44,    45,
     106,   107,    39,    40,    41,    42,    96,   100,   110,    11,
      21,    68,    69,    70,    71,    72,    73,    99,    43,    21,
      11,    21,    28,    78,    45,    79,    14,    74,    75,    43,
      15,   -13,   108,     1,    16,    63,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    25,    86,    87,    88,
      89,    90,    91,    76,    77,    24,    74,    75,    92,    93,
      26,    27,    94,    95,    28,    32,    61,    31,    62,    66,
      67,    82,    83,   101,   102,   103,   104,   109,   105,    10,
      22,     0,    35,    30,    29
};

static const yytype_int8 yycheck[] =
{
      42,    43,    33,     7,    13,    18,     0,    20,     3,     4,
       5,    24,     9,    17,     9,    10,    25,     9,    10,    61,
      62,     6,     7,    18,    33,    67,    18,    22,    23,    24,
     101,   102,    36,     3,     4,     5,    78,    79,   109,     9,
      10,    12,    13,    14,    15,    16,    17,    78,    18,    10,
       9,    10,    22,    18,    24,    20,    20,    28,    29,    18,
      24,    19,   104,     6,     7,    24,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    25,    68,    69,    70,
      71,    72,    73,    30,    31,    19,    28,    29,    74,    75,
      21,    20,    76,    77,    22,    21,    18,    24,    18,    24,
      11,    24,    19,    19,    19,    19,    25,     8,    21,     4,
      14,    -1,    33,    25,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    33,    34,    35,    36,    37,    38,     0,
      35,     9,    59,    18,    20,    24,     7,    37,    39,    40,
      41,    10,    60,    59,    19,    25,    21,    20,    22,    42,
      41,    24,    21,    43,    61,    36,    37,    44,    61,    59,
       3,     4,     5,    18,    23,    24,    42,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    59,
      60,    18,    18,    24,    50,    50,    24,    11,    12,    13,
      14,    15,    16,    17,    28,    29,    30,    31,    18,    20,
      50,    50,    24,    19,    50,    51,    53,    53,    53,    53,
      53,    53,    54,    54,    55,    55,    50,    57,    58,    61,
      50,    19,    19,    19,    25,    21,    45,    45,    50,     8,
      45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    43,
      43,    44,    44,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    56,    57,    57,    58,
      58,    59,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     4,     1,     1,     3,
       1,     1,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 36 "cminus.y"
                         { savedTree = yyvsp[0];}
#line 1312 "y.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 39 "cminus.y"
                        { 
                            YYSTYPE t = yyvsp[-1];
                            if (t != NULL) {
                                while (t->sibling != NULL) {
                                    t = t->sibling;
                                }
                                t->sibling = yyvsp[0];
                                yyval = yyvsp[-1];
                            } else {
                                yyval = yyvsp[0];
                            }
                        }
#line 1329 "y.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 51 "cminus.y"
                                  { yyval = yyvsp[0]; }
#line 1335 "y.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 53 "cminus.y"
                                      { yyval = yyvsp[0]; }
#line 1341 "y.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 54 "cminus.y"
                                      { yyval = yyvsp[0]; }
#line 1347 "y.tab.c"
    break;

  case 7: /* var_declaration: type_specifier identifier SEMI  */
#line 57 "cminus.y"
                     {
                        yyval = newExpNode(VarDK);
                        yyval->type = yyvsp[-2]->type;
                        yyval->typestring = yyvsp[-2]->typestring;
                        yyval->attr.name = yyvsp[-1]->attr.name;
                        yyval->lineno = yyvsp[-1]->lineno;
                     }
#line 1359 "y.tab.c"
    break;

  case 8: /* var_declaration: type_specifier identifier LBRACE number RBRACE SEMI  */
#line 65 "cminus.y"
                     {
                        yyval = newExpNode(VarDK);
                        if (yyvsp[-5]->type == Integer) {
                            yyval->type = IntegerArr;
                            yyval->typestring = "int[]";
                        }
                        else if (yyvsp[-5]->type == Void) {
                            yyval->type = VoidArr;
                            yyval->typestring = "void[]";
                        }
                        else yyval->type = None;
                        yyval->attr.name = yyvsp[-4]->attr.name;
                        yyval->child[0] = yyvsp[-2];
                        yyval->lineno = yyvsp[-4]->lineno;
                     }
#line 1379 "y.tab.c"
    break;

  case 9: /* type_specifier: INT  */
#line 82 "cminus.y"
                     { 
                        yyval = newExpNode(TypeK);
                        yyval->lineno = lineno;
                        yyval->type = Integer;
                        yyval->typestring = "int";
                     }
#line 1390 "y.tab.c"
    break;

  case 10: /* type_specifier: VOID  */
#line 89 "cminus.y"
                     {
                        yyval = newExpNode(TypeK);
                        yyval->lineno = lineno;
                        yyval->type = Void;
                        yyval->typestring = "void";
                     }
#line 1401 "y.tab.c"
    break;

  case 11: /* fun_declaration: type_specifier identifier LPAREN params RPAREN compound_stmt  */
#line 97 "cminus.y"
                    {
                        yyval = newExpNode(FuncDK);
                        yyval->type = yyvsp[-5]->type;
                        yyval->typestring = yyvsp[-5]->typestring;
                        yyval->attr.name = yyvsp[-4]->attr.name;
                        yyval->lineno = yyvsp[-4]->lineno;
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                    }
#line 1415 "y.tab.c"
    break;

  case 12: /* params: param_list  */
#line 107 "cminus.y"
                                 { yyval = yyvsp[0]; }
#line 1421 "y.tab.c"
    break;

  case 13: /* params: VOID  */
#line 109 "cminus.y"
                     {
                        yyval = newExpNode(TypeK);
                        yyval->lineno = lineno;
                        yyval->type = Void;
                        yyval->typestring = "void";
                     }
#line 1432 "y.tab.c"
    break;

  case 14: /* param_list: param_list COMMA param  */
#line 117 "cminus.y"
                    { 
                        YYSTYPE t = yyvsp[-2];
                        if (t != NULL) {
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-2];
                        } else {
                            yyval = yyvsp[0];
                        }
                    }
#line 1449 "y.tab.c"
    break;

  case 15: /* param_list: param  */
#line 129 "cminus.y"
                            { yyval = yyvsp[0]; }
#line 1455 "y.tab.c"
    break;

  case 16: /* param: type_specifier identifier  */
#line 132 "cminus.y"
                    {
                        yyval = newExpNode(ParamK);
                        yyval->type = yyvsp[-1]->type;
                        yyval->typestring = yyvsp[-1]->typestring;
                        yyval->attr.name = yyvsp[0]->attr.name;
                        yyval->lineno = yyvsp[0]->lineno;
                    }
#line 1467 "y.tab.c"
    break;

  case 17: /* param: type_specifier identifier LBRACE RBRACE  */
#line 140 "cminus.y"
                    {
                        yyval = newExpNode(ParamK);
                        if (yyvsp[-3]->type == Integer) {
                            yyval->type = IntegerArr;
                            yyval->typestring = "int[]";
                        }
                        else if (yyvsp[-3]->type == Void) {
                            yyval->type = VoidArr;
                            yyval->typestring = "void[]";
                        }
                        else yyval->type = None;
                        yyval->attr.name = yyvsp[-2]->attr.name;
                        yyval->lineno = yyvsp[-2]->lineno;
                    }
#line 1486 "y.tab.c"
    break;

  case 18: /* compound_stmt: LCURLY local_declarations statement_list RCURLY  */
#line 156 "cminus.y"
                    {
                        yyval = newStmtNode(CompK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[-1];
                    }
#line 1496 "y.tab.c"
    break;

  case 19: /* local_declarations: local_declarations var_declaration  */
#line 163 "cminus.y"
                    {
                        if (yyvsp[-1] != NULL) {
                            YYSTYPE t = yyvsp[-1];
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-1];
                        } else {
                            yyval = yyvsp[0];
                        }
                    }
#line 1513 "y.tab.c"
    break;

  case 21: /* statement_list: statement_list statement  */
#line 178 "cminus.y"
                    {
                        if (yyvsp[-1] != NULL) {
                            YYSTYPE t = yyvsp[-1];
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-1];
                        } else {
                            yyval = yyvsp[0];
                        }
                    }
#line 1530 "y.tab.c"
    break;

  case 23: /* statement: expression_stmt  */
#line 193 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1536 "y.tab.c"
    break;

  case 24: /* statement: compound_stmt  */
#line 195 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1542 "y.tab.c"
    break;

  case 25: /* statement: selection_stmt  */
#line 197 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1548 "y.tab.c"
    break;

  case 26: /* statement: iteration_stmt  */
#line 199 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1554 "y.tab.c"
    break;

  case 27: /* statement: return_stmt  */
#line 201 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1560 "y.tab.c"
    break;

  case 28: /* expression_stmt: expression SEMI  */
#line 203 "cminus.y"
                                      { yyval = yyvsp[-1]; }
#line 1566 "y.tab.c"
    break;

  case 29: /* expression_stmt: SEMI  */
#line 204 "cminus.y"
                           { yyval = NULL; }
#line 1572 "y.tab.c"
    break;

  case 30: /* selection_stmt: IF LPAREN expression RPAREN statement  */
#line 207 "cminus.y"
                    {
                        yyval = newStmtNode(SelectK);
                        yyval->attr.name = "If";
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                    }
#line 1583 "y.tab.c"
    break;

  case 31: /* selection_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 214 "cminus.y"
                    {
                        yyval = newStmtNode(SelectK);
                        yyval->attr.name = "If-Else";
                        yyval->child[0] = yyvsp[-4];
                        yyval->child[1] = yyvsp[-2];
                        yyval->child[2] = yyvsp[0];
                    }
#line 1595 "y.tab.c"
    break;

  case 32: /* iteration_stmt: WHILE LPAREN expression RPAREN statement  */
#line 223 "cminus.y"
                    {
                        yyval = newStmtNode(WhileK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                    }
#line 1605 "y.tab.c"
    break;

  case 33: /* return_stmt: RETURN SEMI  */
#line 230 "cminus.y"
                    { yyval = newStmtNode(RetK); }
#line 1611 "y.tab.c"
    break;

  case 34: /* return_stmt: RETURN expression SEMI  */
#line 232 "cminus.y"
                    {
                        yyval = newStmtNode(RetK);
                        yyval->child[0] = yyvsp[-1];
                        yyval->type = yyvsp[-1]->type;
                        yyval->attr.name = yyvsp[-1]->attr.name;
                    }
#line 1622 "y.tab.c"
    break;

  case 35: /* expression: var ASSIGN expression  */
#line 240 "cminus.y"
                    {
                        yyval = newStmtNode(AssignK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                    }
#line 1632 "y.tab.c"
    break;

  case 36: /* expression: simple_expression  */
#line 245 "cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1638 "y.tab.c"
    break;

  case 37: /* var: identifier  */
#line 248 "cminus.y"
                    {
                        yyval = newStmtNode(VarK);
                        yyval->attr.name = yyvsp[0]->attr.name;
                    }
#line 1647 "y.tab.c"
    break;

  case 38: /* var: identifier LBRACE expression RBRACE  */
#line 253 "cminus.y"
                    {
                        yyval = newStmtNode(VarK);
                        yyval->attr.name = yyvsp[-3]->attr.name;
                        yyval->child[0] = yyvsp[-1];
                    }
#line 1657 "y.tab.c"
    break;

  case 39: /* simple_expression: additive_expression LE additive_expression  */
#line 260 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = LE;
                    }
#line 1668 "y.tab.c"
    break;

  case 40: /* simple_expression: additive_expression LT additive_expression  */
#line 267 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = LT;
                    }
#line 1679 "y.tab.c"
    break;

  case 41: /* simple_expression: additive_expression GT additive_expression  */
#line 274 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = GT;
                    }
#line 1690 "y.tab.c"
    break;

  case 42: /* simple_expression: additive_expression GE additive_expression  */
#line 281 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = GE;
                    }
#line 1701 "y.tab.c"
    break;

  case 43: /* simple_expression: additive_expression EQ additive_expression  */
#line 288 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = EQ;
                    }
#line 1712 "y.tab.c"
    break;

  case 44: /* simple_expression: additive_expression NE additive_expression  */
#line 295 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = NE;
                    }
#line 1723 "y.tab.c"
    break;

  case 45: /* simple_expression: additive_expression  */
#line 301 "cminus.y"
                                          { yyval = yyvsp[0]; }
#line 1729 "y.tab.c"
    break;

  case 46: /* additive_expression: additive_expression PLUS term  */
#line 304 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = PLUS;
                    }
#line 1740 "y.tab.c"
    break;

  case 47: /* additive_expression: additive_expression MINUS term  */
#line 311 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = MINUS;
                    }
#line 1751 "y.tab.c"
    break;

  case 48: /* additive_expression: term  */
#line 317 "cminus.y"
                           { yyval = yyvsp[0]; }
#line 1757 "y.tab.c"
    break;

  case 49: /* term: term TIMES factor  */
#line 320 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = TIMES;
                    }
#line 1768 "y.tab.c"
    break;

  case 50: /* term: term OVER factor  */
#line 327 "cminus.y"
                    {
                        yyval = newExpNode(OpK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[0];
                        yyval->attr.op = OVER;
                    }
#line 1779 "y.tab.c"
    break;

  case 51: /* term: factor  */
#line 333 "cminus.y"
                             { yyval = yyvsp[0]; }
#line 1785 "y.tab.c"
    break;

  case 52: /* factor: LPAREN expression RPAREN  */
#line 334 "cminus.y"
                                               { yyval = yyvsp[-1]; }
#line 1791 "y.tab.c"
    break;

  case 53: /* factor: var  */
#line 335 "cminus.y"
                          { yyval = yyvsp[0]; }
#line 1797 "y.tab.c"
    break;

  case 54: /* factor: call  */
#line 336 "cminus.y"
                           { yyval = yyvsp[0]; }
#line 1803 "y.tab.c"
    break;

  case 55: /* factor: number  */
#line 337 "cminus.y"
                             { yyval = yyvsp[0]; }
#line 1809 "y.tab.c"
    break;

  case 56: /* call: identifier LPAREN args RPAREN  */
#line 340 "cminus.y"
                    {
                        yyval = newExpNode(CallK);
                        yyval->child[0] = yyvsp[-1];
                        yyval->attr.name = yyvsp[-3]->attr.name;
                    }
#line 1819 "y.tab.c"
    break;

  case 57: /* args: arg_list  */
#line 346 "cminus.y"
                               { yyval = yyvsp[0]; }
#line 1825 "y.tab.c"
    break;

  case 59: /* arg_list: arg_list COMMA expression  */
#line 350 "cminus.y"
                    {
                        if (yyvsp[-2] != NULL) {
                            YYSTYPE t = yyvsp[-2];
                            while (t->sibling != NULL) {
                                t = t->sibling;
                            }
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-2];
                        } else {
                            yyval = yyvsp[0];
                        }
                    }
#line 1842 "y.tab.c"
    break;

  case 60: /* arg_list: expression  */
#line 362 "cminus.y"
                                 { yyval = yyvsp[0]; }
#line 1848 "y.tab.c"
    break;

  case 61: /* identifier: ID  */
#line 365 "cminus.y"
                    {
                        yyval = newExpNode(IdK);
                        yyval->lineno = lineno;
                        yyval->attr.name = copyString(tokenString);
                    }
#line 1858 "y.tab.c"
    break;

  case 62: /* number: NUM  */
#line 372 "cminus.y"
                    {
                        yyval = newExpNode(ConstK);
                        yyval->lineno = lineno;
                        yyval->attr.val = atoi(tokenString);
                    }
#line 1868 "y.tab.c"
    break;

  case 63: /* empty: %empty  */
#line 378 "cminus.y"
                      {yyval = NULL;}
#line 1874 "y.tab.c"
    break;


#line 1878 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 381 "cminus.y"


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

