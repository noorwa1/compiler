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
#include <stdbool.h>
#include <stdarg.h>
#define MAX_FUNCS 100
#define MAX_Var 100

int tempCount = 0;
int labelCount = 0;
char* currentFunc = NULL;
int paramSize = 0;

char* newTemp();
char* newLabel();
void resetCounters();

void genCode(const char* format, ...);
typedef struct node {
    char *token;
    struct node *left;
    struct node *mid;
    struct node *right;
} node;

node* mknode(char* token, node *left,node *right);

void printTree(node* tree);
int yyerror(char *e);


#line 105 "y.tab.c"

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
    BOOL = 264,                    /* BOOL  */
    STRING = 265,                  /* STRING  */
    CHARPTR = 266,                 /* CHARPTR  */
    CHAR = 267,                    /* CHAR  */
    INT = 268,                     /* INT  */
    INTPTR = 269,                  /* INTPTR  */
    REAL = 270,                    /* REAL  */
    REALPTR = 271,                 /* REALPTR  */
    ADDRESS = 272,                 /* ADDRESS  */
    ASSIGNMENT = 273,              /* ASSIGNMENT  */
    LENGTH = 274,                  /* LENGTH  */
    NOT = 275,                     /* NOT  */
    EQ = 276,                      /* EQ  */
    NOTEQ = 277,                   /* NOTEQ  */
    GTE = 278,                     /* GTE  */
    GT = 279,                      /* GT  */
    LTW = 280,                     /* LTW  */
    LT = 281,                      /* LT  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    DIVISION = 284,                /* DIVISION  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    STAR = 287,                    /* STAR  */
    STR_VAL = 288,                 /* STR_VAL  */
    REAL_VAL = 289,                /* REAL_VAL  */
    CHAR_VAL = 290,                /* CHAR_VAL  */
    DEC_VAL = 291,                 /* DEC_VAL  */
    HEX_VAL = 292,                 /* HEX_VAL  */
    NULLL = 293,                   /* NULLL  */
    BTRUE = 294,                   /* BTRUE  */
    BFALSE = 295,                  /* BFALSE  */
    SEMICOLON = 296,               /* SEMICOLON  */
    COMMA = 297,                   /* COMMA  */
    LPAREN = 298,                  /* LPAREN  */
    RPAREN = 299,                  /* RPAREN  */
    LBRACKET = 300,                /* LBRACKET  */
    RBRACKET = 301,                /* RBRACKET  */
    LBRACE = 302,                  /* LBRACE  */
    RBRACE = 303,                  /* RBRACE  */
    BEG = 304,                     /* BEG  */
    END = 305,                     /* END  */
    COLON = 306,                   /* COLON  */
    ARG_ARROW = 307,               /* ARG_ARROW  */
    VOID = 308,                    /* VOID  */
    FUNCTION = 309,                /* FUNCTION  */
    MAIN = 310,                    /* MAIN  */
    RETURN = 311,                  /* RETURN  */
    ID = 312,                      /* ID  */
    DEF = 313,                     /* DEF  */
    RETURNS = 314,                 /* RETURNS  */
    VAR = 315,                     /* VAR  */
    TYPE = 316,                    /* TYPE  */
    LTE = 317                      /* LTE  */
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
#define BOOL 264
#define STRING 265
#define CHARPTR 266
#define CHAR 267
#define INT 268
#define INTPTR 269
#define REAL 270
#define REALPTR 271
#define ADDRESS 272
#define ASSIGNMENT 273
#define LENGTH 274
#define NOT 275
#define EQ 276
#define NOTEQ 277
#define GTE 278
#define GT 279
#define LTW 280
#define LT 281
#define AND 282
#define OR 283
#define DIVISION 284
#define PLUS 285
#define MINUS 286
#define STAR 287
#define STR_VAL 288
#define REAL_VAL 289
#define CHAR_VAL 290
#define DEC_VAL 291
#define HEX_VAL 292
#define NULLL 293
#define BTRUE 294
#define BFALSE 295
#define SEMICOLON 296
#define COMMA 297
#define LPAREN 298
#define RPAREN 299
#define LBRACKET 300
#define RBRACKET 301
#define LBRACE 302
#define RBRACE 303
#define BEG 304
#define END 305
#define COLON 306
#define ARG_ARROW 307
#define VOID 308
#define FUNCTION 309
#define MAIN 310
#define RETURN 311
#define ID 312
#define DEF 313
#define RETURNS 314
#define VAR 315
#define TYPE 316
#define LTE 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "part1.y"

    char *temp;   // Temporary variable for expressions
    char *string; // For identifiers and literals
    char *num;    // For numbers
    struct {
        char *name;
        int size;
    } array;
    int dummy;    // Dummy value for non-value rules

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
  YYSYMBOL_BOOL = 9,                       /* BOOL  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_CHARPTR = 11,                   /* CHARPTR  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_INTPTR = 14,                    /* INTPTR  */
  YYSYMBOL_REAL = 15,                      /* REAL  */
  YYSYMBOL_REALPTR = 16,                   /* REALPTR  */
  YYSYMBOL_ADDRESS = 17,                   /* ADDRESS  */
  YYSYMBOL_ASSIGNMENT = 18,                /* ASSIGNMENT  */
  YYSYMBOL_LENGTH = 19,                    /* LENGTH  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NOTEQ = 22,                     /* NOTEQ  */
  YYSYMBOL_GTE = 23,                       /* GTE  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_LTW = 25,                       /* LTW  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_DIVISION = 29,                  /* DIVISION  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_STAR = 32,                      /* STAR  */
  YYSYMBOL_STR_VAL = 33,                   /* STR_VAL  */
  YYSYMBOL_REAL_VAL = 34,                  /* REAL_VAL  */
  YYSYMBOL_CHAR_VAL = 35,                  /* CHAR_VAL  */
  YYSYMBOL_DEC_VAL = 36,                   /* DEC_VAL  */
  YYSYMBOL_HEX_VAL = 37,                   /* HEX_VAL  */
  YYSYMBOL_NULLL = 38,                     /* NULLL  */
  YYSYMBOL_BTRUE = 39,                     /* BTRUE  */
  YYSYMBOL_BFALSE = 40,                    /* BFALSE  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_LPAREN = 43,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 44,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 45,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 46,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 47,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 48,                    /* RBRACE  */
  YYSYMBOL_BEG = 49,                       /* BEG  */
  YYSYMBOL_END = 50,                       /* END  */
  YYSYMBOL_COLON = 51,                     /* COLON  */
  YYSYMBOL_ARG_ARROW = 52,                 /* ARG_ARROW  */
  YYSYMBOL_VOID = 53,                      /* VOID  */
  YYSYMBOL_FUNCTION = 54,                  /* FUNCTION  */
  YYSYMBOL_MAIN = 55,                      /* MAIN  */
  YYSYMBOL_RETURN = 56,                    /* RETURN  */
  YYSYMBOL_ID = 57,                        /* ID  */
  YYSYMBOL_DEF = 58,                       /* DEF  */
  YYSYMBOL_RETURNS = 59,                   /* RETURNS  */
  YYSYMBOL_VAR = 60,                       /* VAR  */
  YYSYMBOL_TYPE = 61,                      /* TYPE  */
  YYSYMBOL_LTE = 62,                       /* LTE  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_project = 64,                   /* project  */
  YYSYMBOL_program = 65,                   /* program  */
  YYSYMBOL_procedures = 66,                /* procedures  */
  YYSYMBOL_proc = 67,                      /* proc  */
  YYSYMBOL_functype = 68,                  /* functype  */
  YYSYMBOL_params = 69,                    /* params  */
  YYSYMBOL_parameters = 70,                /* parameters  */
  YYSYMBOL_par = 71,                       /* par  */
  YYSYMBOL_body = 72,                      /* body  */
  YYSYMBOL_body_ret = 73,                  /* body_ret  */
  YYSYMBOL_ret = 74,                       /* ret  */
  YYSYMBOL_declartions = 75,               /* declartions  */
  YYSYMBOL_varblock = 76,                  /* varblock  */
  YYSYMBOL_typedecls = 77,                 /* typedecls  */
  YYSYMBOL_typedecl = 78,                  /* typedecl  */
  YYSYMBOL_vardecls = 79,                  /* vardecls  */
  YYSYMBOL_vardecl = 80,                   /* vardecl  */
  YYSYMBOL_str_dec = 81,                   /* str_dec  */
  YYSYMBOL_str_item = 82,                  /* str_item  */
  YYSYMBOL_var_asis = 83,                  /* var_asis  */
  YYSYMBOL_ref = 84,                       /* ref  */
  YYSYMBOL_value = 85,                     /* value  */
  YYSYMBOL_statements = 86,                /* statements  */
  YYSYMBOL_stmnt_block = 87,               /* stmnt_block  */
  YYSYMBOL_statement = 88,                 /* statement  */
  YYSYMBOL_for_declars = 89,               /* for_declars  */
  YYSYMBOL_if = 90,                        /* if  */
  YYSYMBOL_if_else = 91,                   /* if_else  */
  YYSYMBOL_while = 92,                     /* while  */
  YYSYMBOL_do = 93,                        /* do  */
  YYSYMBOL_for = 94,                       /* for  */
  YYSYMBOL_if_block = 95,                  /* if_block  */
  YYSYMBOL_block = 96,                     /* block  */
  YYSYMBOL_assignment = 97,                /* assignment  */
  YYSYMBOL_lhs = 98,                       /* lhs  */
  YYSYMBOL_expr = 99,                      /* expr  */
  YYSYMBOL_expr_list = 100,                /* expr_list  */
  YYSYMBOL_paren_expr = 101,               /* paren_expr  */
  YYSYMBOL_call_func = 102                 /* call_func  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   611

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    85,    87,    88,    92,   100,   108,   118,
     119,   120,   121,   122,   123,   124,   127,   128,   132,   133,
     136,   137,   140,   142,   144,   148,   149,   152,   154,   154,
     156,   157,   160,   160,   162,   165,   170,   170,   172,   173,
     176,   179,   180,   183,   186,   189,   192,   193,   200,   201,
     202,   203,   208,   209,   210,   211,   216,   217,   218,   221,
     222,   225,   226,   227,   228,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   243,   246,   251,   255,   268,   282,
     295,   304,   323,   324,   327,   329,   332,   337,   338,   343,
     350,   351,   356,   361,   366,   371,   376,   381,   393,   405,
     410,   415,   420,   425,   430,   431,   436,   441,   446,   451,
     456,   461,   466,   471,   476,   481,   486,   491,   496,   501,
     525,   529,   532,   535,   537
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
  "FOR", "IF", "ELSE", "BOOL", "STRING", "CHARPTR", "CHAR", "INT",
  "INTPTR", "REAL", "REALPTR", "ADDRESS", "ASSIGNMENT", "LENGTH", "NOT",
  "EQ", "NOTEQ", "GTE", "GT", "LTW", "LT", "AND", "OR", "DIVISION", "PLUS",
  "MINUS", "STAR", "STR_VAL", "REAL_VAL", "CHAR_VAL", "DEC_VAL", "HEX_VAL",
  "NULLL", "BTRUE", "BFALSE", "SEMICOLON", "COMMA", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "BEG", "END", "COLON",
  "ARG_ARROW", "VOID", "FUNCTION", "MAIN", "RETURN", "ID", "DEF",
  "RETURNS", "VAR", "TYPE", "LTE", "$accept", "project", "program",
  "procedures", "proc", "functype", "params", "parameters", "par", "body",
  "body_ret", "ret", "declartions", "varblock", "typedecls", "typedecl",
  "vardecls", "vardecl", "str_dec", "str_item", "var_asis", "ref", "value",
  "statements", "stmnt_block", "statement", "for_declars", "if", "if_else",
  "while", "do", "for", "if_block", "block", "assignment", "lhs", "expr",
  "expr_list", "paren_expr", "call_func", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-222)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-105)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -222,    29,  -222,   -26,  -222,   -27,  -222,    -5,    -2,    71,
      71,   350,    31,    46,    47,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,    37,    43,    93,    59,    40,    51,   350,   -41,
      75,  -222,    64,    78,    51,    79,   350,    80,    40,   200,
      64,  -222,  -222,  -222,    40,    51,  -222,  -222,    81,    83,
    -222,   142,    87,  -222,    95,   101,    96,    98,   105,   554,
     120,   554,   107,   108,   554,   132,    -1,   112,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,   554,    51,    -3,  -222,   188,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,   152,    92,   489,
    -222,  -222,  -222,   126,   134,   141,   133,   -19,  -222,   111,
      36,   212,  -222,    20,   225,   144,   167,  -222,  -222,  -222,
    -222,  -222,   238,   188,   554,   554,   146,  -222,   529,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
    -222,   554,   142,   140,   160,  -222,    96,   565,  -222,    98,
      51,   554,   153,  -222,   192,  -222,  -222,  -222,   554,   111,
     350,   161,   183,   111,   554,  -222,  -222,   154,   262,   159,
     284,  -222,   165,   310,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,    22,   499,   499,    22,  -222,   173,  -222,   171,  -222,
     187,    49,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,   188,   326,   554,   554,   347,  -222,   175,   554,
     554,   222,   368,  -222,   554,  -222,   232,  -222,  -222,  -222,
     207,  -222,  -222,  -222,   -30,  -222,   389,   415,  -222,    -8,
    -222,   431,   476,   220,  -222,  -222,   239,  -222,   223,  -222,
    -222,    69,   175,    44,   111,  -222,  -222,   218,  -222,   235,
     236,  -222,   261,  -222,  -222,   175,   175,   554,  -222,  -222,
     452,   229,   246,   111,   231,  -222
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     3,     1,     0,     4,     0,     0,    16,
      16,     0,     0,    17,     0,     9,    13,    10,    11,    15,
      12,    14,     0,     0,     0,     0,     0,    26,     0,    26,
      21,    19,     0,     0,    26,     0,     0,     0,     0,     0,
      27,    29,     5,    25,     0,    26,     5,    20,     0,     0,
      28,    60,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   108,
     105,   107,   119,   113,   112,     0,    26,   118,    22,    60,
      68,    69,    70,    71,    72,    73,    67,     0,     0,    66,
       8,     5,     7,     0,     0,    37,    35,     0,    33,     0,
     118,     0,   104,    76,     0,   114,     0,   103,   110,   111,
     106,    89,     0,    60,   122,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,    60,     0,     0,    31,     0,     0,    30,     0,
      26,     0,    87,    64,     0,    61,    62,    63,     0,     0,
       0,     0,     0,     0,     0,   116,    90,     0,   121,     0,
       0,   124,     0,     0,    91,    92,    93,    94,    96,    97,
      98,   102,    99,   100,   101,    95,     0,     6,     0,    36,
       0,     0,    48,    53,    49,    50,    52,    58,    56,    57,
      34,    32,    60,     0,     0,     0,     0,    79,     0,     0,
       0,    77,     0,    84,   122,   123,   117,    86,    85,    23,
      39,    54,    55,    51,     0,    24,     0,     0,   117,    45,
      74,     0,    75,     0,   115,   120,     0,    83,     0,    88,
      80,     0,     0,     0,     0,    38,    82,     0,    46,    43,
      44,    41,     0,    78,    47,     0,     0,     0,    42,    40,
       0,     0,     0,     0,     0,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,     7,  -222,   -22,   286,  -222,   -17,   251,
    -222,  -163,     2,  -222,  -222,   258,  -222,   162,   163,  -222,
    -221,  -222,    72,   -40,  -141,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,  -222,   -96,   -95,  -102,   -59,   113,  -222,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    51,     6,    22,    12,    13,    31,    52,
     133,   143,    33,    34,    40,    41,    97,    98,    94,    95,
     220,   239,   190,    78,   144,    79,   151,    80,    81,    82,
      83,    84,   145,    85,    86,    87,    88,   159,   116,   102
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   152,   104,   146,   147,   107,    35,     3,   197,    89,
     231,   241,   201,   209,    45,   -87,   112,    49,    36,    32,
     227,    47,   138,   139,   248,   249,   141,    53,     7,     4,
       8,    37,     5,   109,   232,   110,    43,    89,     9,   117,
     114,    10,   115,   119,   120,   121,   122,    54,   123,   124,
     125,   228,    67,   146,   147,   158,   160,   146,   147,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    89,   175,   157,    11,    23,    67,   142,   113,   114,
     150,   148,   193,   212,   131,   213,   237,    24,    26,   196,
      89,    25,   176,   243,    27,   202,    28,    30,   132,   180,
     181,   142,   182,   183,   184,   185,   186,   187,   188,   189,
      29,    32,   254,   119,   120,   121,   122,    38,   123,   124,
     125,   126,   127,   128,   129,    39,   238,    42,   198,    46,
      44,   242,    56,   130,    57,   216,   217,    90,   146,   147,
     221,   222,   192,    67,    91,   158,    58,    59,    60,    61,
      89,    92,   214,    93,   131,    96,    99,   146,   147,    62,
     140,    63,    64,   103,   105,   106,   108,   141,   142,   111,
     118,   134,    65,    66,    67,   135,    68,    69,    70,    71,
      72,    73,    74,   136,   137,    75,   155,   161,   250,   154,
     177,    76,    58,    59,    60,    61,   178,   195,   194,    77,
       5,   200,   199,   205,   203,    62,   207,    63,    64,    15,
      48,    16,    17,    18,    19,    20,    21,   210,    65,    66,
      67,   211,    68,    69,    70,    71,    72,    73,    74,   141,
     223,    75,   219,   119,   120,   121,   122,    76,   123,   124,
     125,   126,   127,   128,   129,    77,   119,   120,   121,   122,
     -88,   123,   124,   125,   126,   127,   128,   129,   226,   119,
     120,   121,   122,   149,   123,   124,   125,   126,   127,   128,
     129,   234,   235,   236,   131,   244,   153,   245,   246,   247,
     252,   255,   156,   119,   120,   121,   122,   131,   123,   124,
     125,   126,   127,   128,   129,   253,    14,    55,    50,   179,
     131,   191,     0,   240,   204,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,   129,   225,     0,     0,
       0,     0,     0,     0,   131,     0,     0,     0,     0,     0,
     206,   119,   120,   121,   122,     0,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,   131,   119,   120,   121,
     122,   208,   123,   124,   125,   126,   127,   128,   129,    15,
       0,    16,    17,    18,    19,    20,    21,   215,   119,   120,
     121,   122,   131,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   119,
     120,   121,   122,   218,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     119,   120,   121,   122,   224,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,   229,   119,   120,   121,   122,
       0,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,   131,   119,   120,   121,   122,   230,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   119,   120,   121,   122,   131,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,   251,   119,   120,   121,
     122,     0,   123,   124,   125,   126,   127,   128,   129,     0,
    -104,  -104,  -104,  -104,   131,  -104,  -104,  -104,  -104,     0,
     119,   120,   121,   122,     0,   123,   124,   125,   126,     0,
    -104,   129,     0,     0,     0,     0,     0,     0,   131,     0,
       0,     0,     0,     0,     0,     0,    62,     0,    63,    64,
       0,  -104,     0,     0,     0,     0,     0,     0,     0,    65,
      66,   131,   162,    68,    69,    70,    71,    72,    73,    74,
       0,    62,    75,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,   100,     0,    68,    69,
      70,    71,    72,    73,    74,   180,   181,    75,   182,   183,
     184,   185,   186,   187,   188,   189,     0,     0,     0,     0,
       0,   100
};

static const yytype_int16 yycheck[] =
{
      59,   103,    61,    99,    99,    64,    28,     0,   149,    51,
      18,   232,   153,   176,    36,    18,    75,    39,    59,    60,
      50,    38,    41,    42,   245,   246,    56,    44,    55,     0,
      57,    29,    58,    34,    42,    36,    34,    79,    43,    79,
      43,    43,    45,    21,    22,    23,    24,    45,    26,    27,
      28,   214,    32,   149,   149,   114,   115,   153,   153,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   113,   131,   113,     3,    44,    32,    57,    76,    43,
      60,    45,   141,    34,    62,    36,    17,    41,    51,   148,
     132,    44,   132,   234,    51,   154,     3,    57,    91,    30,
      31,    57,    33,    34,    35,    36,    37,    38,    39,    40,
      51,    60,   253,    21,    22,    23,    24,    42,    26,    27,
      28,    29,    30,    31,    32,    61,    57,    49,   150,    49,
      51,   233,    51,    41,    51,   194,   195,    50,   234,   234,
     199,   200,   140,    32,    49,   204,     4,     5,     6,     7,
     192,    50,   192,    57,    62,    57,    51,   253,   253,    17,
      49,    19,    20,    43,    57,    57,    34,    56,    57,    57,
      18,    45,    30,    31,    32,    41,    34,    35,    36,    37,
      38,    39,    40,    42,    51,    43,    19,    41,   247,    45,
      50,    49,     4,     5,     6,     7,    36,     5,    45,    57,
      58,    18,    41,    44,    50,    17,    41,    19,    20,     9,
      10,    11,    12,    13,    14,    15,    16,    46,    30,    31,
      32,    34,    34,    35,    36,    37,    38,    39,    40,    56,
       8,    43,    57,    21,    22,    23,    24,    49,    26,    27,
      28,    29,    30,    31,    32,    57,    21,    22,    23,    24,
      18,    26,    27,    28,    29,    30,    31,    32,    51,    21,
      22,    23,    24,    51,    26,    27,    28,    29,    30,    31,
      32,    51,    33,    50,    62,    57,    51,    42,    42,    18,
      51,    50,    44,    21,    22,    23,    24,    62,    26,    27,
      28,    29,    30,    31,    32,    49,    10,    46,    40,   136,
      62,   139,    -1,   231,    42,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      46,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    62,    21,    22,    23,
      24,    41,    26,    27,    28,    29,    30,    31,    32,     9,
      -1,    11,    12,    13,    14,    15,    16,    41,    21,    22,
      23,    24,    62,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    21,
      22,    23,    24,    46,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      21,    22,    23,    24,    46,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    46,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    62,    21,    22,    23,    24,    41,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    21,    22,    23,    24,    62,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    44,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      21,    22,    23,    24,    62,    26,    27,    28,    29,    -1,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    -1,
      41,    32,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    62,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    17,    43,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    57,    -1,    34,    35,
      36,    37,    38,    39,    40,    30,    31,    43,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,    66,     0,    58,    67,    55,    57,    43,
      43,     3,    69,    70,    69,     9,    11,    12,    13,    14,
      15,    16,    68,    44,    41,    44,    51,    51,     3,    51,
      57,    71,    60,    75,    76,    68,    59,    75,    42,    61,
      77,    78,    49,    75,    51,    68,    49,    71,    10,    68,
      78,    66,    72,    71,    75,    72,    51,    51,     4,     5,
       6,     7,    17,    19,    20,    30,    31,    32,    34,    35,
      36,    37,    38,    39,    40,    43,    49,    57,    86,    88,
      90,    91,    92,    93,    94,    96,    97,    98,    99,   102,
      50,    49,    50,    57,    81,    82,    57,    79,    80,    51,
      57,    99,   102,    43,    99,    57,    57,    99,    34,    34,
      36,    57,    99,    75,    43,    45,   101,    86,    18,    21,
      22,    23,    24,    26,    27,    28,    29,    30,    31,    32,
      41,    62,    66,    73,    45,    41,    42,    51,    41,    42,
      49,    56,    57,    74,    87,    95,    96,    97,    45,    51,
      60,    89,    98,    51,    45,    19,    44,    86,    99,   100,
      99,    41,    33,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    86,    50,    36,    81,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      85,    80,    75,    99,    45,     5,    99,    87,    68,    41,
      18,    87,    99,    50,    42,    44,    46,    41,    41,    74,
      46,    34,    34,    36,    86,    41,    99,    99,    46,    57,
      83,    99,    99,     8,    46,   100,    51,    50,    74,    46,
      41,    18,    42,    41,    51,    33,    50,    17,    57,    84,
      85,    83,    98,    87,    57,    42,    42,    18,    83,    83,
      99,    44,    51,    49,    87,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    73,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    90,    91,    92,
      93,    94,    95,    95,    96,    97,    97,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,    12,    10,    10,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     6,     4,
       3,     1,     2,     3,     3,     2,     0,     2,     2,     1,
       5,     5,     3,     1,     3,     1,     3,     1,     6,     4,
       5,     3,     5,     3,     3,     1,     1,     2,     1,     1,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       0,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     0,     4,     7,     4,
       6,    14,     5,     4,     4,     4,     4,     1,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     2,     1,     1,     1,
       2,     2,     1,     1,     2,     5,     3,     4,     1,     1,
       3,     1,     0,     3,     3
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
#line 83 "part1.y"
                    { YYACCEPT; }
#line 1618 "y.tab.c"
    break;

  case 3: /* program: procedures  */
