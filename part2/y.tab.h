/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 197 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
