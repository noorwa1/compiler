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
#define MAX_FUNCS 100
#define MAX_Var 100
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
void register_func(char* name);
bool func_exists(char* name);
void register_var(char* name);
bool var_exists(char* name);
int openParenthesis = 0;
int pauselevel = 0;
int main_defined = 0;
int hadOperator = 0;
int currentTab = 0;
int yylex();
int yyerror(char *e);

int isBooleanExpression(char* token);
void validate_array_index(char* val);
char* defined_funcs[MAX_FUNCS];
int func_count = 0;
void clear_var_scope();
int var_count = 0;
char* defined_vars[MAX_Var];
int parm_num=1;

#line 122 "y.tab.c"

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
#line 53 "part1.y"

    struct node *node;
    char *string;
	char* num;

#line 305 "y.tab.c"

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
  YYSYMBOL_for_declars = 81,               /* for_declars  */
  YYSYMBOL_str_dec = 82,                   /* str_dec  */
  YYSYMBOL_str_item = 83,                  /* str_item  */
  YYSYMBOL_var_asis = 84,                  /* var_asis  */
  YYSYMBOL_ref = 85,                       /* ref  */
  YYSYMBOL_value = 86,                     /* value  */
  YYSYMBOL_statements = 87,                /* statements  */
  YYSYMBOL_stmnt_block = 88,               /* stmnt_block  */
  YYSYMBOL_statement = 89,                 /* statement  */
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
  YYSYMBOL_derefrence_expr = 100,          /* derefrence_expr  */
  YYSYMBOL_expr_list = 101,                /* expr_list  */
  YYSYMBOL_paren_expr = 102,               /* paren_expr  */
  YYSYMBOL_call_func = 103                 /* call_func  */
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
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  267

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
       0,    90,    90,    92,    94,    95,   100,   122,   145,   172,
     173,   174,   175,   176,   177,   178,   181,   182,   186,   199,
     213,   214,   217,   222,   227,   231,   232,   236,   239,   240,
     244,   245,   251,   252,   255,   263,   280,   281,   282,   285,
     286,   290,   303,   319,   320,   322,   323,   324,   325,   327,
     328,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   344,   345,   349,   350,   351,   352,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   366,   375,   388,
     399,   407,   420,   425,   430,   431,   434,   435,   436,   440,
     442,   443,   444,   445,   446,   447,   448,   449,   451,   452,
     453,   454,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   473,   479,   481,   482,
     485,   486,   487,   492,   493,   494,   496,   498
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
  "vardecls", "vardecl", "for_declars", "str_dec", "str_item", "var_asis",
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