#line 85 "part1.y"
                       {  }
#line 1624 "y.tab.c"
    break;

  case 4: /* procedures: procedures proc  */
#line 87 "part1.y"
                            { }
#line 1630 "y.tab.c"
    break;

  case 5: /* procedures: %empty  */
#line 88 "part1.y"
              { }
#line 1636 "y.tab.c"
    break;

  case 6: /* proc: DEF ID LPAREN params RPAREN COLON RETURNS functype declartions BEG body_ret END  */
#line 93 "part1.y"
    {
        currentFunc = (yyvsp[-10].string);
        resetCounters();
        genCode("%s:\n", (yyvsp[-10].string));
        genCode("    BeginFunc\n");
        genCode("    EndFunc\n\n");
    }
#line 1648 "y.tab.c"
    break;

  case 7: /* proc: DEF ID LPAREN params RPAREN COLON declartions BEG body END  */
#line 101 "part1.y"
    {
        currentFunc = (yyvsp[-8].string);
        resetCounters();
        genCode("%s:\n", (yyvsp[-8].string));
        genCode("    BeginFunc\n");
        genCode("    EndFunc\n\n");
    }
#line 1660 "y.tab.c"
    break;

  case 8: /* proc: DEF MAIN LPAREN params RPAREN COLON declartions BEG body END  */
