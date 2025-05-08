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

#line 199 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