#define YYPACT_NINF (-225)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-105)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -225,    25,  -225,   -17,  -225,   -31,  -225,   -12,    13,    76,
      76,   175,    42,    50,    59,  -225,  -225,  -225,  -225,  -225,
    -225,  -225,    55,    80,   107,    81,    67,    68,   175,   -25,
      86,  -225,   175,    82,   175,    78,    91,    89,    67,    92,
      67,    89,   162,    78,  -225,  -225,  -225,  -225,  -225,  -225,
      97,   100,   101,  -225,    77,   103,    77,   105,  -225,    99,
     102,   106,   597,   117,   597,   108,   109,   597,   128,    -6,
     -21,  -225,  -225,  -225,  -225,  -225,  -225,  -225,   597,    89,
       9,  -225,   163,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
     161,   187,  -225,   525,  -225,   125,  -225,   135,   147,   164,
     165,   153,    57,  -225,    73,    45,    44,   203,  -225,    61,
     215,   176,   204,  -225,  -225,  -225,  -225,   597,     3,   229,
     163,   597,   597,   181,  -225,   569,   597,   597,   597,   597,
     597,   597,   597,   597,   597,   597,   597,  -225,   597,   597,
    -225,  -225,   212,  -225,    99,   542,  -225,   102,   183,    89,
     217,  -225,   258,  -225,  -225,  -225,   219,   597,    73,   175,
     226,   250,    73,   597,  -225,   257,   597,  -225,   220,   276,
     225,   299,  -225,   230,   325,  -225,  -225,  -225,  -225,  -225,
    -225,  -225,    23,   535,   535,    23,  -225,   341,   228,  -225,
     238,    56,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,  -225,  -225,   163,   597,   597,   362,  -225,   218,   597,
     597,   268,   383,  -225,   404,  -225,   597,  -225,   264,  -225,
    -225,  -225,   239,  -225,  -225,  -225,   -27,   425,   451,  -225,
      -3,  -225,   467,   512,   241,  -225,  -225,  -225,   260,   244,
    -225,  -225,   608,   218,   -14,    73,  -225,  -225,   252,  -225,
     253,   254,  -225,   292,  -225,  -225,   218,   218,   597,  -225,
    -225,   488,   261,   262,    73,   263,  -225
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     3,     1,     0,     4,     0,     0,    17,
      17,     0,     0,    16,     0,     9,    13,    10,    11,    15,
      12,    14,     0,     0,     0,     0,     0,     0,     0,    26,
      21,    19,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    26,     0,    27,    29,     5,    25,    20,     5,    18,
       0,     0,     0,    28,    63,     0,    63,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   108,   105,   107,   119,   113,   112,     0,    26,
     118,    22,    63,    71,    72,    73,    74,    75,    76,    70,
       0,     0,   103,    69,     7,     0,     8,     0,     0,     0,
      40,    35,     0,    33,     0,     0,   118,     0,   104,    38,
       0,   114,     0,   102,   110,   111,   106,     0,   120,     0,
      63,   125,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,     0,
      23,     6,     0,    31,     0,     0,    30,     0,     0,    26,
      86,    67,     0,    64,    65,    66,   120,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,    89,     0,   124,
       0,     0,   127,     0,     0,    90,    91,    92,    93,    95,
      96,    97,   101,    98,    99,   100,    94,     0,     0,    39,
       0,     0,    51,    56,    52,    53,    55,    61,    59,    60,
      34,    32,    88,    63,     0,     0,     0,    79,     0,     0,
       0,    77,     0,   121,     0,    83,   125,   126,   117,    85,
      84,    24,    42,    57,    58,    54,     0,     0,     0,   117,
      48,    36,     0,    37,     0,   115,   122,   123,     0,     0,
      87,    80,     0,     0,     0,     0,    41,    82,     0,    49,
      46,    47,    44,     0,    78,    50,     0,     0,     0,    45,
      43,     0,     0,     0,     0,     0,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -225,  -225,  -225,     8,  -225,   -22,   304,  -225,    85,  -225,
     259,   -88,     1,  -225,  -225,   272,  -225,   169,  -225,   180,
    -225,  -224,  -225,    90,   -42,  -145,  -225,  -225,  -225,  -225,
    -225,  -225,  -225,  -101,  -100,  -108,   -62,  -225,   118,  -225,
     -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    56,     6,    22,    12,    13,    31,    55,
      57,   151,    36,    37,    43,    44,   102,   103,   160,    99,
     100,   231,   250,   200,    81,   152,    82,    83,    84,    85,
      86,    87,   153,    88,    89,    90,    91,    92,   170,   123,
     108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   161,   110,   154,   155,   113,    33,   140,     3,    93,
      39,    93,    41,   207,    95,   242,   119,   211,   148,   252,
      52,   -88,   117,   215,     7,     4,     8,   -86,   115,   139,
     116,     9,   259,   260,    34,    35,   118,    93,    46,   243,
     124,     5,    50,   150,   126,   127,   128,   129,   166,   130,
     131,   132,   121,    54,   122,   165,    10,   154,   155,   169,
     171,   154,   155,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    93,   186,   187,   168,    11,
     120,    61,    62,    63,    64,   138,    23,   121,   117,   157,
     224,    24,   225,   148,    65,   206,    66,    67,   146,   147,
     254,   212,   156,    25,   214,   148,    26,    68,    69,    70,
      28,    71,    72,    73,    74,    75,    76,    77,   150,   265,
      78,   159,   149,    47,    30,    49,    79,    32,    38,   139,
     150,    27,    29,    40,    80,     5,   253,   208,   239,    42,
      45,    48,   227,   228,   154,   155,    58,   232,   233,    35,
     203,    59,    60,    94,   169,    96,    98,   104,    93,   101,
     109,   226,   114,   154,   155,   111,   112,    61,    62,    63,
      64,    15,    51,    16,    17,    18,    19,    20,    21,   125,
      65,   139,    66,    67,    15,   141,    16,    17,    18,    19,
      20,    21,   142,    68,    69,    70,   261,    71,    72,    73,
      74,    75,    76,    77,   145,   143,    78,   144,   126,   127,
     128,   129,    79,   130,   131,   132,   133,   134,   135,   136,
      80,   163,   172,   164,   126,   127,   128,   129,   137,   130,
     131,   132,   133,   134,   135,   136,   126,   127,   128,   129,
     202,   130,   131,   132,   133,   134,   135,   136,   188,   138,
     126,   127,   128,   129,   158,   130,   131,   132,   133,   134,
     135,   136,   204,   205,   166,   138,   162,   209,   210,   217,
     215,   219,   223,   167,   222,   230,   234,   138,   126,   127,
     128,   129,   -87,   130,   131,   132,   133,   134,   135,   136,
     238,   138,   245,   246,   247,   256,   257,   126,   127,   128,
     129,   213,   130,   131,   132,   133,   134,   135,   136,   255,
     258,   264,   263,   266,    14,    53,   201,    97,   216,   138,
     126,   127,   128,   129,   189,   130,   131,   132,   133,   134,
     135,   136,   251,     0,   237,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,   218,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,   138,   126,   127,   128,   129,   220,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,   221,   126,   127,   128,   129,   138,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   126,   127,   128,   129,   229,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   126,   127,   128,   129,   235,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   126,   127,   128,   129,
     236,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,   138,     0,     0,     0,
       0,   240,   126,   127,   128,   129,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   138,   126,   127,
     128,   129,   241,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   126,
     127,   128,   129,   138,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,   262,   126,   127,   128,   129,     0,   130,   131,
     132,   133,   134,   135,   136,     0,  -104,  -104,  -104,  -104,
     138,  -104,  -104,  -104,  -104,     0,   126,   127,   128,   129,
       0,   130,   131,   132,   133,     0,  -104,   136,     0,     0,
       0,     0,   190,   191,   138,   192,   193,   194,   195,   196,
     197,   198,   199,     0,     0,     0,    65,  -104,    66,    67,
       0,     0,     0,     0,     0,     0,     0,   138,     0,    68,
      69,   105,   173,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,     0,    65,     0,    66,    67,     0,     0,
       0,     0,     0,     0,     0,   248,   106,    68,    69,   105,
       0,    71,    72,    73,    74,    75,    76,    77,   190,   191,
      78,   192,   193,   194,   195,   196,   197,   198,   199,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249
};