#line 109 "part1.y"
    {
        currentFunc = "main";
        resetCounters();
        genCode("main:\n");
        genCode("    BeginFunc\n");
        genCode("    EndFunc\n\n");
    }
#line 1672 "y.tab.c"
    break;

  case 9: /* functype: BOOL  */
#line 118 "part1.y"
                 { }
#line 1678 "y.tab.c"
    break;

  case 10: /* functype: CHAR  */
#line 119 "part1.y"
                   { }
#line 1684 "y.tab.c"
    break;

  case 11: /* functype: INT  */
#line 120 "part1.y"
                  { }
#line 1690 "y.tab.c"
    break;

  case 12: /* functype: REAL  */
#line 121 "part1.y"
                   { }
#line 1696 "y.tab.c"
    break;

  case 13: /* functype: CHARPTR  */
#line 122 "part1.y"
                      { }
#line 1702 "y.tab.c"
    break;

  case 14: /* functype: REALPTR  */
#line 123 "part1.y"
                      { }
#line 1708 "y.tab.c"
    break;

  case 15: /* functype: INTPTR  */
#line 124 "part1.y"
                     { }
#line 1714 "y.tab.c"
    break;

  case 16: /* params: %empty  */
#line 127 "part1.y"
               { }
#line 1720 "y.tab.c"
    break;

  case 17: /* params: parameters  */
