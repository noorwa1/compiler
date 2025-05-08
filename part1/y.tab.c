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
#line 1 "part1.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.c"

typedef struct node
{
	char *token;
	struct node *left;
	struct node *mid;
	struct node *right;
} node;

node* mknode(char* token, node *left,node *right);
void printTree(node *tree);
void printtree(node *tree, int level, int linebreak);
char* concat(char* s1, char* s2);

void printTabs(int n);
void printTabsOnce(int n);
void pausex();
void unpause();
void printNewline();
int streq(char* s1, char* s2);
int isType(char* t);
int isOperator(char* t);

int openParenthesis = 0;
int pauselevel = 0;
int hadOperator = 0;
int currentTab = 0;
int yylex();
int yyerror(char *e);


#line 108 "y.tab.c"

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
    ARGS = 258,                    /* ARGS  */
    DO = 259,                      /* DO  */
    WHILE = 260,                   /* WHILE  */
    FOR = 261,                     /* FOR  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    VAR = 264,                     /* VAR  */
    BOOL = 265,                    /* BOOL  */
    STRING = 266,                  /* STRING  */
    CHARPTR = 267,                 /* CHARPTR  */
    CHAR = 268,                    /* CHAR  */
    INT = 269,                     /* INT  */
    INTPTR = 270,                  /* INTPTR  */
    REAL = 271,                    /* REAL  */
    REALPTR = 272,                 /* REALPTR  */
    TYPE = 273,                    /* TYPE  */
    ADDRESS = 274,                 /* ADDRESS  */
    ASSIGNMENT = 275,              /* ASSIGNMENT  */
    LENGTH = 276,                  /* LENGTH  */
    NOT = 277,                     /* NOT  */
    EQ = 278,                      /* EQ  */
    NOTEQ = 279,                   /* NOTEQ  */
    GTE = 280,                     /* GTE  */
    GT = 281,                      /* GT  */
    LTW = 282,                     /* LTW  */
    LT = 283,                      /* LT  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    DIVISION = 286,                /* DIVISION  */
    PLUS = 287,                    /* PLUS  */
    MINUS = 288,                   /* MINUS  */
    STAR = 289,                    /* STAR  */
    DDASH = 290,                   /* DDASH  */
    STR_VAL = 291,                 /* STR_VAL  */
    REAL_VAL = 292,                /* REAL_VAL  */
    CHAR_VAL = 293,                /* CHAR_VAL  */
    DEC_VAL = 294,                 /* DEC_VAL  */
    HEX_VAL = 295,                 /* HEX_VAL  */
    NULLL = 296,                   /* NULLL  */
    BTRUE = 297,                   /* BTRUE  */
    BFALSE = 298,                  /* BFALSE  */
    SEMICOLON = 299,               /* SEMICOLON  */
    COMMA = 300,                   /* COMMA  */
    LPAREN = 301,                  /* LPAREN  */
    RPAREN = 302,                  /* RPAREN  */
    LBRACKET = 303,                /* LBRACKET  */
    RBRACKET = 304,                /* RBRACKET  */
    LBRACE = 305,                  /* LBRACE  */
    RBRACE = 306,                  /* RBRACE  */
    BEG = 307,                     /* BEG  */
    END = 308,                     /* END  */
    COLON = 309,                   /* COLON  */
    ARG_ARROW = 310,               /* ARG_ARROW  */
    VOID = 311,                    /* VOID  */
    FUNCTION = 312,                /* FUNCTION  */
    MAIN = 313,                    /* MAIN  */
    RETURN = 314,                  /* RETURN  */
    ID = 315,                      /* ID  */
    DEF = 316,                     /* DEF  */
    RETURNS = 317,                 /* RETURNS  */
    LTE = 318                      /* LTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ARGS 258
#define DO 259
#define WHILE 260
#define FOR 261
#define IF 262
#define ELSE 263
#define VAR 264
#define BOOL 265
#define STRING 266
#define CHARPTR 267
#define CHAR 268
#define INT 269
#define INTPTR 270
#define REAL 271
#define REALPTR 272
#define TYPE 273
#define ADDRESS 274
#define ASSIGNMENT 275
#define LENGTH 276
#define NOT 277
#define EQ 278
#define NOTEQ 279
#define GTE 280
#define GT 281
#define LTW 282
#define LT 283
#define AND 284
#define OR 285
#define DIVISION 286
#define PLUS 287
#define MINUS 288
#define STAR 289
#define DDASH 290
#define STR_VAL 291
#define REAL_VAL 292
#define CHAR_VAL 293
#define DEC_VAL 294
#define HEX_VAL 295
#define NULLL 296
#define BTRUE 297
#define BFALSE 298
#define SEMICOLON 299
#define COMMA 300
#define LPAREN 301
#define RPAREN 302
#define LBRACKET 303
#define RBRACKET 304
#define LBRACE 305
#define RBRACE 306
#define BEG 307
#define END 308
#define COLON 309
#define ARG_ARROW 310
#define VOID 311
#define FUNCTION 312
#define MAIN 313
#define RETURN 314
#define ID 315
#define DEF 316
#define RETURNS 317
#define LTE 318

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "part1.y"

    struct node *node;
    char *string;
	char* num;

#line 293 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
  YYSYMBOL_ARGS = 3,                       /* ARGS  */
  YYSYMBOL_DO = 4,                         /* DO  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_STRING = 11,                    /* STRING  */
  YYSYMBOL_CHARPTR = 12,                   /* CHARPTR  */
  YYSYMBOL_CHAR = 13,                      /* CHAR  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_INTPTR = 15,                    /* INTPTR  */
  YYSYMBOL_REAL = 16,                      /* REAL  */
  YYSYMBOL_REALPTR = 17,                   /* REALPTR  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_ADDRESS = 19,                   /* ADDRESS  */
  YYSYMBOL_ASSIGNMENT = 20,                /* ASSIGNMENT  */
  YYSYMBOL_LENGTH = 21,                    /* LENGTH  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NOTEQ = 24,                     /* NOTEQ  */
  YYSYMBOL_GTE = 25,                       /* GTE  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_LTW = 27,                       /* LTW  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_DIVISION = 31,                  /* DIVISION  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_STAR = 34,                      /* STAR  */
  YYSYMBOL_DDASH = 35,                     /* DDASH  */
  YYSYMBOL_STR_VAL = 36,                   /* STR_VAL  */
  YYSYMBOL_REAL_VAL = 37,                  /* REAL_VAL  */
  YYSYMBOL_CHAR_VAL = 38,                  /* CHAR_VAL  */
  YYSYMBOL_DEC_VAL = 39,                   /* DEC_VAL  */
  YYSYMBOL_HEX_VAL = 40,                   /* HEX_VAL  */
  YYSYMBOL_NULLL = 41,                     /* NULLL  */
  YYSYMBOL_BTRUE = 42,                     /* BTRUE  */
  YYSYMBOL_BFALSE = 43,                    /* BFALSE  */
  YYSYMBOL_SEMICOLON = 44,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_LPAREN = 46,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 47,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 48,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 49,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 50,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 51,                    /* RBRACE  */
  YYSYMBOL_BEG = 52,                       /* BEG  */
  YYSYMBOL_END = 53,                       /* END  */
  YYSYMBOL_COLON = 54,                     /* COLON  */
  YYSYMBOL_ARG_ARROW = 55,                 /* ARG_ARROW  */
  YYSYMBOL_VOID = 56,                      /* VOID  */
  YYSYMBOL_FUNCTION = 57,                  /* FUNCTION  */
  YYSYMBOL_MAIN = 58,                      /* MAIN  */
  YYSYMBOL_RETURN = 59,                    /* RETURN  */
  YYSYMBOL_ID = 60,                        /* ID  */
  YYSYMBOL_DEF = 61,                       /* DEF  */
  YYSYMBOL_RETURNS = 62,                   /* RETURNS  */
  YYSYMBOL_LTE = 63,                       /* LTE  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_project = 65,                   /* project  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_procedures = 67,                /* procedures  */
  YYSYMBOL_proc = 68,                      /* proc  */
  YYSYMBOL_functype = 69,                  /* functype  */
  YYSYMBOL_params = 70,                    /* params  */
  YYSYMBOL_parameters = 71,                /* parameters  */
  YYSYMBOL_par = 72,                       /* par  */
  YYSYMBOL_body = 73,                      /* body  */
  YYSYMBOL_body_ret = 74,                  /* body_ret  */
  YYSYMBOL_ret = 75,                       /* ret  */
  YYSYMBOL_declartions = 76,               /* declartions  */
  YYSYMBOL_declars = 77,                   /* declars  */
  YYSYMBOL_for_declars = 78,               /* for_declars  */
  YYSYMBOL_str_dec = 79,                   /* str_dec  */
  YYSYMBOL_var_asis = 80,                  /* var_asis  */
  YYSYMBOL_ref = 81,                       /* ref  */
  YYSYMBOL_value = 82,                     /* value  */
  YYSYMBOL_statements = 83,                /* statements  */
  YYSYMBOL_stmnt_block = 84,               /* stmnt_block  */
  YYSYMBOL_statement = 85,                 /* statement  */
  YYSYMBOL_if = 86,                        /* if  */
  YYSYMBOL_if_else = 87,                   /* if_else  */
  YYSYMBOL_while = 88,                     /* while  */
  YYSYMBOL_do = 89,                        /* do  */
  YYSYMBOL_for = 90,                       /* for  */
  YYSYMBOL_if_block = 91,                  /* if_block  */
  YYSYMBOL_block = 92,                     /* block  */
  YYSYMBOL_assignment = 93,                /* assignment  */
  YYSYMBOL_lhs = 94,                       /* lhs  */
  YYSYMBOL_expr = 95,                      /* expr  */
  YYSYMBOL_derefrence_expr = 96,           /* derefrence_expr  */
  YYSYMBOL_expr_list = 97,                 /* expr_list  */
  YYSYMBOL_paren_expr = 98,                /* paren_expr  */
  YYSYMBOL_call_func = 99                  /* call_func  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   626

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    76,    78,    79,    84,    89,    94,   101,
     102,   103,   104,   105,   106,   107,   110,   111,   114,   115,
     118,   119,   122,   127,   132,   149,   150,   153,   154,   157,
     158,   159,   161,   162,   163,   164,   167,   168,   170,   171,
     172,   173,   175,   176,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   192,   193,   197,   198,   199,
     200,   203,   204,   205,   206,   207,   208,   209,   210,   213,
     220,   229,   236,   244,   253,   258,   263,   264,   267,   268,
     269,   273,   275,   276,   277,   278,   279,   280,   281,   282,
     284,   285,   286,   287,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   306,   312,
     314,   315,   318,   319,   320,   325,   326,   327,   329,   332
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
  "\"end of file\"", "error", "\"invalid token\"", "ARGS", "DO", "WHILE",
  "FOR", "IF", "ELSE", "VAR", "BOOL", "STRING", "CHARPTR", "CHAR", "INT",
  "INTPTR", "REAL", "REALPTR", "TYPE", "ADDRESS", "ASSIGNMENT", "LENGTH",
  "NOT", "EQ", "NOTEQ", "GTE", "GT", "LTW", "LT", "AND", "OR", "DIVISION",
  "PLUS", "MINUS", "STAR", "DDASH", "STR_VAL", "REAL_VAL", "CHAR_VAL",
  "DEC_VAL", "HEX_VAL", "NULLL", "BTRUE", "BFALSE", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "BEG",
  "END", "COLON", "ARG_ARROW", "VOID", "FUNCTION", "MAIN", "RETURN", "ID",
  "DEF", "RETURNS", "LTE", "$accept", "project", "program", "procedures",
  "proc", "functype", "params", "parameters", "par", "body", "body_ret",
  "ret", "declartions", "declars", "for_declars", "str_dec", "var_asis",
  "ref", "value", "statements", "stmnt_block", "statement", "if",
  "if_else", "while", "do", "for", "if_block", "block", "assignment",
  "lhs", "expr", "derefrence_expr", "expr_list", "paren_expr", "call_func", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -214,    17,  -214,   -47,  -214,   -12,  -214,    -4,    37,    55,
      97,    65,   213,    54,  -214,    97,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,    73,    74,    70,    58,   -37,    78,    75,
      87,  -214,   213,    57,    58,    97,    15,    80,    83,   213,
    -214,  -214,   119,   142,  -214,  -214,    86,   140,   130,    88,
     200,    94,   200,    85,    99,   200,   106,    45,    31,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,   200,   130,    -2,  -214,
     142,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   145,   224,
    -214,  -214,    15,   107,  -214,   108,   112,  -214,    63,    35,
      64,   241,    13,   260,   120,   146,  -214,  -214,  -214,  -214,
     200,    -8,   277,   142,   200,   200,  -214,  -214,   171,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
    -214,   200,   142,  -214,   116,   111,   113,   117,   130,   200,
     124,  -214,   173,  -214,  -214,  -214,   138,   200,    63,   213,
     147,   169,    63,   200,  -214,   302,   200,  -214,   143,   322,
     150,   345,   154,   358,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,     9,   563,   563,     9,  -214,   141,  -214,   151,   157,
     152,  -214,   142,   381,   200,   200,   403,  -214,   155,   200,
     200,   208,   425,  -214,   447,  -214,   200,  -214,   198,  -214,
    -214,  -214,   181,  -214,   566,    27,  -214,   469,   483,  -214,
       6,  -214,   505,   547,   170,  -214,  -214,  -214,   186,   199,
      77,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   201,
     191,  -214,  -214,    66,   155,   -15,    63,     7,  -214,  -214,
    -214,  -214,  -214,   202,  -214,   206,   214,  -214,   243,  -214,
     225,   111,  -214,   155,   155,   200,   231,  -214,  -214,  -214,
     527,   111,   223,  -214,   226,    63,   227,  -214
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     3,     1,     0,     4,     0,     0,     0,
      17,     0,     0,     0,    16,    17,     9,    13,    10,    11,
      15,    12,    14,     0,     0,     0,     0,     0,     0,    21,
      19,     5,     0,     0,     0,    17,    26,     0,     0,     0,
      20,    18,     0,    56,     7,     5,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     100,    97,    99,   111,   105,   104,     0,    26,   110,    22,
      56,    63,    64,    65,    66,    67,    68,    62,     0,     0,
      95,    96,    26,     0,     5,     0,     0,    25,     0,     0,
     110,     0,    31,     0,   106,     0,    94,   102,   103,    98,
       0,   112,     0,    56,   117,     0,   119,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,    56,     6,     0,     0,     0,     0,    26,     0,
      78,    60,     0,    57,    58,    59,   112,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,    81,     0,   116,
       0,     0,     0,     0,    82,    83,    84,    85,    87,    88,
      89,    93,    90,    91,    92,    86,     0,     8,     0,     0,
       0,    80,    56,     0,     0,     0,     0,    71,     0,     0,
       0,    69,     0,   113,     0,    75,   117,   118,   109,    77,
      76,    23,     0,    28,     0,     0,    24,     0,     0,   109,
      41,    29,     0,    30,     0,   107,   114,   115,     0,     0,
       0,    44,    49,    45,    46,    48,    54,    52,    53,     0,
       0,    79,    72,     0,     0,     0,     0,    33,    50,    51,
      47,    27,    74,     0,    42,    39,    40,    37,     0,    70,
       0,     0,    43,     0,     0,     0,    35,    32,    38,    36,
       0,     0,     0,    34,     0,     0,     0,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,    10,  -214,   -26,    14,  -214,   245,  -214,
     197,  -159,   -39,  -214,  -214,  -163,  -213,  -214,    59,   -28,
    -134,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   -85,   -68,
     -91,   -50,  -214,   110,  -214,  -214
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    82,     6,    23,    13,    14,    30,    37,
      83,   131,    43,    48,   140,   169,   201,   235,   219,    69,
     132,    70,    71,    72,    73,    74,    75,   133,    76,    77,
      78,    79,    80,   150,   106,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,   141,    93,   134,   177,    96,    38,   191,   181,    87,
       3,   237,   -80,    46,     5,    31,   102,     4,   -78,   127,
     135,    86,   139,     7,    42,    32,   223,   240,   103,    25,
     248,   249,   109,   110,   111,   112,   220,   113,   114,   115,
     146,    36,   107,   122,   104,   130,   105,   127,     8,    41,
     145,   224,   241,   134,   149,   151,     9,   134,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     135,   165,   121,   130,   135,   148,     5,   100,   247,   173,
     185,   100,    98,    10,    99,   233,   129,   176,   253,   172,
      11,   101,   239,   182,   166,   136,   184,   127,   209,   210,
      12,    24,   211,   212,   213,   214,   215,   216,   217,   218,
     104,    15,   137,   178,   229,   128,   230,    28,    29,    39,
      34,   256,   129,   130,   197,   198,   234,    26,    27,   202,
     203,    35,    33,    44,   238,    45,   149,    47,    84,    42,
      92,   134,    88,    97,   195,    94,    49,    50,    51,    52,
      16,    85,    17,    18,    19,    20,    21,    22,   135,    95,
     123,    53,   125,    54,    55,   108,   126,   144,   143,   167,
     134,   168,   174,   170,    56,    57,    58,   171,   175,    59,
      60,    61,    62,    63,    64,    65,   146,   135,    66,   180,
      53,   179,    54,    55,    67,   250,   185,   187,   189,   192,
     129,   193,    68,    56,    57,    89,   194,   152,    59,    60,
      61,    62,    63,    64,    65,   200,   204,    66,   -79,    53,
     208,    54,    55,    16,   226,    17,    18,    19,    20,    21,
      22,    90,    56,    57,    89,   227,   228,    59,    60,    61,
      62,    63,    64,    65,   232,   231,    66,   109,   110,   111,
     112,   243,   113,   114,   115,   116,   117,   118,   119,   244,
      90,   246,   242,   245,   109,   110,   111,   112,   120,   113,
     114,   115,   116,   117,   118,   119,   251,   254,   255,    40,
     257,   124,   236,   109,   110,   111,   112,   121,   113,   114,
     115,   116,   117,   118,   119,   138,   207,     0,     0,     0,
     109,   110,   111,   112,   121,   113,   114,   115,   116,   117,
     118,   119,     0,     0,   142,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   147,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
     121,     0,     0,     0,     0,   109,   110,   111,   112,   183,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,   186,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,   118,   119,
       0,   109,   110,   111,   112,   121,   113,   114,   115,   116,
     117,   118,   119,     0,   188,     0,     0,     0,     0,     0,
       0,     0,   190,     0,   109,   110,   111,   112,   121,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   196,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   109,   110,
     111,   112,   199,   113,   114,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     109,   110,   111,   112,   205,   113,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   109,   110,   111,   112,   206,   113,   114,   115,
     116,   117,   118,   119,     0,     0,   109,   110,   111,   112,
     121,   113,   114,   115,   116,   117,   118,   119,   221,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   109,   110,
     111,   112,   121,   113,   114,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,     0,   121,     0,     0,   225,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,   121,     0,
     109,   110,   111,   112,   252,   113,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,   109,   110,   111,   112,
     121,   113,   114,   115,   116,     0,     0,   119,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121
};

static const yytype_int16 yycheck[] =
{
      50,    92,    52,    88,   138,    55,    32,   166,   142,    48,
       0,   224,    20,    39,    61,    52,    66,     0,    20,    34,
      88,    47,     9,    35,     9,    62,    20,    20,    67,    15,
     243,   244,    23,    24,    25,    26,   195,    28,    29,    30,
      48,    31,    70,    82,    46,    60,    48,    34,    60,    35,
     100,    45,    45,   138,   104,   105,    60,   142,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     138,   121,    63,    60,   142,   103,    61,    46,   241,   129,
      53,    46,    37,    46,    39,    19,    59,   137,   251,   128,
      35,    60,   226,   143,   122,    60,   146,    34,    32,    33,
       3,    47,    36,    37,    38,    39,    40,    41,    42,    43,
      46,    46,    48,   139,    37,    52,    39,    47,    60,    62,
      45,   255,    59,    60,   174,   175,    60,    54,    54,   179,
     180,    44,    54,    53,   225,    52,   186,    18,    52,     9,
      46,   226,    54,    37,   172,    60,     4,     5,     6,     7,
      10,    11,    12,    13,    14,    15,    16,    17,   226,    60,
      53,    19,    54,    21,    22,    20,    54,    21,    48,    53,
     255,    60,    48,    60,    32,    33,    34,    60,     5,    37,
      38,    39,    40,    41,    42,    43,    48,   255,    46,    20,
      19,    44,    21,    22,    52,   245,    53,    47,    44,    48,
      59,    44,    60,    32,    33,    34,    54,    36,    37,    38,
      39,    40,    41,    42,    43,    60,     8,    46,    20,    19,
      39,    21,    22,    10,    54,    12,    13,    14,    15,    16,
      17,    60,    32,    33,    34,    49,    37,    37,    38,    39,
      40,    41,    42,    43,    53,    44,    46,    23,    24,    25,
      26,    45,    28,    29,    30,    31,    32,    33,    34,    45,
      60,    36,    60,    20,    23,    24,    25,    26,    44,    28,
      29,    30,    31,    32,    33,    34,    45,    54,    52,    34,
      53,    84,   223,    23,    24,    25,    26,    63,    28,    29,
      30,    31,    32,    33,    34,    54,   186,    -1,    -1,    -1,
      23,    24,    25,    26,    63,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    47,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    47,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    45,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      -1,    23,    24,    25,    26,    63,    28,    29,    30,    31,
      32,    33,    34,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    23,    24,    25,    26,    63,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    44,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    23,    24,
      25,    26,    49,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      23,    24,    25,    26,    49,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    23,    24,    25,    26,    49,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    23,    24,    25,    26,
      63,    28,    29,    30,    31,    32,    33,    34,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    23,    24,
      25,    26,    63,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    44,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      23,    24,    25,    26,    47,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      63,    28,    29,    30,    31,    -1,    -1,    34,    32,    33,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,    67,     0,    61,    68,    35,    60,    60,
      46,    35,     3,    70,    71,    46,    10,    12,    13,    14,
      15,    16,    17,    69,    47,    70,    54,    54,    47,    60,
      72,    52,    62,    54,    45,    44,    67,    73,    69,    62,
      72,    70,     9,    76,    53,    52,    69,    18,    77,     4,
       5,     6,     7,    19,    21,    22,    32,    33,    34,    37,
      38,    39,    40,    41,    42,    43,    46,    52,    60,    83,
      85,    86,    87,    88,    89,    90,    92,    93,    94,    95,
      96,    99,    67,    74,    52,    11,    69,    76,    54,    34,
      60,    95,    46,    95,    60,    60,    95,    37,    37,    39,
      46,    60,    95,    76,    46,    48,    98,    83,    20,    23,
      24,    25,    26,    28,    29,    30,    31,    32,    33,    34,
      44,    63,    76,    53,    74,    54,    54,    34,    52,    59,
      60,    75,    84,    91,    92,    93,    60,    48,    54,     9,
      78,    94,    54,    48,    21,    95,    48,    47,    83,    95,
      97,    95,    36,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    83,    53,    60,    79,
      60,    60,    76,    95,    48,     5,    95,    84,    69,    44,
      20,    84,    95,    47,    95,    53,    45,    47,    49,    44,
      44,    75,    48,    44,    54,    83,    44,    95,    95,    49,
      60,    80,    95,    95,     8,    49,    49,    97,    39,    32,
      33,    36,    37,    38,    39,    40,    41,    42,    43,    82,
      75,    49,    44,    20,    45,    44,    54,    49,    37,    37,
      39,    44,    53,    19,    60,    81,    82,    80,    94,    84,
      20,    45,    60,    45,    45,    20,    36,    79,    80,    80,
      95,    45,    47,    79,    54,    52,    84,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    67,    67,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    74,    75,    76,    76,    77,    77,    78,
      78,    78,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    93,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    97,    97,    97,    98,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,    11,     9,    13,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     4,
       3,     1,     3,     4,     3,     3,     0,     7,     5,     3,
       3,     0,     6,     4,     8,     6,     5,     3,     5,     3,
       3,     1,     1,     2,     1,     1,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     2,     0,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       7,     4,     6,    14,     5,     4,     4,     4,     1,     4,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     2,     1,
       1,     1,     2,     2,     1,     1,     2,     5,     3,     4,
       1,     1,     2,     4,     5,     3,     1,     0,     3,     2
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
  case 2: /* project: program  */