static const yytype_int16 yycheck[] =
{
      62,   109,    64,   104,   104,    67,    28,    95,     0,    54,
      32,    56,    34,   158,    56,    18,    78,   162,    32,   243,
      42,    18,    43,    50,    55,     0,    57,    18,    34,    56,
      36,    43,   256,   257,    59,    60,    57,    82,    37,    42,
      82,    58,    41,    57,    21,    22,    23,    24,    45,    26,
      27,    28,    43,    45,    45,   117,    43,   158,   158,   121,
     122,   162,   162,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   120,   138,   139,   120,     3,
      79,     4,     5,     6,     7,    62,    44,    43,    43,    45,
      34,    41,    36,    32,    17,   157,    19,    20,    41,    42,
     245,   163,    57,    44,   166,    32,    51,    30,    31,    32,
       3,    34,    35,    36,    37,    38,    39,    40,    57,   264,
      43,    60,    49,    38,    57,    40,    49,    59,    42,    56,
      57,    51,    51,    51,    57,    58,   244,   159,   226,    61,
      49,    49,   204,   205,   245,   245,    49,   209,   210,    60,
     149,    51,    51,    50,   216,    50,    57,    51,   203,    57,
      43,   203,    34,   264,   264,    57,    57,     4,     5,     6,
       7,     9,    10,    11,    12,    13,    14,    15,    16,    18,
      17,    56,    19,    20,     9,    50,    11,    12,    13,    14,
      15,    16,    45,    30,    31,    32,   258,    34,    35,    36,
      37,    38,    39,    40,    51,    41,    43,    42,    21,    22,
      23,    24,    49,    26,    27,    28,    29,    30,    31,    32,
      57,    45,    41,    19,    21,    22,    23,    24,    41,    26,
      27,    28,    29,    30,    31,    32,    21,    22,    23,    24,
      57,    26,    27,    28,    29,    30,    31,    32,    36,    62,
      21,    22,    23,    24,    51,    26,    27,    28,    29,    30,
      31,    32,    45,     5,    45,    62,    51,    41,    18,    44,
      50,    41,    34,    44,    46,    57,     8,    62,    21,    22,
      23,    24,    18,    26,    27,    28,    29,    30,    31,    32,
      51,    62,    51,    33,    50,    42,    42,    21,    22,    23,
      24,    44,    26,    27,    28,    29,    30,    31,    32,    57,
      18,    49,    51,    50,    10,    43,   147,    58,    42,    62,
      21,    22,    23,    24,   144,    26,    27,    28,    29,    30,
      31,    32,   242,    -1,   216,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    62,    21,    22,    23,    24,    41,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    21,    22,    23,    24,    62,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    21,    22,    23,    24,    46,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    21,    22,    23,    24,    46,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    21,    22,    23,    24,
      46,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    46,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    62,    21,    22,
      23,    24,    41,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    21,
      22,    23,    24,    62,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    44,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    21,    22,    23,    24,
      62,    26,    27,    28,    29,    -1,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    -1,    41,    32,    -1,    -1,
      -1,    -1,    30,    31,    62,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    17,    62,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    -1,    17,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    57,    30,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    30,    31,
      43,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,    66,     0,    58,    67,    55,    57,    43,
      43,     3,    69,    70,    69,     9,    11,    12,    13,    14,
      15,    16,    68,    44,    41,    44,    51,    51,     3,    51,
      57,    71,    59,    68,    59,    60,    75,    76,    42,    68,
      51,    68,    61,    77,    78,    49,    75,    71,    49,    71,
      75,    10,    68,    78,    66,    72,    66,    73,    49,    51,
      51,     4,     5,     6,     7,    17,    19,    20,    30,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    43,    49,
      57,    87,    89,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   100,   103,    50,    87,    50,    73,    57,    82,
      83,    57,    79,    80,    51,    32,    57,    99,   103,    43,
      99,    57,    57,    99,    34,    34,    36,    43,    57,    99,
      75,    43,    45,   102,    87,    18,    21,    22,    23,    24,
      26,    27,    28,    29,    30,    31,    32,    41,    62,    56,
      74,    50,    45,    41,    42,    51,    41,    42,    32,    49,
      57,    74,    88,    95,    96,    97,    57,    45,    51,    60,
      81,    98,    51,    45,    19,    99,    45,    44,    87,    99,
     101,    99,    41,    33,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    36,    82,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      86,    80,    57,    75,    45,     5,    99,    88,    68,    41,
      18,    88,    99,    44,    99,    50,    42,    44,    46,    41,
      41,    41,    46,    34,    34,    36,    87,    99,    99,    46,
      57,    84,    99,    99,     8,    46,    46,   101,    51,    74,
      46,    41,    18,    42,    41,    51,    33,    50,    17,    57,
      85,    86,    84,    98,    88,    57,    42,    42,    18,    84,
      84,    99,    44,    51,    49,    88,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    73,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    97,    98,    98,    98,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   101,   101,   102,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,    12,    10,    11,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     4,
       3,     1,     2,     3,     3,     2,     0,     2,     2,     1,
       5,     5,     3,     1,     3,     1,     3,     3,     0,     3,
       1,     6,     4,     5,     3,     5,     3,     3,     1,     1,
       2,     1,     1,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     2,     0,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     7,     4,
       6,    14,     5,     4,     4,     4,     1,     4,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     1,     1,     2,     5,     3,     4,     1,     1,
       2,     4,     5,     3,     1,     0,     3,     3
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
#line 90 "part1.y"
                    {printTree((yyvsp[0].node));}
#line 1646 "y.tab.c"
    break;

  case 3: /* program: procedures  */
#line 92 "part1.y"
                       {(yyval.node)=mknode("CODE ",(yyvsp[0].node),NULL);}
#line 1652 "y.tab.c"
    break;

  case 4: /* procedures: procedures proc  */
#line 94 "part1.y"
                            {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1658 "y.tab.c"
    break;

  case 5: /* procedures: %empty  */
#line 95 "part1.y"
                          {(yyval.node)=NULL;}
#line 1664 "y.tab.c"
    break;

  case 6: /* proc: DEF ID LPAREN params RPAREN COLON RETURNS functype declartions BEG body_ret END  */
#line 101 "part1.y"
    {
		parm_num=1;
		clear_var_scope();
        if (func_exists((yyvsp[-10].string))) {
            yyerror("Error: Function name already defined.");
            YYABORT;
        }
        register_func((yyvsp[-10].string));

        (yyval.node) = mknode("(FUNC\n\t ",
                    mknode((yyvsp[-10].string),
                           mknode("\n",
                                  mknode("\t\t(PARS\n ", (yyvsp[-8].node), NULL),
                                  mknode("\n\t\t(RET ", (yyvsp[-4].node),
                                         mknode("\n\t\t(DECLS\n", (yyvsp[-3].node), NULL))
                           ),
                           NULL
                    ),
                    (yyvsp[-1].node));
    }
#line 1689 "y.tab.c"
    break;

  case 7: /* proc: DEF ID LPAREN params RPAREN COLON declartions BEG body END  */
#line 123 "part1.y"
    {
		parm_num=1;
		clear_var_scope();
        if (func_exists((yyvsp[-8].string))) {
            yyerror("Error: Function name already defined.");
            YYABORT;
        }
        register_func((yyvsp[-8].string));

        (yyval.node) = mknode("(FUNC\n\t ",
                    mknode((yyvsp[-8].string),
                           mknode("\n",
                                  mknode("\t\t(PARS\n\t ", (yyvsp[-6].node), NULL),
                                  mknode("\n\t\t(RET ",
                                         mknode("\n\t\t(DECLS\n", (yyvsp[-3].node), NULL),
                                         NULL)
                           ),
                           NULL
                    ),
                    mknode(")\n", (yyvsp[-1].node), NULL));
    }
#line 1715 "y.tab.c"
    break;

  case 8: /* proc: DEF MAIN LPAREN params RPAREN COLON RETURNS functype BEG body_ret END  */
#line 146 "part1.y"
    {
        if (main_defined) {
            yyerror("Error: Multiple 'main' functions are not allowed.");
            yyerror((yyvsp[-9].string));
            YYABORT;
        }
        if (main_defined && (yyvsp[-7].node) != NULL) {
            yyerror("Main function does not accept parameters!");
            YYABORT;
        }
        main_defined = 1;

        (yyval.node) = mknode("(FUNC\n\t ",
                    mknode((yyvsp[-9].string),
                           mknode("\n",
                                  mknode("\n\t\t(None\n ", NULL, NULL),
                                  mknode("\n\t\t(RET ", (yyvsp[-3].node), NULL)
                           ),
                           NULL
                    ),
                    mknode(")\n", (yyvsp[-1].node), NULL));
    }
#line 1742 "y.tab.c"
    break;

  case 9: /* functype: BOOL  */
#line 172 "part1.y"
                 {(yyval.node)=mknode(" BOOL ",NULL,NULL);}
#line 1748 "y.tab.c"
    break;

  case 10: /* functype: CHAR  */
#line 173 "part1.y"
                               {(yyval.node)=mknode(" CHAR ",NULL,NULL);}
#line 1754 "y.tab.c"
    break;

  case 11: /* functype: INT  */
#line 174 "part1.y"
                  {(yyval.node)=mknode(" INT ",NULL,NULL);}
#line 1760 "y.tab.c"
    break;

  case 12: /* functype: REAL  */
#line 175 "part1.y"
                   {(yyval.node)=mknode(" REAL ",NULL,NULL);}
#line 1766 "y.tab.c"
    break;

  case 13: /* functype: CHARPTR  */
#line 176 "part1.y"
                                  {(yyval.node)=mknode(" CHAR* ",NULL,NULL);}
#line 1772 "y.tab.c"
    break;

  case 14: /* functype: REALPTR  */
#line 177 "part1.y"
                                  {(yyval.node)=mknode(" REAL* ",NULL,NULL);}
#line 1778 "y.tab.c"
    break;

  case 15: /* functype: INTPTR  */
#line 178 "part1.y"
                                 {(yyval.node)=mknode(" INT* ",NULL,NULL);}
#line 1784 "y.tab.c"
    break;

  case 16: /* params: parameters  */
#line 181 "part1.y"
                           {(yyval.node)= mknode("PARAMLIST\n",(yyvsp[0].node),NULL);}
#line 1790 "y.tab.c"
    break;

  case 17: /* params: %empty  */
#line 182 "part1.y"
                          {(yyval.node)=mknode("NONE",NULL,NULL);}
#line 1796 "y.tab.c"
    break;

  case 18: /* parameters: parameters SEMICOLON ARGS functype COLON par  */
#line 186 "part1.y"
                                                 {
        if (atoi(&(yyvsp[-3].num)[3]) != parm_num) {
            printf("Error: Expected par%d but got %s\n", parm_num, (yyvsp[-3].num));
            yyerror("Parameter order mismatch.");
            YYABORT;
        }
        printf("  %d      %d\n", parm_num, atoi(&(yyvsp[-3].num)[3]));
        parm_num++;

        (yyval.node) = mknode("",
                    (yyvsp[-5].node),
                    mknode(" (", mknode((yyvsp[-3].num), (yyvsp[-2].node), (yyvsp[0].node)), mknode(" )\n", NULL, NULL)));
    }
#line 1814 "y.tab.c"
    break;

  case 19: /* parameters: ARGS functype COLON par  */
#line 199 "part1.y"
                            {
        if (atoi(&(yyvsp[-3].num)[3]) != parm_num) {
            printf("Error: Expected par%d but got %s\n", parm_num, (yyvsp[-3].num));
            yyerror("Parameter order mismatch.");
            YYABORT;
        }
        printf("  %d      %d\n", parm_num, atoi(&(yyvsp[-3].num)[3]));
        parm_num++;

        (yyval.node) = mknode(" (", mknode((yyvsp[-3].num), (yyvsp[-2].node), (yyvsp[0].node)), mknode(" )\n", NULL, NULL));
    }
#line 1830 "y.tab.c"
    break;

  case 20: /* par: ID COMMA par  */
#line 213 "part1.y"
                             {(yyval.node)=mknode((yyvsp[-2].string),mknode(" ",(yyvsp[0].node),NULL),NULL);}
#line 1836 "y.tab.c"
    break;

  case 21: /* par: ID  */
#line 214 "part1.y"
                             {(yyval.node)=mknode((yyvsp[0].string), NULL, NULL);}
#line 1842 "y.tab.c"
    break;

  case 22: /* body: procedures statements  */
#line 218 "part1.y"
{
			(yyval.node)=mknode("body ",mknode("",(yyvsp[-1].node),NULL),mknode("",(yyvsp[0].node),mknode("}",NULL,NULL)));
}
#line 1850 "y.tab.c"
    break;

  case 23: /* body_ret: procedures statements ret  */
#line 223 "part1.y"
{
			(yyval.node)=mknode("body ",mknode("",(yyvsp[-2].node),NULL),mknode("",(yyvsp[-1].node),mknode("}",NULL,NULL)));
}
#line 1858 "y.tab.c"
    break;

  case 24: /* ret: RETURN expr SEMICOLON  */
#line 227 "part1.y"
                                      {(yyval.node)=mknode("return",(yyvsp[-1].node),NULL);}
#line 1864 "y.tab.c"
    break;

  case 25: /* declartions: varblock declartions  */
#line 231 "part1.y"
                                  {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1870 "y.tab.c"
    break;

  case 26: /* declartions: %empty  */
#line 232 "part1.y"
                         {(yyval.node)=NULL;}
#line 1876 "y.tab.c"
    break;

  case 27: /* varblock: VAR typedecls  */
#line 236 "part1.y"
                       { (yyval.node) = mknode("DECLARE_BLOCK\n\t\t\t", (yyvsp[0].node), NULL); }
#line 1882 "y.tab.c"
    break;

  case 28: /* typedecls: typedecls typedecl  */
#line 239 "part1.y"
                                { (yyval.node) = mknode("TYPELIST\n\t\t\t", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1888 "y.tab.c"
    break;

  case 29: /* typedecls: typedecl  */
#line 240 "part1.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1894 "y.tab.c"
    break;

  case 30: /* typedecl: TYPE functype COLON vardecls SEMICOLON  */
#line 244 "part1.y"
                                            { (yyval.node) = mknode("TYPE", mknode((yyvsp[-3].node)->token, (yyvsp[-1].node), NULL), NULL); }
#line 1900 "y.tab.c"
    break;

  case 31: /* typedecl: TYPE STRING COLON str_dec SEMICOLON  */
#line 245 "part1.y"
                                              {
        (yyval.node) = mknode("TYPE", mknode("string", (yyvsp[-1].node), NULL), NULL);
      }
#line 1908 "y.tab.c"
    break;

  case 32: /* vardecls: vardecls COMMA vardecl  */
#line 251 "part1.y"
                                { (yyval.node) = mknode("VARLIST", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1914 "y.tab.c"
    break;

  case 33: /* vardecls: vardecl  */
#line 252 "part1.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1920 "y.tab.c"
    break;

  case 34: /* vardecl: ID COLON value  */
#line 255 "part1.y"
                                  { 
		if (var_exists((yyvsp[-2].string))){
			yyerror("two variables have the same name in the scope! $17\n");
			YYABORT;
		}		
		register_var((yyvsp[-2].string));
		(yyval.node) = mknode("VAR_DEF", mknode((yyvsp[-2].string), (yyvsp[0].node), NULL), NULL); 
		}
#line 1933 "y.tab.c"
    break;

  case 35: /* vardecl: ID  */
#line 263 "part1.y"
                     {
        if (var_exists((yyvsp[0].string))) {
            yyerror("Error: variable already declared in this scope.");
            YYABORT;
        }
        register_var((yyvsp[0].string));
        (yyval.node) = mknode("VAR_DEF", mknode((yyvsp[0].string), NULL, NULL), NULL);
    }
#line 1946 "y.tab.c"
    break;

  case 36: /* for_declars: VAR functype var_asis  */
#line 280 "part1.y"
                                   {(yyval.node)=mknode("var",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1952 "y.tab.c"
    break;

  case 37: /* for_declars: lhs ASSIGNMENT expr  */
#line 281 "part1.y"
                                              {(yyval.node)=mknode("=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1958 "y.tab.c"
    break;

  case 38: /* for_declars: %empty  */
#line 282 "part1.y"
                          {(yyval.node)=NULL;}
#line 1964 "y.tab.c"
    break;

  case 39: /* str_dec: str_item COMMA str_dec  */
#line 285 "part1.y"
                             { (yyval.node) = mknode("VARLIST", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1970 "y.tab.c"
    break;

  case 40: /* str_dec: str_item  */
#line 286 "part1.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1976 "y.tab.c"
    break;

  case 41: /* str_item: ID LBRACKET DEC_VAL RBRACKET COLON STR_VAL  */
#line 290 "part1.y"
                                                 {
        validate_array_index((yyvsp[-3].string));
        if (var_exists((yyvsp[-5].string))) {
            yyerror("Variable already defined!");
            YYABORT;
        }
        register_var((yyvsp[-5].string));
        (yyval.node) = mknode("VAR_DEF",
                    mknode((yyvsp[-5].string),
                           mknode("size", mknode((yyvsp[-3].string), NULL, NULL), NULL),
                           mknode((yyvsp[0].string), NULL, NULL)),
                    NULL);
      }
#line 1994 "y.tab.c"
    break;

  case 42: /* str_item: ID LBRACKET DEC_VAL RBRACKET  */
#line 303 "part1.y"
                                   {
        validate_array_index((yyvsp[-1].string));
        if (var_exists((yyvsp[-3].string))) {
            yyerror("Variable already defined!");
            YYABORT;
        }
        register_var((yyvsp[-3].string));
        (yyval.node) = mknode("VAR_DEF",
                    mknode((yyvsp[-3].string),
                           mknode("size", mknode((yyvsp[-1].string), NULL, NULL), NULL),
                           NULL),
                    NULL);
      }
#line 2012 "y.tab.c"
    break;

  case 43: /* var_asis: ID ASSIGNMENT value COMMA var_asis  */
#line 319 "part1.y"
                                                   {(yyval.node)=mknode((yyvsp[-4].string),mknode("",(yyvsp[-2].node),NULL),(yyvsp[0].node));}
#line 2018 "y.tab.c"
    break;

  case 44: /* var_asis: ID COMMA var_asis  */
#line 320 "part1.y"
                                            {(yyval.node)=mknode((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 2024 "y.tab.c"
    break;

  case 45: /* var_asis: ID ASSIGNMENT ref COMMA var_asis  */
#line 322 "part1.y"
                                                           {(yyval.node)=mknode((yyvsp[-4].string),(yyvsp[-2].node),mknode("",(yyvsp[0].node),NULL));}
#line 2030 "y.tab.c"
    break;

  case 46: /* var_asis: ID ASSIGNMENT ref  */
#line 323 "part1.y"
                                            {(yyval.node)=mknode((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 2036 "y.tab.c"
    break;

  case 47: /* var_asis: ID ASSIGNMENT value  */
#line 324 "part1.y"
                                              {(yyval.node)=mknode((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 2042 "y.tab.c"
    break;

  case 48: /* var_asis: ID  */
#line 325 "part1.y"
                             {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2048 "y.tab.c"
    break;

  case 49: /* ref: ID  */
#line 327 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2054 "y.tab.c"
    break;

  case 50: /* ref: ADDRESS ID  */
#line 328 "part1.y"
                                     {(yyval.node)=mknode("&",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2060 "y.tab.c"
    break;

  case 51: /* value: STR_VAL  */
#line 331 "part1.y"
                        {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2066 "y.tab.c"
    break;

  case 52: /* value: CHAR_VAL  */
#line 332 "part1.y"
                                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2072 "y.tab.c"
    break;

  case 53: /* value: DEC_VAL  */
#line 333 "part1.y"
                                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2078 "y.tab.c"
    break;

  case 54: /* value: MINUS DEC_VAL  */
#line 334 "part1.y"
                                        {(yyval.node)=mknode(" -",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2084 "y.tab.c"
    break;

  case 55: /* value: HEX_VAL  */
#line 335 "part1.y"
                                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2090 "y.tab.c"
    break;

  case 56: /* value: REAL_VAL  */
#line 336 "part1.y"
                                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2096 "y.tab.c"
    break;

  case 57: /* value: PLUS REAL_VAL  */
#line 337 "part1.y"
                                        {(yyval.node)=mknode(" +",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2102 "y.tab.c"
    break;

  case 58: /* value: MINUS REAL_VAL  */
#line 338 "part1.y"
                                         {(yyval.node)=mknode(" +",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2108 "y.tab.c"
    break;

  case 59: /* value: BTRUE  */
#line 339 "part1.y"
                                {(yyval.node)=mknode("TRUE ",NULL,NULL);}
#line 2114 "y.tab.c"
    break;

  case 60: /* value: BFALSE  */
#line 340 "part1.y"
                                 {(yyval.node)=mknode("FALSE ",NULL,NULL);}
#line 2120 "y.tab.c"
    break;

  case 61: /* value: NULLL  */
#line 341 "part1.y"
                                {(yyval.node)=mknode("null",NULL,NULL);}
#line 2126 "y.tab.c"
    break;

  case 62: /* statements: statement statements  */
#line 344 "part1.y"
                                     {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2132 "y.tab.c"
    break;

  case 63: /* statements: %empty  */
#line 345 "part1.y"
                          {(yyval.node)=NULL;}
#line 2138 "y.tab.c"
    break;

  case 64: /* stmnt_block: if_block  */
#line 349 "part1.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2144 "y.tab.c"
    break;

  case 65: /* stmnt_block: block  */
#line 350 "part1.y"
                                        {(yyval.node)=(yyvsp[0].node);}
#line 2150 "y.tab.c"
    break;

  case 66: /* stmnt_block: assignment  */
#line 351 "part1.y"
                                             {(yyval.node)=(yyvsp[0].node);}
#line 2156 "y.tab.c"
    break;

  case 67: /* stmnt_block: ret  */
#line 352 "part1.y"
                                      {(yyval.node)=(yyvsp[0].node);}
#line 2162 "y.tab.c"
    break;

  case 68: /* statement: expr SEMICOLON  */
#line 355 "part1.y"
                           {(yyval.node)=(yyvsp[-1].node);}
#line 2168 "y.tab.c"
    break;

  case 69: /* statement: call_func  */
#line 356 "part1.y"
                                    {(yyval.node)=(yyvsp[0].node);}
#line 2174 "y.tab.c"
    break;

  case 70: /* statement: assignment  */
#line 357 "part1.y"
                                     {(yyval.node)=(yyvsp[0].node);}
#line 2180 "y.tab.c"
    break;

  case 71: /* statement: if  */
#line 358 "part1.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2186 "y.tab.c"
    break;

  case 72: /* statement: if_else  */
#line 359 "part1.y"
                                  {(yyval.node)=(yyvsp[0].node);}
#line 2192 "y.tab.c"
    break;

  case 73: /* statement: while  */
#line 360 "part1.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2198 "y.tab.c"
    break;

  case 74: /* statement: do  */
#line 361 "part1.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2204 "y.tab.c"
    break;

  case 75: /* statement: for  */
#line 362 "part1.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2210 "y.tab.c"
    break;

  case 76: /* statement: block  */
#line 363 "part1.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2216 "y.tab.c"
    break;

  case 77: /* if: IF expr COLON stmnt_block  */
#line 366 "part1.y"
                               {
    if (!isBooleanExpression((yyvsp[-2].node)->token)) {
        yyerror("Condition in 'if' must be a boolean expression.");
        YYABORT;
    }
    (yyval.node) = mknode("if", mknode("", (yyvsp[-2].node), mknode("", NULL, NULL)), (yyvsp[0].node));
}
#line 2228 "y.tab.c"
    break;

  case 78: /* if_else: IF expr COLON stmnt_block ELSE COLON stmnt_block  */
#line 376 "part1.y"
                        {
					if (!isBooleanExpression((yyvsp[-5].node)->token)) {
        yyerror("Condition in 'if' must be a boolean expression.");
        YYABORT;
    }
				(yyval.node)=mknode("if-else",
				mknode("", (yyvsp[-5].node),
				mknode("",NULL,NULL)),
				mknode("",(yyvsp[-3].node),
				mknode("",(yyvsp[0].node),NULL)));
			}
#line 2244 "y.tab.c"
    break;

  case 79: /* while: WHILE expr COLON stmnt_block  */
#line 389 "part1.y"
                        {
			if (!isBooleanExpression((yyvsp[-2].node)->token)) {
        		yyerror("Condition in 'While' must be a boolean expression.");
        		YYABORT;
    		}	
				(yyval.node)=mknode("while",
				mknode(" ", (yyvsp[-2].node),
				mknode(" ",NULL,NULL)),(yyvsp[0].node));
			}
#line 2258 "y.tab.c"
    break;

  case 80: /* do: DO COLON stmnt_block WHILE expr SEMICOLON  */
#line 400 "part1.y"
                        {
				(yyval.node)=mknode("do",
				mknode("{", (yyvsp[-3].node),
				mknode("}",NULL,NULL)),
				mknode("while",(yyvsp[-1].node),NULL));
			}
#line 2269 "y.tab.c"
    break;

  case 81: /* for: FOR LPAREN for_declars SEMICOLON expr SEMICOLON lhs ASSIGNMENT expr RPAREN COLON BEG stmnt_block END  */
#line 408 "part1.y"
                        {
			if (!isBooleanExpression((yyvsp[-9].node)->token)&& !isBooleanExpression((yyvsp[-5].node)->token)) {
        		yyerror("Condition in 'for' must be a boolean expression (comparison or 0/1).");
        		YYABORT;
    		}
				(yyval.node)=mknode("for",
				mknode("(",(yyvsp[-11].node),mknode("",(yyvsp[-9].node),mknode("=",(yyvsp[-7].node),mknode("",(yyvsp[-5].node),mknode(")",NULL,NULL))))),
				(yyvsp[-1].node));
			}
#line 2283 "y.tab.c"
    break;

  case 82: /* if_block: BEG declartions statements ret END  */
#line 421 "part1.y"
                        {
				(yyval.node)=mknode("{",(yyvsp[-3].node),mknode("", (yyvsp[-2].node), mknode("",(yyvsp[-1].node),mknode("}",NULL,NULL))));
			}
#line 2291 "y.tab.c"
    break;

  case 83: /* block: BEG declartions statements END  */
#line 426 "part1.y"
                        {
				(yyval.node)=mknode("{",(yyvsp[-2].node),mknode("", (yyvsp[-1].node), mknode("}",NULL,NULL)));
			}
#line 2299 "y.tab.c"
    break;

  case 84: /* assignment: lhs ASSIGNMENT expr SEMICOLON  */
#line 430 "part1.y"
                                              {(yyval.node)=mknode("=",(yyvsp[-3].node),mknode("",(yyvsp[-1].node),mknode("",NULL,NULL)));}
#line 2305 "y.tab.c"
    break;

  case 85: /* assignment: lhs ASSIGNMENT STR_VAL SEMICOLON  */
#line 431 "part1.y"
                                                           {(yyval.node)=mknode("=",(yyvsp[-3].node),mknode((yyvsp[-1].string),NULL,NULL));}
#line 2311 "y.tab.c"
    break;

  case 86: /* lhs: ID  */
#line 434 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2317 "y.tab.c"
    break;

  case 87: /* lhs: ID LBRACKET expr RBRACKET  */
#line 435 "part1.y"
                                                    {(yyval.node)=mknode((yyvsp[-3].string),mknode("[",(yyvsp[-1].node),mknode("]\n",NULL,NULL)),NULL);}
#line 2323 "y.tab.c"
    break;

  case 88: /* lhs: STAR ID  */
#line 436 "part1.y"
                                  {(yyval.node)=mknode("POINTER ",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2329 "y.tab.c"
    break;

  case 89: /* expr: LPAREN expr RPAREN  */
#line 440 "part1.y"
                          {(yyval.node)=mknode("(",(yyvsp[-1].node),mknode(")",NULL,NULL));}
#line 2335 "y.tab.c"
    break;

  case 90: /* expr: expr EQ expr  */
#line 442 "part1.y"
                   {(yyval.node)=mknode("==",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2341 "y.tab.c"
    break;

  case 91: /* expr: expr NOTEQ expr  */
#line 443 "part1.y"
                          {(yyval.node)=mknode("!=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2347 "y.tab.c"
    break;

  case 92: /* expr: expr GTE expr  */
#line 444 "part1.y"
                        {(yyval.node)=mknode(">=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2353 "y.tab.c"
    break;

  case 93: /* expr: expr GT expr  */
#line 445 "part1.y"
                       {(yyval.node)=mknode(">",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2359 "y.tab.c"
    break;

  case 94: /* expr: expr LTE expr  */
#line 446 "part1.y"
                        {(yyval.node)=mknode("<=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2365 "y.tab.c"
    break;

  case 95: /* expr: expr LT expr  */
#line 447 "part1.y"
                       {(yyval.node)=mknode("<",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2371 "y.tab.c"
    break;

  case 96: /* expr: expr AND expr  */
#line 448 "part1.y"
                        {(yyval.node)=mknode("and",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2377 "y.tab.c"
    break;

  case 97: /* expr: expr OR expr  */
#line 449 "part1.y"
                       {(yyval.node)=mknode("||",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2383 "y.tab.c"
    break;

  case 98: /* expr: expr PLUS expr  */
#line 451 "part1.y"
                         {(yyval.node)=mknode("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2389 "y.tab.c"
    break;

  case 99: /* expr: expr MINUS expr  */
#line 452 "part1.y"
                          {(yyval.node)=mknode("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2395 "y.tab.c"
    break;

  case 100: /* expr: expr STAR expr  */
#line 453 "part1.y"
                         {(yyval.node)=mknode("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2401 "y.tab.c"
    break;

  case 101: /* expr: expr DIVISION expr  */
#line 454 "part1.y"
                             {(yyval.node)=mknode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2407 "y.tab.c"
    break;

  case 102: /* expr: NOT expr  */
#line 456 "part1.y"
                   {(yyval.node)=mknode("not ",(yyvsp[0].node),NULL);}
#line 2413 "y.tab.c"
    break;

  case 103: /* expr: derefrence_expr  */
#line 457 "part1.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2419 "y.tab.c"
    break;

  case 104: /* expr: call_func  */
#line 458 "part1.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2425 "y.tab.c"
    break;

  case 105: /* expr: DEC_VAL  */
#line 459 "part1.y"
                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2431 "y.tab.c"
    break;

  case 106: /* expr: MINUS DEC_VAL  */
#line 460 "part1.y"
                        {(yyval.node)=mknode(concat("-",(yyvsp[0].string)),NULL,NULL);}
#line 2437 "y.tab.c"
    break;

  case 107: /* expr: HEX_VAL  */
#line 461 "part1.y"
                  {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2443 "y.tab.c"
    break;

  case 108: /* expr: CHAR_VAL  */
#line 462 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2449 "y.tab.c"
    break;

  case 109: /* expr: REAL_VAL  */
#line 463 "part1.y"
                   {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2455 "y.tab.c"
    break;

  case 110: /* expr: PLUS REAL_VAL  */
#line 464 "part1.y"
                        {(yyval.node)=mknode(concat("+",(yyvsp[0].string)),NULL,NULL);}
#line 2461 "y.tab.c"
    break;

  case 111: /* expr: MINUS REAL_VAL  */
#line 465 "part1.y"
                         {(yyval.node)=mknode(concat("-",(yyvsp[0].string)),NULL,NULL);}
#line 2467 "y.tab.c"
    break;

  case 112: /* expr: BFALSE  */
#line 466 "part1.y"
                 {(yyval.node)=mknode("FALSE ",NULL,NULL);}
#line 2473 "y.tab.c"
    break;

  case 113: /* expr: BTRUE  */
#line 467 "part1.y"
                {(yyval.node)=mknode("TRUE ",NULL,NULL);}
#line 2479 "y.tab.c"
    break;

  case 114: /* expr: ADDRESS ID  */
#line 468 "part1.y"
                     {(yyval.node)=mknode("&",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2485 "y.tab.c"
    break;

  case 115: /* expr: ADDRESS ID LBRACKET expr RBRACKET  */
#line 470 "part1.y"
        {
		(yyval.node)=mknode("&",mknode("[",mknode((yyvsp[-3].string),NULL,NULL),mknode("]",NULL,NULL)),(yyvsp[-1].node));
	}
#line 2493 "y.tab.c"
    break;

  case 116: /* expr: LENGTH ID LENGTH  */
#line 474 "part1.y"
        {
		(yyval.node)=mknode("|",
		mknode((yyvsp[-1].string),NULL,NULL),
		mknode("|",NULL,NULL));
	}
#line 2503 "y.tab.c"
    break;

  case 117: /* expr: ID LBRACKET expr RBRACKET  */
#line 480 "part1.y"
        {(yyval.node)=mknode((yyvsp[-3].string),mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)),NULL);}
#line 2509 "y.tab.c"
    break;

  case 118: /* expr: ID  */
#line 481 "part1.y"
             {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2515 "y.tab.c"
    break;

  case 119: /* expr: NULLL  */
#line 482 "part1.y"
                {(yyval.node)=mknode("null",NULL,NULL);}
#line 2521 "y.tab.c"
    break;

  case 120: /* derefrence_expr: STAR ID  */
#line 485 "part1.y"
                         {(yyval.node)=mknode("POINTER ",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2527 "y.tab.c"
    break;

  case 121: /* derefrence_expr: STAR LPAREN expr RPAREN  */
#line 486 "part1.y"
                                  {(yyval.node)=mknode("POINTER ",mknode("(",(yyvsp[-1].node),NULL),mknode(")",NULL,NULL));}
#line 2533 "y.tab.c"
    break;

  case 122: /* derefrence_expr: STAR ID LBRACKET expr RBRACKET  */
#line 488 "part1.y"
        {(yyval.node)=mknode("POINTER ", mknode((yyvsp[-3].string),NULL,NULL), mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)));}
#line 2539 "y.tab.c"
    break;

  case 123: /* expr_list: expr COMMA expr_list  */
#line 492 "part1.y"
                                     {(yyval.node)=mknode("",(yyvsp[-2].node),mknode("",(yyvsp[0].node),NULL));}
#line 2545 "y.tab.c"
    break;

  case 124: /* expr_list: expr  */
#line 493 "part1.y"
                                       {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2551 "y.tab.c"
    break;

  case 125: /* expr_list: %empty  */
#line 494 "part1.y"
                                  {(yyval.node)=NULL;}
#line 2557 "y.tab.c"
    break;

  case 126: /* paren_expr: LPAREN expr_list RPAREN  */
#line 496 "part1.y"
                                        {(yyval.node)=(yyvsp[-1].node);}
#line 2563 "y.tab.c"
    break;

  case 127: /* call_func: ID paren_expr SEMICOLON  */
#line 498 "part1.y"
                                   {
	if (!func_exists((yyvsp[-2].string))){
		yyerror("function is not defined!");
		YYABORT;
	}
	(yyval.node)=mknode("Call func",mknode((yyvsp[-2].string),NULL,NULL),mknode("args ",(yyvsp[-1].node),NULL));}
#line 2574 "y.tab.c"
    break;


#line 2578 "y.tab.c"

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

#line 505 "part1.y"


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



bool func_exists(char* name) {
	for (int i = 0; i < func_count; ++i) {
		if (strcmp(defined_funcs[i], name) == 0) return true;
	}
	return false;
}

void register_func(char* name) {
	if (func_count < MAX_FUNCS) {
		defined_funcs[func_count++] = strdup(name);
	}
}

void register_var(char* name) {
	if(var_count<MAX_Var){
		defined_vars[var_count++] = strdup(name);
	}
}

bool var_exists(char* name){
	for(int i =0; i< var_count ; i++){
		if (strcmp(defined_vars[i],name)==0) return true;
	}
	return false;
}
void clear_var_scope() {
    for (int i = 0; i < var_count; i++) {
        free(defined_vars[i]);
    }
    var_count = 0;
}


int isBooleanExpression(char* token) {
    return (
		strcmp(token, "TRUE") == 0 ||
		strcmp(token, "notFALSE") == 0 ||
        strcmp(token, "==") == 0 ||
        strcmp(token, "!=") == 0 ||
        strcmp(token, "<") == 0 ||
        strcmp(token, "<=") == 0 ||
        strcmp(token, ">") == 0 ||
        strcmp(token, ">=") == 0 ||
        strcmp(token, "0") == 0 ||
        strcmp(token, "1") == 0
    );
}
void validate_array_index(char* val) {
    for (int i = 0; val[i]; i++) {
        if (val[i] < '0' || val[i] > '9') {
            yyerror("Error: index inside [] must be an integer.");

        }
    }
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