#line 128 "part1.y"
                         { }
#line 1726 "y.tab.c"
    break;

  case 18: /* parameters: parameters SEMICOLON ARGS functype COLON par  */
#line 132 "part1.y"
                                                 { }
#line 1732 "y.tab.c"
    break;

  case 19: /* parameters: ARGS functype COLON par  */
#line 133 "part1.y"
                            { }
#line 1738 "y.tab.c"
    break;

  case 20: /* par: ID COMMA par  */
#line 136 "part1.y"
                         { }
#line 1744 "y.tab.c"
    break;

  case 21: /* par: ID  */
#line 137 "part1.y"
                 { }
#line 1750 "y.tab.c"
    break;

  case 22: /* body: procedures statements  */
#line 140 "part1.y"
                                    { }
#line 1756 "y.tab.c"
    break;

  case 23: /* body_ret: procedures statements ret  */
#line 142 "part1.y"
                                        { }
#line 1762 "y.tab.c"
    break;

  case 24: /* ret: RETURN expr SEMICOLON  */
#line 144 "part1.y"
                                   { 
                genCode("    Return %s\n", (yyvsp[-1].temp));
            }
#line 1770 "y.tab.c"
    break;

  case 25: /* declartions: varblock declartions  */
#line 148 "part1.y"
                                  { }