#line 74 "part1.y"
                    {printTree((yyvsp[0].node));}
#line 1613 "y.tab.c"
    break;

  case 3: /* program: procedures  */
#line 76 "part1.y"
                       {(yyval.node)=mknode("CODE ",(yyvsp[0].node),NULL);}
#line 1619 "y.tab.c"
    break;

  case 4: /* procedures: procedures proc  */
#line 78 "part1.y"
                            {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1625 "y.tab.c"
    break;

  case 5: /* procedures: %empty  */
#line 79 "part1.y"
                          {(yyval.node)=NULL;}
#line 1631 "y.tab.c"
    break;

  case 6: /* proc: DEF ID LPAREN params RPAREN COLON RETURNS functype BEG body_ret END  */
#line 85 "part1.y"
                        {
				(yyval.node)=mknode("(FUNC\n\t ", mknode((yyvsp[-9].string),mknode("\n",mknode("\t\t(PARS\n ",(yyvsp[-7].node),NULL),mknode("\n\t\t(RET ",(yyvsp[-3].node),NULL)),NULL),(yyvsp[-1].node));
			}
#line 1639 "y.tab.c"
    break;

  case 7: /* proc: DEF ID LPAREN params RPAREN COLON BEG body END  */
#line 90 "part1.y"
                        {
				(yyval.node)=mknode("(FUNC\n\t ", mknode((yyvsp[-7].string),mknode("\n",mknode("\n\t\t(PARS\n ",(yyvsp[-5].node),NULL),mknode("\n\t\t(RET ",NULL,NULL)),NULL),mknode(")\n",(yyvsp[-1].node),NULL));
			}
#line 1647 "y.tab.c"
    break;

  case 8: /* proc: DEF DDASH ID DDASH LPAREN params RPAREN COLON RETURNS functype BEG body_ret END  */
#line 95 "part1.y"
                        {
				(yyval.node)=mknode("(FUNC\n\t ", mknode((yyvsp[-10].string),mknode("\n",mknode("\t\t(PARS\n ",(yyvsp[-7].node),NULL),mknode("\n\t\t(RET ",(yyvsp[-3].node),NULL)),NULL),(yyvsp[-1].node));
			}
#line 1655 "y.tab.c"
    break;

  case 9: /* functype: BOOL  */
#line 101 "part1.y"
                 {(yyval.node)=mknode(" BOOL ",NULL,NULL);}
#line 1661 "y.tab.c"
    break;

  case 10: /* functype: CHAR  */
#line 102 "part1.y"
                               {(yyval.node)=mknode(" CHAR ",NULL,NULL);}
#line 1667 "y.tab.c"
    break;

  case 11: /* functype: INT  */
#line 103 "part1.y"
                  {(yyval.node)=mknode(" INT ",NULL,NULL);}
#line 1673 "y.tab.c"
    break;

  case 12: /* functype: REAL  */
#line 104 "part1.y"
                   {(yyval.node)=mknode(" REAL ",NULL,NULL);}
#line 1679 "y.tab.c"
    break;

  case 13: /* functype: CHARPTR  */
#line 105 "part1.y"
                                  {(yyval.node)=mknode(" CHAR* ",NULL,NULL);}
#line 1685 "y.tab.c"
    break;

  case 14: /* functype: REALPTR  */
#line 106 "part1.y"
                                  {(yyval.node)=mknode(" REAL* ",NULL,NULL);}
#line 1691 "y.tab.c"
    break;

  case 15: /* functype: INTPTR  */
#line 107 "part1.y"
                                 {(yyval.node)=mknode(" INT* ",NULL,NULL);}
#line 1697 "y.tab.c"
    break;

  case 16: /* params: parameters  */
#line 110 "part1.y"
                           {(yyval.node)= mknode("",(yyvsp[0].node),NULL);}
#line 1703 "y.tab.c"
    break;

  case 17: /* params: %empty  */
#line 111 "part1.y"
                          {(yyval.node)=mknode("NONE",NULL,NULL);}
#line 1709 "y.tab.c"
    break;

  case 18: /* parameters: ARGS functype COLON par SEMICOLON params  */
#line 114 "part1.y"
                                                       {(yyval.node)=mknode(" (",mknode((yyvsp[-5].num),(yyvsp[-4].node),(yyvsp[-2].node)), mknode(") ",mknode("\n",mknode("(",NULL,NULL),NULL),(yyvsp[0].node)));}
#line 1715 "y.tab.c"
    break;

  case 19: /* parameters: ARGS functype COLON par  */
#line 115 "part1.y"
                                                  {(yyval.node)=mknode(" (",mknode((yyvsp[-3].num),(yyvsp[-2].node),(yyvsp[0].node)),mknode(" )",NULL,NULL));}
#line 1721 "y.tab.c"
    break;

  case 20: /* par: ID COMMA par  */
#line 118 "part1.y"
                             {(yyval.node)=mknode((yyvsp[-2].string),mknode(" ",(yyvsp[0].node),NULL),NULL);}
#line 1727 "y.tab.c"
    break;

  case 21: /* par: ID  */
#line 119 "part1.y"
                             {(yyval.node)=mknode((yyvsp[0].string), NULL, NULL);}
#line 1733 "y.tab.c"
    break;

  case 22: /* body: procedures declartions statements  */
#line 123 "part1.y"
{
			(yyval.node)=mknode("body ",mknode("",(yyvsp[-2].node),NULL),mknode("",(yyvsp[-1].node),mknode("",(yyvsp[0].node),mknode("}",NULL,NULL))));
}
#line 1741 "y.tab.c"
    break;

  case 23: /* body_ret: procedures declartions statements ret  */
#line 128 "part1.y"
{
			(yyval.node)=mknode("body ",mknode("",(yyvsp[-3].node),NULL),mknode("",(yyvsp[-2].node),mknode("",(yyvsp[-1].node),mknode("",(yyvsp[0].node),NULL))));
}
#line 1749 "y.tab.c"
    break;

  case 24: /* ret: RETURN expr SEMICOLON  */
#line 132 "part1.y"
                                      {(yyval.node)=mknode("return",(yyvsp[-1].node),NULL);}
#line 1755 "y.tab.c"
    break;

  case 25: /* declartions: VAR declars declartions  */
#line 149 "part1.y"
                                     {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1761 "y.tab.c"
    break;

  case 26: /* declartions: %empty  */
#line 150 "part1.y"
                          {(yyval.node)=NULL;}
#line 1767 "y.tab.c"
    break;

  case 27: /* declars: TYPE functype COLON ID COLON value SEMICOLON  */
#line 153 "part1.y"
                                                             {(yyval.node)=mknode((yyvsp[-3].string),NULL,NULL);}
#line 1773 "y.tab.c"
    break;

  case 28: /* declars: TYPE STRING COLON str_dec SEMICOLON  */
#line 154 "part1.y"
                                                              {(yyval.node)=mknode("string",(yyvsp[-1].node),NULL);}
#line 1779 "y.tab.c"
    break;

  case 29: /* for_declars: VAR functype var_asis  */
#line 157 "part1.y"
                                   {(yyval.node)=mknode("var",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1785 "y.tab.c"
    break;

  case 30: /* for_declars: lhs ASSIGNMENT expr  */
#line 158 "part1.y"
                                              {(yyval.node)=mknode("=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1791 "y.tab.c"
    break;

  case 31: /* for_declars: %empty  */
#line 159 "part1.y"
                          {(yyval.node)=NULL;}
#line 1797 "y.tab.c"
    break;

  case 32: /* str_dec: ID LBRACKET DEC_VAL RBRACKET COMMA str_dec  */
#line 161 "part1.y"
                                                           {(yyval.node)=mknode((yyvsp[-5].string),mknode("",mknode("[",mknode((yyvsp[-3].string),NULL,NULL),mknode("]",NULL,NULL)),NULL),(yyvsp[0].node));}
#line 1803 "y.tab.c"
    break;

  case 33: /* str_dec: ID LBRACKET DEC_VAL RBRACKET  */
#line 162 "part1.y"
                                                       {(yyval.node)=mknode((yyvsp[-3].string),mknode("",mknode("[",mknode((yyvsp[-1].string),NULL,NULL),mknode("]",NULL,NULL)),NULL),NULL);}
#line 1809 "y.tab.c"
    break;

  case 34: /* str_dec: ID LBRACKET DEC_VAL RBRACKET ASSIGNMENT STR_VAL COMMA str_dec  */
#line 163 "part1.y"
                                                                                        {(yyval.node)=mknode((yyvsp[-7].string),mknode("",mknode("[",mknode((yyvsp[-5].string),NULL,NULL),mknode("]",NULL,NULL)),mknode((yyvsp[-2].string),NULL,NULL)),(yyvsp[0].node));}
#line 1815 "y.tab.c"
    break;

  case 35: /* str_dec: ID LBRACKET DEC_VAL RBRACKET ASSIGNMENT STR_VAL  */
#line 164 "part1.y"
                                                                          {(yyval.node)=mknode((yyvsp[-5].string),mknode("",mknode("[",mknode((yyvsp[-3].string),NULL,NULL),mknode("]",NULL,NULL)),mknode((yyvsp[0].string),NULL,NULL)),NULL);}
#line 1821 "y.tab.c"
    break;

  case 36: /* var_asis: ID ASSIGNMENT value COMMA var_asis  */
#line 167 "part1.y"
                                                   {(yyval.node)=mknode((yyvsp[-4].string),mknode("",(yyvsp[-2].node),NULL),(yyvsp[0].node));}
#line 1827 "y.tab.c"
    break;

  case 37: /* var_asis: ID COMMA var_asis  */
#line 168 "part1.y"
                                            {(yyval.node)=mknode((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 1833 "y.tab.c"
    break;

  case 38: /* var_asis: ID ASSIGNMENT ref COMMA var_asis  */
#line 170 "part1.y"
                                                           {(yyval.node)=mknode((yyvsp[-4].string),(yyvsp[-2].node),mknode("",(yyvsp[0].node),NULL));}
#line 1839 "y.tab.c"
    break;

  case 39: /* var_asis: ID ASSIGNMENT ref  */
#line 171 "part1.y"
                                            {(yyval.node)=mknode((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 1845 "y.tab.c"
    break;

  case 40: /* var_asis: ID ASSIGNMENT value  */
#line 172 "part1.y"
                                              {(yyval.node)=mknode((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 1851 "y.tab.c"
    break;

  case 41: /* var_asis: ID  */
#line 173 "part1.y"
                             {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 1857 "y.tab.c"
    break;

  case 42: /* ref: ID  */
#line 175 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 1863 "y.tab.c"
    break;

  case 43: /* ref: ADDRESS ID  */
#line 176 "part1.y"
                                     {(yyval.node)=mknode("&",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 1869 "y.tab.c"
    break;

  case 44: /* value: STR_VAL  */
#line 179 "part1.y"
                        {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 1875 "y.tab.c"
    break;

  case 45: /* value: CHAR_VAL  */
#line 180 "part1.y"
                                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 1881 "y.tab.c"
    break;

  case 46: /* value: DEC_VAL  */
#line 181 "part1.y"
                                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 1887 "y.tab.c"
    break;

  case 47: /* value: MINUS DEC_VAL  */
#line 182 "part1.y"
                                        {(yyval.node)=mknode(" -",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 1893 "y.tab.c"
    break;

  case 48: /* value: HEX_VAL  */
#line 183 "part1.y"
                                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 1899 "y.tab.c"
    break;

  case 49: /* value: REAL_VAL  */
#line 184 "part1.y"
                                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 1905 "y.tab.c"
    break;

  case 50: /* value: PLUS REAL_VAL  */
#line 185 "part1.y"
                                        {(yyval.node)=mknode(" +",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 1911 "y.tab.c"
    break;

  case 51: /* value: MINUS REAL_VAL  */
#line 186 "part1.y"
                                         {(yyval.node)=mknode(" +",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 1917 "y.tab.c"
    break;

  case 52: /* value: BTRUE  */
#line 187 "part1.y"
                                {(yyval.node)=mknode("TRUE ",NULL,NULL);}
#line 1923 "y.tab.c"
    break;

  case 53: /* value: BFALSE  */
#line 188 "part1.y"
                                 {(yyval.node)=mknode("FALSE ",NULL,NULL);}
#line 1929 "y.tab.c"
    break;

  case 54: /* value: NULLL  */
#line 189 "part1.y"
                                {(yyval.node)=mknode("null",NULL,NULL);}
#line 1935 "y.tab.c"
    break;

  case 55: /* statements: statement statements  */
#line 192 "part1.y"
                                     {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1941 "y.tab.c"
    break;

  case 56: /* statements: %empty  */
#line 193 "part1.y"
                          {(yyval.node)=NULL;}
#line 1947 "y.tab.c"
    break;

  case 57: /* stmnt_block: if_block  */
#line 197 "part1.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 1953 "y.tab.c"
    break;

  case 58: /* stmnt_block: block  */
#line 198 "part1.y"
                                        {(yyval.node)=(yyvsp[0].node);}
#line 1959 "y.tab.c"
    break;

  case 59: /* stmnt_block: assignment  */
#line 199 "part1.y"
                                             {(yyval.node)=(yyvsp[0].node);}
#line 1965 "y.tab.c"
    break;

  case 60: /* stmnt_block: ret  */
#line 200 "part1.y"
                                      {(yyval.node)=(yyvsp[0].node);}
#line 1971 "y.tab.c"
    break;

  case 61: /* statement: expr SEMICOLON  */
#line 203 "part1.y"
                           {(yyval.node)=(yyvsp[-1].node);}
#line 1977 "y.tab.c"
    break;

  case 62: /* statement: assignment  */
#line 204 "part1.y"
                                     {(yyval.node)=(yyvsp[0].node);}
#line 1983 "y.tab.c"
    break;

  case 63: /* statement: if  */
#line 205 "part1.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 1989 "y.tab.c"
    break;

  case 64: /* statement: if_else  */
#line 206 "part1.y"
                                  {(yyval.node)=(yyvsp[0].node);}
#line 1995 "y.tab.c"
    break;

  case 65: /* statement: while  */
#line 207 "part1.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2001 "y.tab.c"
    break;

  case 66: /* statement: do  */
#line 208 "part1.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2007 "y.tab.c"
    break;

  case 67: /* statement: for  */
#line 209 "part1.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2013 "y.tab.c"
    break;

  case 68: /* statement: block  */
#line 210 "part1.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2019 "y.tab.c"
    break;

  case 69: /* if: IF expr COLON stmnt_block  */
#line 214 "part1.y"
                        {
				(yyval.node)=mknode("if",
				mknode("", (yyvsp[-2].node),
				mknode("",NULL,NULL)),(yyvsp[0].node));
			}
#line 2029 "y.tab.c"
    break;

  case 70: /* if_else: IF expr COLON stmnt_block ELSE COLON stmnt_block  */
#line 221 "part1.y"
                        {
				(yyval.node)=mknode("if-else",
				mknode("", (yyvsp[-5].node),
				mknode("",NULL,NULL)),
				mknode("",(yyvsp[-3].node),
				mknode("",(yyvsp[0].node),NULL)));
			}
#line 2041 "y.tab.c"
    break;

  case 71: /* while: WHILE expr COLON stmnt_block  */
#line 230 "part1.y"
                        {
				(yyval.node)=mknode("while",
				mknode(" ", (yyvsp[-2].node),
				mknode(" ",NULL,NULL)),(yyvsp[0].node));
			}
#line 2051 "y.tab.c"
    break;

  case 72: /* do: DO COLON stmnt_block WHILE expr SEMICOLON  */
#line 237 "part1.y"
                        {
				(yyval.node)=mknode("do",
				mknode("{", (yyvsp[-3].node),
				mknode("}",NULL,NULL)),
				mknode("while",(yyvsp[-1].node),NULL));
			}
#line 2062 "y.tab.c"
    break;

  case 73: /* for: FOR LPAREN for_declars SEMICOLON expr SEMICOLON lhs ASSIGNMENT expr RPAREN COLON BEG stmnt_block END  */
#line 245 "part1.y"
                        {
				(yyval.node)=mknode("for",
				mknode("(",(yyvsp[-11].node),mknode("",(yyvsp[-9].node),mknode("=",(yyvsp[-7].node),mknode("",(yyvsp[-5].node),mknode(")",NULL,NULL))))),
				(yyvsp[-1].node));
			}
#line 2072 "y.tab.c"
    break;

  case 74: /* if_block: BEG declartions statements ret END  */
#line 254 "part1.y"
                        {
				(yyval.node)=mknode("{",(yyvsp[-3].node),mknode("", (yyvsp[-2].node), mknode("",(yyvsp[-1].node),mknode("}",NULL,NULL))));
			}
#line 2080 "y.tab.c"
    break;

  case 75: /* block: BEG declartions statements END  */
#line 259 "part1.y"
                        {
				(yyval.node)=mknode("{",(yyvsp[-2].node),mknode("", (yyvsp[-1].node), mknode("}",NULL,NULL)));
			}
#line 2088 "y.tab.c"
    break;

  case 76: /* assignment: lhs ASSIGNMENT expr SEMICOLON  */
#line 263 "part1.y"
                                              {(yyval.node)=mknode("=",(yyvsp[-3].node),mknode("",(yyvsp[-1].node),mknode("",NULL,NULL)));}
#line 2094 "y.tab.c"
    break;

  case 77: /* assignment: lhs ASSIGNMENT STR_VAL SEMICOLON  */
#line 264 "part1.y"
                                                           {(yyval.node)=mknode("=",(yyvsp[-3].node),mknode((yyvsp[-1].string),NULL,NULL));}
#line 2100 "y.tab.c"
    break;

  case 78: /* lhs: ID  */
#line 267 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2106 "y.tab.c"
    break;

  case 79: /* lhs: ID LBRACKET expr RBRACKET  */
#line 268 "part1.y"
                                                    {(yyval.node)=mknode((yyvsp[-3].string),mknode("[",(yyvsp[-1].node),mknode("]\n",NULL,NULL)),NULL);}
#line 2112 "y.tab.c"
    break;

  case 80: /* lhs: STAR ID  */
#line 269 "part1.y"
                                  {(yyval.node)=mknode("POINTER ",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2118 "y.tab.c"
    break;

  case 81: /* expr: LPAREN expr RPAREN  */
#line 273 "part1.y"
                          {(yyval.node)=mknode("(",(yyvsp[-1].node),mknode(")",NULL,NULL));}
#line 2124 "y.tab.c"
    break;

  case 82: /* expr: expr EQ expr  */
#line 275 "part1.y"
                   {(yyval.node)=mknode("==",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2130 "y.tab.c"
    break;

  case 83: /* expr: expr NOTEQ expr  */
#line 276 "part1.y"
                          {(yyval.node)=mknode("!=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2136 "y.tab.c"
    break;

  case 84: /* expr: expr GTE expr  */
#line 277 "part1.y"
                        {(yyval.node)=mknode(">=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2142 "y.tab.c"
    break;

  case 85: /* expr: expr GT expr  */
#line 278 "part1.y"
                       {(yyval.node)=mknode(">",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2148 "y.tab.c"
    break;

  case 86: /* expr: expr LTE expr  */
#line 279 "part1.y"
                        {(yyval.node)=mknode("<=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2154 "y.tab.c"
    break;

  case 87: /* expr: expr LT expr  */
#line 280 "part1.y"
                       {(yyval.node)=mknode("<",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2160 "y.tab.c"
    break;

  case 88: /* expr: expr AND expr  */
#line 281 "part1.y"
                        {(yyval.node)=mknode("and",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2166 "y.tab.c"
    break;

  case 89: /* expr: expr OR expr  */
#line 282 "part1.y"
                       {(yyval.node)=mknode("||",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2172 "y.tab.c"
    break;

  case 90: /* expr: expr PLUS expr  */
#line 284 "part1.y"
                         {(yyval.node)=mknode("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2178 "y.tab.c"
    break;

  case 91: /* expr: expr MINUS expr  */
#line 285 "part1.y"
                          {(yyval.node)=mknode("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2184 "y.tab.c"
    break;

  case 92: /* expr: expr STAR expr  */
#line 286 "part1.y"
                         {(yyval.node)=mknode("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2190 "y.tab.c"
    break;

  case 93: /* expr: expr DIVISION expr  */
#line 287 "part1.y"
                             {(yyval.node)=mknode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2196 "y.tab.c"
    break;

  case 94: /* expr: NOT expr  */
#line 289 "part1.y"
                   {(yyval.node)=mknode("not ",(yyvsp[0].node),NULL);}
#line 2202 "y.tab.c"
    break;

  case 95: /* expr: derefrence_expr  */
#line 290 "part1.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2208 "y.tab.c"
    break;

  case 96: /* expr: call_func  */
#line 291 "part1.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2214 "y.tab.c"
    break;

  case 97: /* expr: DEC_VAL  */
#line 292 "part1.y"
                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2220 "y.tab.c"
    break;

  case 98: /* expr: MINUS DEC_VAL  */
#line 293 "part1.y"
                        {(yyval.node)=mknode(concat("-",(yyvsp[0].string)),NULL,NULL);}
#line 2226 "y.tab.c"
    break;

  case 99: /* expr: HEX_VAL  */
#line 294 "part1.y"
                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2232 "y.tab.c"
    break;

  case 100: /* expr: CHAR_VAL  */
#line 295 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2238 "y.tab.c"
    break;

  case 101: /* expr: REAL_VAL  */
#line 296 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2244 "y.tab.c"
    break;

  case 102: /* expr: PLUS REAL_VAL  */
#line 297 "part1.y"
                        {(yyval.node)=mknode(concat("+",(yyvsp[0].string)),NULL,NULL);}
#line 2250 "y.tab.c"
    break;

  case 103: /* expr: MINUS REAL_VAL  */
#line 298 "part1.y"
                         {(yyval.node)=mknode(concat("-",(yyvsp[0].string)),NULL,NULL);}
#line 2256 "y.tab.c"
    break;

  case 104: /* expr: BFALSE  */
#line 299 "part1.y"
                 {(yyval.node)=mknode("FALSE ",NULL,NULL);}
#line 2262 "y.tab.c"
    break;

  case 105: /* expr: BTRUE  */
#line 300 "part1.y"
                {(yyval.node)=mknode("TRUE ",NULL,NULL);}
#line 2268 "y.tab.c"
    break;

  case 106: /* expr: ADDRESS ID  */
#line 301 "part1.y"
                     {(yyval.node)=mknode("&",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2274 "y.tab.c"
    break;

  case 107: /* expr: ADDRESS ID LBRACKET expr RBRACKET  */
#line 303 "part1.y"
        {
		(yyval.node)=mknode("&",mknode("[",mknode((yyvsp[-3].string),NULL,NULL),mknode("]",NULL,NULL)),(yyvsp[-1].node));
	}
#line 2282 "y.tab.c"
    break;

  case 108: /* expr: LENGTH ID LENGTH  */
#line 307 "part1.y"
        {
		(yyval.node)=mknode("|",
		mknode((yyvsp[-1].string),NULL,NULL),
		mknode("|",NULL,NULL));
	}
#line 2292 "y.tab.c"
    break;

  case 109: /* expr: ID LBRACKET expr RBRACKET  */
#line 313 "part1.y"
        {(yyval.node)=mknode((yyvsp[-3].string),mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)),NULL);}
#line 2298 "y.tab.c"
    break;

  case 110: /* expr: ID  */
#line 314 "part1.y"
             {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2304 "y.tab.c"
    break;

  case 111: /* expr: NULLL  */
#line 315 "part1.y"
                {(yyval.node)=mknode("null",NULL,NULL);}
#line 2310 "y.tab.c"
    break;

  case 112: /* derefrence_expr: STAR ID  */
#line 318 "part1.y"
                         {(yyval.node)=mknode("POINTER ",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2316 "y.tab.c"
    break;

  case 113: /* derefrence_expr: STAR LPAREN expr RPAREN  */
#line 319 "part1.y"
                                  {(yyval.node)=mknode("POINTER ",mknode("(",(yyvsp[-1].node),NULL),mknode(")",NULL,NULL));}
#line 2322 "y.tab.c"
    break;

  case 114: /* derefrence_expr: STAR ID LBRACKET expr RBRACKET  */
#line 321 "part1.y"
        {(yyval.node)=mknode("POINTER ", mknode((yyvsp[-3].string),NULL,NULL), mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)));}
#line 2328 "y.tab.c"
    break;

  case 115: /* expr_list: expr COMMA expr_list  */
#line 325 "part1.y"
                                     {(yyval.node)=mknode("",(yyvsp[-2].node),mknode("",(yyvsp[0].node),NULL));}
#line 2334 "y.tab.c"
    break;

  case 116: /* expr_list: expr  */
#line 326 "part1.y"
                                       {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2340 "y.tab.c"
    break;

  case 117: /* expr_list: %empty  */
#line 327 "part1.y"
                                  {(yyval.node)=NULL;}
#line 2346 "y.tab.c"
    break;

  case 118: /* paren_expr: LPAREN expr_list RPAREN  */
#line 329 "part1.y"
                                        {(yyval.node)=(yyvsp[-1].node);}
#line 2352 "y.tab.c"
    break;

  case 119: /* call_func: ID paren_expr  */
#line 332 "part1.y"
                         {(yyval.node)=mknode("Call func",mknode((yyvsp[-1].string),NULL,NULL),mknode("args ",(yyvsp[0].node),NULL));}
#line 2358 "y.tab.c"
    break;


#line 2362 "y.tab.c"

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

#line 334 "part1.y"


int main()
{
	return yyparse();
}

/* allocation for node*/
node* mknode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

char* concat(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len = len1 + len2;
	char* newstr = (char*)malloc(sizeof(char)*len + 1);
	int j = 0;
	for (int i = 0; i < len1; ++i) {
		newstr[j++] = s1[i];
	}
	for (int i = 0; i < len2; ++i) {
		newstr[j++] = s2[i];
	}
	newstr[j] = '\0';
	return newstr;
}

void printNewline() {
	printf("\n");
	currentTab = 0;
}

void printTabs(int n)
{
	if (pauselevel)
		return;
	for(int i = 0; i < n; ++i) {
		currentTab++;
		printf("\t");
	}
}

void printTabsOnce(int n) {
	int temp = pauselevel;
	unpause();
	printTabs(n);
	pauselevel = temp;
}

void pausex() {
	pauselevel = 1;
}

void unpause() {
	pauselevel = 0;
}

int streq(char* s1, char* s2) {
	return strcmp(s1, s2) == 0;
}

int isType(char* t) {
	return  streq(t, "BOOL ") ||
			streq(t, "INT ") ||
			streq(t, "CHAR ") ||
			streq(t, "REAL ") ||
			streq(t, "VOID ") ||
			streq(t, "INT* ") ||
			streq(t, "CHAR* ") ||
			streq(t, "REAL* ");
}

int isOperator(char* t) {
	return streq(t, ">") ||
		   streq(t, "<") ||
		   streq(t, ">=") ||
		   streq(t, "<=") ||
		   streq(t, "==") ||
		   streq(t, "!=") ||
		   streq(t, "!") ||
		   streq(t, "||") ||
		   streq(t, "&&") ||
		   streq(t, "*") ||
		   streq(t, "/") ||
		   streq(t, "+") ||
		   streq(t, "-");
}

void printTree(node* tree) {
	printtree(tree, 0, 0);
}

void printtree(node* tree, int level, int linebreak) {
	char* t = tree->token;
	struct node* left = tree->left;
	struct node* right = tree->right;
	char* r;
	char* l;
	if (left) l = tree->left->token;
	if (right) r = tree->right->token;

	int lvl = level;
	int closeParen = 0;
	int newline = 0;
	int tabs = 0;
	int leftBreak = 0;
	int rightBreak = 0;
	int pauseLeft = 0;
	int pauseRight = 0;
	int printTabsLeft = 0;
	int unpaus = 1;

	if (streq(t, "") ||
		streq(t, "\n") ||
		streq(t, " ") ||
		streq(t, "}")) {
		if (streq(t, "\n")) {
			printNewline();
			printTabsOnce(level);
		}
		unpaus = 0;
	} else {
		if (streq(t, ")") && openParenthesis == 0);
		else {
			if (currentTab == 0)
				printTabs(level);
		}
		lvl++;
		if (streq(t, "(")) {
			if (streq(r, ")") && streq(l, "")) {
				printNewline();
				printTabs(level);
				printf("(");
				openParenthesis++;
			}
			pauseLeft = 1;
			pauseRight = 1;
			lvl--;
		} else if (streq(t, ")")) {
			if (openParenthesis > 0) {
				printf("%s", t);
				printNewline();
				newline = 1;
				openParenthesis--;
			}
		} else if (streq(t, "FUNCTION ") || streq(t, "CODE ")) {
			printf("(%s", t);
			printNewline();
			closeParen = 1;
			newline = 1;
			leftBreak = 1;
			tabs = 1;
			unpause();
		} else if (streq(t, "Call func")) {
			if (hadOperator) {
				printNewline();
				printTabsOnce(level);
			}
			printf("(%s", t);
			printNewline();
			closeParen = 1;
			newline = 1;
			leftBreak = 1;
			tabs = 1;
			unpause();
			hadOperator = 1;
		} else if (streq(t, "args ")) {
			printf("(PARS");
			newline = 1;
			closeParen = 1;
			if (left) {
				tabs = 1;
				printNewline();
				pauseRight = 1;
				pauseLeft = 1;
				printTabs(level+1);
			} else {
				printf(" NONE");
			}
		} else if (streq(t, "type ")) {
			printf("(TYPE ");
			closeParen = 1;
			newline = 1;
			pauseLeft = 1;
		} else if (streq(t, "body ")) {
			printf("\t\t(BODY");
			printNewline();
			closeParen = 1;
			tabs = 1;
			newline = 1;
		} else if (streq(t, "return")) {
			printf("(RET ");
			closeParen = 1;
			pauseLeft = 1;
			newline = 1;
			if (left && isOperator(l)) tabs = 1;
		} else if (streq(t, "var") || streq(t, "string")) {
			printf("(DECLARE ");
			closeParen = 1;
			newline = 1;
			pauseLeft = 1;
			pauseRight = 1;
		} else if (streq(t, "if")){
			printf("(IF ");
			closeParen = 1;
			tabs = 1;
			newline = 1;
		} else if (streq(t, "if-else")){
			printf("(IF-ELSE ");
			closeParen = 1;
			tabs = 1;
			newline = 1;
		} else if (streq(t, "while")){
			printf("(WHILE ");
			closeParen = 1;
			tabs = 1;
			newline = 1;
		} else if (streq(t, "do")){
			printf("(DO");
			printNewline();
			closeParen = 1;
			tabs = 1;
			newline = 1;
		} else if (streq(t, "for")){
			printf("(FOR");
			printNewline();
			closeParen = 1;
			tabs = 1;
			newline = 1;
		} else if (streq(t, "{")) {
			printf("(BLOCK");
			printNewline();
			closeParen = 1;
			newline = 1;
			tabs = 1;
		} else if (isType(t)) {
			printf("%s", t);
			unpaus = 0;
		} else if (streq(t, "=")) {
			printf("(=");
			pauseLeft = 1;
			pauseRight = 1;
			closeParen = 1;
			newline = 1;
			hadOperator = 0;
		} else if (isOperator(t)) {
			printNewline();
			unpause();
			hadOperator = 1;
			printTabs(level);
			printf("(%s", t);
			if (streq(t, "!")) tabs = 1;
			closeParen = 1;
			pauseLeft = 1;
			newline = 1;
			if (right) {
				if (streq(r, "Call func")) {
					leftBreak = 1;
					printNewline();
					currentTab = 0;
					printTabsLeft = 1;
				} else {
					rightBreak = 1;
				}
				tabs = 1;
			}
			if (left && right) {
				rightBreak = 1;
				newline = 1;
			}
		} else if (streq(t, "]\n")) {
			printf("%s", t);
			printTabsOnce(level);
		} else if (streq(t, "TRUE ") || streq(t, "FALSE ")) {
			printf("%s", t);
			printNewline();
		} else {
			printf(" %s", t);
			unpaus = 0;
			if (linebreak) printNewline();
			--lvl;
		}
	}
	if (left) {
		if (printTabsLeft) { printTabsOnce(lvl); }
		if (pauseLeft) pausex();
		printtree(left, lvl, leftBreak);
	}
	if (right) {
		if (pauseRight) pausex();
		printtree(right, lvl, rightBreak);
	}
	if (currentTab == 0 && (tabs || (hadOperator && streq(t, "=")))) {
		if (streq(t, "args ") && !hadOperator);
		else {
			printTabsOnce(level);
			if (streq(t,"=")) hadOperator = 0;
		}
	}
	if (closeParen) { printf(")"); }
	if (newline) { printNewline(); }
	if (unpaus) { unpause(); }
}

int yyerror(char *e)
{
	int yydebug=1;
	fflush(stdout);
	fprintf(stderr, "Error: %s at line %d\n" ,e, yylineno);
	fprintf(stderr, "does not accept '%s'\n", yytext);

	return 0;
}