#line 1776 "y.tab.c"
    break;

  case 26: /* declartions: %empty  */
#line 149 "part1.y"
              { }
#line 1782 "y.tab.c"
    break;

  case 27: /* varblock: VAR typedecls  */
#line 152 "part1.y"
                        { }
#line 1788 "y.tab.c"
    break;

  case 28: /* typedecls: typedecls typedecl  */
#line 154 "part1.y"
                              { }
#line 1794 "y.tab.c"
    break;

  case 29: /* typedecls: typedecl  */
#line 154 "part1.y"
                                             { }
#line 1800 "y.tab.c"
    break;

  case 30: /* typedecl: TYPE functype COLON vardecls SEMICOLON  */
#line 156 "part1.y"
                                                  { }
#line 1806 "y.tab.c"
    break;

  case 31: /* typedecl: TYPE STRING COLON str_dec SEMICOLON  */
#line 157 "part1.y"
                                              { }
#line 1812 "y.tab.c"
    break;

  case 32: /* vardecls: vardecls COMMA vardecl  */
#line 160 "part1.y"
                                 { }
#line 1818 "y.tab.c"
    break;

  case 33: /* vardecls: vardecl  */
#line 160 "part1.y"
                                               { }
#line 1824 "y.tab.c"
    break;

  case 34: /* vardecl: ID COLON value  */
#line 162 "part1.y"
                           { 
                genCode("    %s = %s\n", (yyvsp[-2].string), (yyvsp[0].temp));
            }
#line 1832 "y.tab.c"
    break;

  case 35: /* vardecl: ID  */
#line 165 "part1.y"
                 {
                // Declaration without initialization
            }
#line 1840 "y.tab.c"
    break;

  case 36: /* str_dec: str_item COMMA str_dec  */
#line 170 "part1.y"
                                { }
#line 1846 "y.tab.c"
    break;

  case 37: /* str_dec: str_item  */
#line 170 "part1.y"
                                               { }
#line 1852 "y.tab.c"
    break;

  case 38: /* str_item: ID LBRACKET DEC_VAL RBRACKET COLON STR_VAL  */
#line 172 "part1.y"
                                                       { }
#line 1858 "y.tab.c"
    break;

  case 39: /* str_item: ID LBRACKET DEC_VAL RBRACKET  */
#line 173 "part1.y"
                                           { }
#line 1864 "y.tab.c"
    break;

  case 40: /* var_asis: ID ASSIGNMENT value COMMA var_asis  */
#line 176 "part1.y"
                                               { 
                genCode("    %s = %s\n", (yyvsp[-4].string), (yyvsp[-2].temp));
            }
#line 1872 "y.tab.c"
    break;

  case 41: /* var_asis: ID COMMA var_asis  */
#line 179 "part1.y"
                                { }
#line 1878 "y.tab.c"
    break;

  case 42: /* var_asis: ID ASSIGNMENT ref COMMA var_asis  */
#line 180 "part1.y"
                                               { 
                genCode("    %s = %s\n", (yyvsp[-4].string), (yyvsp[-2].string));
            }
#line 1886 "y.tab.c"
    break;

  case 43: /* var_asis: ID ASSIGNMENT ref  */
#line 183 "part1.y"
                                { 
                genCode("    %s = %s\n", (yyvsp[-2].string), (yyvsp[0].string));
            }
#line 1894 "y.tab.c"
    break;

  case 44: /* var_asis: ID ASSIGNMENT value  */
#line 186 "part1.y"
                                  { 
                genCode("    %s = %s\n", (yyvsp[-2].string), (yyvsp[0].temp));
            }
#line 1902 "y.tab.c"
    break;

  case 45: /* var_asis: ID  */
#line 189 "part1.y"
                 { }
#line 1908 "y.tab.c"
    break;

  case 46: /* ref: ID  */
#line 192 "part1.y"
               { (yyval.string) = (yyvsp[0].string); }
#line 1914 "y.tab.c"
    break;

  case 47: /* ref: ADDRESS ID  */
#line 193 "part1.y"
                         { 
                char* temp = newTemp();
                genCode("    %s = &%s\n", temp, (yyvsp[0].string));
                (yyval.string) = temp;
            }
#line 1924 "y.tab.c"
    break;

  case 48: /* value: STR_VAL  */
#line 200 "part1.y"
                    { (yyval.temp) = (yyvsp[0].string); }
#line 1930 "y.tab.c"
    break;

  case 49: /* value: CHAR_VAL  */
#line 201 "part1.y"
                       { (yyval.temp) = (yyvsp[0].string); }
#line 1936 "y.tab.c"
    break;

  case 50: /* value: DEC_VAL  */
#line 202 "part1.y"
                      { (yyval.temp) = (yyvsp[0].string); }
#line 1942 "y.tab.c"
    break;

  case 51: /* value: MINUS DEC_VAL  */
#line 203 "part1.y"
                            { 
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 1952 "y.tab.c"
    break;

  case 52: /* value: HEX_VAL  */
#line 208 "part1.y"
                      { (yyval.temp) = (yyvsp[0].string); }
#line 1958 "y.tab.c"
    break;

  case 53: /* value: REAL_VAL  */
#line 209 "part1.y"
                       { (yyval.temp) = (yyvsp[0].string); }
#line 1964 "y.tab.c"
    break;

  case 54: /* value: PLUS REAL_VAL  */
#line 210 "part1.y"
                            { (yyval.temp) = (yyvsp[0].string); }
#line 1970 "y.tab.c"
    break;

  case 55: /* value: MINUS REAL_VAL  */
#line 211 "part1.y"
                             {
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 1980 "y.tab.c"
    break;

  case 56: /* value: BTRUE  */
#line 216 "part1.y"
                    { (yyval.temp) = "1"; }
#line 1986 "y.tab.c"
    break;

  case 57: /* value: BFALSE  */
#line 217 "part1.y"
                     { (yyval.temp) = "0"; }
#line 1992 "y.tab.c"
    break;

  case 58: /* value: NULLL  */
#line 218 "part1.y"
                    { (yyval.temp) = "0"; }
#line 1998 "y.tab.c"
    break;

  case 59: /* statements: statement statements  */
#line 221 "part1.y"
                                    { }
#line 2004 "y.tab.c"
    break;

  case 60: /* statements: %empty  */
#line 222 "part1.y"
              { }
#line 2010 "y.tab.c"
    break;

  case 61: /* stmnt_block: if_block  */
#line 225 "part1.y"
                         { }
#line 2016 "y.tab.c"
    break;

  case 62: /* stmnt_block: block  */
#line 226 "part1.y"
                        { }
#line 2022 "y.tab.c"
    break;

  case 63: /* stmnt_block: assignment  */
#line 227 "part1.y"
                             { }
#line 2028 "y.tab.c"
    break;

  case 64: /* stmnt_block: ret  */
#line 228 "part1.y"
                      { }
#line 2034 "y.tab.c"
    break;

  case 65: /* statement: expr SEMICOLON  */
#line 231 "part1.y"
                           { }
#line 2040 "y.tab.c"
    break;

  case 66: /* statement: call_func  */
#line 232 "part1.y"
                        { }
#line 2046 "y.tab.c"
    break;

  case 67: /* statement: assignment  */
#line 233 "part1.y"
                         { }
#line 2052 "y.tab.c"
    break;

  case 68: /* statement: if  */
#line 234 "part1.y"
                 { }
#line 2058 "y.tab.c"
    break;

  case 69: /* statement: if_else  */
#line 235 "part1.y"
                      { }
#line 2064 "y.tab.c"
    break;

  case 70: /* statement: while  */
#line 236 "part1.y"
                    { }
#line 2070 "y.tab.c"
    break;

  case 71: /* statement: do  */
#line 237 "part1.y"
                 { }
#line 2076 "y.tab.c"
    break;

  case 72: /* statement: for  */
#line 238 "part1.y"
                  { }
#line 2082 "y.tab.c"
    break;

  case 73: /* statement: block  */
#line 239 "part1.y"
                    { }
#line 2088 "y.tab.c"
    break;

  case 74: /* for_declars: VAR functype var_asis  */
#line 244 "part1.y"
    {
    }
#line 2095 "y.tab.c"
    break;

  case 75: /* for_declars: lhs ASSIGNMENT expr  */
#line 247 "part1.y"
    {
        genCode("    %s = %s\n", (yyvsp[-2].string), (yyvsp[0].temp));
    }
#line 2103 "y.tab.c"
    break;

  case 76: /* for_declars: %empty  */
#line 251 "part1.y"
    {
    }
#line 2110 "y.tab.c"
    break;

  case 77: /* if: IF expr COLON stmnt_block  */
#line 256 "part1.y"
            {
                char* trueLabel = newLabel();
                char* falseLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    if %s Goto %s\n", (yyvsp[-2].temp), trueLabel);
                genCode("    goto %s\n", falseLabel);
                genCode("%s:\n", trueLabel);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", falseLabel);
                genCode("%s:\n", endLabel);
            }
#line 2126 "y.tab.c"
    break;

  case 78: /* if_else: IF expr COLON stmnt_block ELSE COLON stmnt_block  */
#line 269 "part1.y"
            {
                char* trueLabel = newLabel();
                char* falseLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    if %s Goto %s\n", (yyvsp[-5].temp), trueLabel);
                genCode("    goto %s\n", falseLabel);
                genCode("%s:\n", trueLabel);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", falseLabel);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", endLabel);
            }
#line 2143 "y.tab.c"
    break;

  case 79: /* while: WHILE expr COLON stmnt_block  */
#line 283 "part1.y"
            {
                char* startLabel = newLabel();
                char* bodyLabel = newLabel();
                char* endLabel = newLabel();
                genCode("%s:\n", startLabel);
                genCode("    ifFalse %s Goto %s\n", (yyvsp[-2].temp), endLabel);
                genCode("    goto %s\n", bodyLabel);
                genCode("%s:\n", bodyLabel);
                genCode("    goto %s\n", startLabel);
                genCode("%s:\n", endLabel);
            }
#line 2159 "y.tab.c"
    break;

  case 80: /* do: DO COLON stmnt_block WHILE expr SEMICOLON  */
#line 296 "part1.y"
            {
                char* startLabel = newLabel();
                char* endLabel = newLabel();
                genCode("%s:\n", startLabel);
                genCode("    if %s Goto %s\n", (yyvsp[-1].temp), startLabel);
                genCode("%s:\n", endLabel);
            }
#line 2171 "y.tab.c"
    break;

  case 81: /* for: FOR LPAREN for_declars SEMICOLON expr SEMICOLON lhs ASSIGNMENT expr RPAREN COLON BEG stmnt_block END  */
#line 305 "part1.y"
            {
                char* startLabel = newLabel();
                char* bodyLabel = newLabel();
                char* updateLabel = newLabel();
                char* endLabel = newLabel();
                
                genCode("    goto %s\n", updateLabel);
                genCode("%s:\n", startLabel);
                genCode("    ifFalse %s Goto %s\n", (yyvsp[-9].temp), endLabel);
                genCode("    goto %s\n", bodyLabel);
                genCode("%s:\n", bodyLabel);
                genCode("%s:\n", updateLabel);
                genCode("    %s = %s\n", (yyvsp[-7].string), (yyvsp[-5].temp)); 
                genCode("    goto %s\n", startLabel);
                genCode("%s:\n", endLabel);
            }
#line 2192 "y.tab.c"
    break;

  case 82: /* if_block: BEG declartions statements ret END  */
#line 323 "part1.y"
                                                { }
#line 2198 "y.tab.c"
    break;

  case 83: /* if_block: BEG declartions statements END  */
#line 324 "part1.y"
                                             { }
#line 2204 "y.tab.c"
    break;

  case 84: /* block: BEG declartions statements END  */
#line 327 "part1.y"
                                           { }
#line 2210 "y.tab.c"
    break;

  case 85: /* assignment: lhs ASSIGNMENT expr SEMICOLON  */
#line 329 "part1.y"
                                          { 
                genCode("    %s = %s\n", (yyvsp[-3].string), (yyvsp[-1].temp));
            }
#line 2218 "y.tab.c"
    break;

  case 86: /* assignment: lhs ASSIGNMENT STR_VAL SEMICOLON  */
#line 332 "part1.y"
                                               { 
                genCode("    %s = %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
            }
#line 2226 "y.tab.c"
    break;

  case 87: /* lhs: ID  */
#line 337 "part1.y"
               { (yyval.string) = (yyvsp[0].string); }
#line 2232 "y.tab.c"
    break;

  case 88: /* lhs: ID LBRACKET expr RBRACKET  */
#line 338 "part1.y"
                                        { 
                char* temp = newTemp();
                genCode("    %s = %s[%s]\n", temp, (yyvsp[-3].string), (yyvsp[-1].temp));
                (yyval.string) = temp;
            }
#line 2242 "y.tab.c"
    break;

  case 89: /* lhs: STAR ID  */
#line 343 "part1.y"
                      { 
                char* temp = newTemp();
                genCode("    %s = *%s\n", temp, (yyvsp[0].string));
                (yyval.string) = temp;
            }
#line 2252 "y.tab.c"
    break;

  case 90: /* expr: LPAREN expr RPAREN  */
#line 350 "part1.y"
                               { (yyval.temp) = (yyvsp[-1].temp); }
#line 2258 "y.tab.c"
    break;

  case 91: /* expr: expr EQ expr  */
#line 351 "part1.y"
                           { 
                char* temp = newTemp();
                genCode("    %s = %s == %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2268 "y.tab.c"
    break;

  case 92: /* expr: expr NOTEQ expr  */
#line 356 "part1.y"
                              { 
                char* temp = newTemp();
                genCode("    %s = %s != %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2278 "y.tab.c"
    break;

  case 93: /* expr: expr GTE expr  */
#line 361 "part1.y"
                            { 
                char* temp = newTemp();
                genCode("    %s = %s >= %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2288 "y.tab.c"
    break;

  case 94: /* expr: expr GT expr  */
#line 366 "part1.y"
                           { 
                char* temp = newTemp();
                genCode("    %s = %s > %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2298 "y.tab.c"
    break;

  case 95: /* expr: expr LTE expr  */
#line 371 "part1.y"
                            { 
                char* temp = newTemp();
                genCode("    %s = %s <= %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2308 "y.tab.c"
    break;

  case 96: /* expr: expr LT expr  */
#line 376 "part1.y"
                           { 
                char* temp = newTemp();
                genCode("    %s = %s < %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2318 "y.tab.c"
    break;

  case 97: /* expr: expr AND expr  */
#line 381 "part1.y"
                            { 
                char* temp = newTemp();
                char* falseLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    ifFalse %s Goto %s\n", (yyvsp[-2].temp), falseLabel);
                genCode("    %s = %s\n", temp, (yyvsp[0].temp));
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", falseLabel);
                genCode("    %s = 0\n", temp);
                genCode("%s:\n", endLabel);
                (yyval.temp) = temp;
            }
#line 2335 "y.tab.c"
    break;

  case 98: /* expr: expr OR expr  */
#line 393 "part1.y"
                           { 
                char* temp = newTemp();
                char* trueLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    ifTrue %s Goto %s\n", (yyvsp[-2].temp), trueLabel);
                genCode("    %s = %s\n", temp, (yyvsp[0].temp));
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", trueLabel);
                genCode("    %s = 1\n", temp);
                genCode("%s:\n", endLabel);
                (yyval.temp) = temp;
            }
#line 2352 "y.tab.c"
    break;

  case 99: /* expr: expr PLUS expr  */
#line 405 "part1.y"
                             { 
                char* temp = newTemp();
                genCode("    %s = %s + %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2362 "y.tab.c"
    break;

  case 100: /* expr: expr MINUS expr  */
#line 410 "part1.y"
                              { 
                char* temp = newTemp();
                genCode("    %s = %s - %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2372 "y.tab.c"
    break;

  case 101: /* expr: expr STAR expr  */
#line 415 "part1.y"
                             { 
                char* temp = newTemp();
                genCode("    %s = %s * %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2382 "y.tab.c"
    break;

  case 102: /* expr: expr DIVISION expr  */
#line 420 "part1.y"
                                 { 
                char* temp = newTemp();
                genCode("    %s = %s / %s\n", temp, (yyvsp[-2].temp), (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2392 "y.tab.c"
    break;

  case 103: /* expr: NOT expr  */
#line 425 "part1.y"
                       { 
                char* temp = newTemp();
                genCode("    %s = !%s\n", temp, (yyvsp[0].temp));
                (yyval.temp) = temp;
            }
#line 2402 "y.tab.c"
    break;

  case 104: /* expr: call_func  */
#line 430 "part1.y"
                        { (yyval.temp) = (yyvsp[0].temp); }
#line 2408 "y.tab.c"
    break;

  case 105: /* expr: DEC_VAL  */
#line 431 "part1.y"
                      { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2418 "y.tab.c"
    break;

  case 106: /* expr: MINUS DEC_VAL  */
#line 436 "part1.y"
                            { 
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2428 "y.tab.c"
    break;

  case 107: /* expr: HEX_VAL  */
#line 441 "part1.y"
                      { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2438 "y.tab.c"
    break;

  case 108: /* expr: CHAR_VAL  */
#line 446 "part1.y"
                       { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2448 "y.tab.c"
    break;

  case 109: /* expr: REAL_VAL  */
#line 451 "part1.y"
                       { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2458 "y.tab.c"
    break;

  case 110: /* expr: PLUS REAL_VAL  */
#line 456 "part1.y"
                            { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2468 "y.tab.c"
    break;

  case 111: /* expr: MINUS REAL_VAL  */
#line 461 "part1.y"
                             {
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2478 "y.tab.c"
    break;

  case 112: /* expr: BFALSE  */
#line 466 "part1.y"
                     { 
                char* temp = newTemp();
                genCode("    %s = 0\n", temp);
                (yyval.temp) = temp;
            }
#line 2488 "y.tab.c"
    break;

  case 113: /* expr: BTRUE  */
#line 471 "part1.y"
                    { 
                char* temp = newTemp();
                genCode("    %s = 1\n", temp);
                (yyval.temp) = temp;
            }
#line 2498 "y.tab.c"
    break;

  case 114: /* expr: ADDRESS ID  */
#line 476 "part1.y"
                         { 
                char* temp = newTemp();
                genCode("    %s = &%s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2508 "y.tab.c"
    break;

  case 115: /* expr: ADDRESS ID LBRACKET expr RBRACKET  */
#line 481 "part1.y"
                                                {
                char* temp = newTemp();
                genCode("    %s = &%s[%s]\n", temp, (yyvsp[-3].string), (yyvsp[-1].temp));
                (yyval.temp) = temp;
            }
#line 2518 "y.tab.c"
    break;

  case 116: /* expr: LENGTH ID LENGTH  */
#line 486 "part1.y"
                               {
                char* temp = newTemp();
                genCode("    %s = sizeof(%s)\n", temp, (yyvsp[-1].string));
                (yyval.temp) = temp;
            }
#line 2528 "y.tab.c"
    break;

  case 117: /* expr: ID LBRACKET expr RBRACKET  */
#line 491 "part1.y"
                                        {
                char* temp = newTemp();
                genCode("    %s = %s[%s]\n", temp, (yyvsp[-3].string), (yyvsp[-1].temp));
                (yyval.temp) = temp;
            }
#line 2538 "y.tab.c"
    break;

  case 118: /* expr: ID  */
#line 496 "part1.y"
                 { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, (yyvsp[0].string));
                (yyval.temp) = temp;
            }
#line 2548 "y.tab.c"
    break;

  case 119: /* expr: NULLL  */
#line 501 "part1.y"
                    { 
                char* temp = newTemp();
                genCode("    %s = 0\n", temp);
                (yyval.temp) = temp;
            }
#line 2558 "y.tab.c"
    break;

  case 120: /* expr_list: expr COMMA expr_list  */
#line 525 "part1.y"
                                   { 

                genCode("    PushParam %s\n", (yyvsp[-2].temp));
            }
#line 2567 "y.tab.c"
    break;

  case 121: /* expr_list: expr  */
#line 529 "part1.y"
                   { 
                genCode("    PushParam %s\n", (yyvsp[0].temp));
            }
#line 2575 "y.tab.c"
    break;

  case 122: /* expr_list: %empty  */
#line 532 "part1.y"
              { }
#line 2581 "y.tab.c"
    break;

  case 123: /* paren_expr: LPAREN expr_list RPAREN  */
#line 535 "part1.y"
                                       { }
#line 2587 "y.tab.c"
    break;

  case 124: /* call_func: ID paren_expr SEMICOLON  */
#line 537 "part1.y"
                                   { 
                char* temp = newTemp();
                genCode("    %s = LCall %s\n", temp, (yyvsp[-2].string));
                genCode("    PopParams\n");
                (yyval.temp) = temp;
            }
#line 2598 "y.tab.c"
    break;


#line 2602 "y.tab.c"

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

#line 544 "part1.y"

char* newTemp() {
    char* name = malloc(10);
    sprintf(name, "t%d", tempCount++);
    return name;
}

char* newLabel() {
    char* name = malloc(10);
    sprintf(name, "L%d", labelCount++);
    return name;
}

void resetCounters() {
    tempCount = 0;
    labelCount = 0;
}

void genCode(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}


node* mknode(char* token, node *left,node *right) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->left=left;
    newnode->right=right;
    newnode->token=token;
    return newnode;
}

void printTree(node* tree) {
}

int yyerror(char *e) {
    int yydebug=1;
    fflush(stdout);
    fprintf(stderr, "Error: %s at line %d\n" ,e, yylineno);
    fprintf(stderr, "does not accept '%s'\n", yytext);
    return 0;
}

int main() {
    yyparse();
    return 0;
}
