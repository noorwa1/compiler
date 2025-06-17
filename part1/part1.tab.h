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

#ifndef YY_YY_PART1_TAB_H_INCLUDED
# define YY_YY_PART1_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    STR_VAL = 259,                 /* STR_VAL  */
    CHAR_VAL = 260,                /* CHAR_VAL  */
    DEC_VAL = 261,                 /* DEC_VAL  */
    HEX_VAL = 262,                 /* HEX_VAL  */
    REAL_VAL = 263,                /* REAL_VAL  */
    BOOL = 264,                    /* BOOL  */
    CHAR = 265,                    /* CHAR  */
    STRING = 266,                  /* STRING  */
    INT = 267,                     /* INT  */
    INTPTR = 268,                  /* INTPTR  */
    CHARPTR = 269,                 /* CHARPTR  */
    REAL = 270,                    /* REAL  */
    REALPTR = 271,                 /* REALPTR  */
    VOID = 272,                    /* VOID  */
    DO = 273,                      /* DO  */
    WHILE = 274,                   /* WHILE  */
    FOR = 275,                     /* FOR  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    VAR = 278,                     /* VAR  */
    TYPE = 279,                    /* TYPE  */
    FUNCTION = 280,                /* FUNCTION  */
    DEF = 281,                     /* DEF  */
    NULLL = 282,                   /* NULLL  */
    BEG = 283,                     /* BEG  */
    END = 284,                     /* END  */
    RETURN = 285,                  /* RETURN  */
    RETURNS = 286,                 /* RETURNS  */
    MAIN = 287,                    /* MAIN  */
    ASSIGNMENT = 288,              /* ASSIGNMENT  */
    EQ = 289,                      /* EQ  */
    NOTEQ = 290,                   /* NOTEQ  */
    GT = 291,                      /* GT  */
    GTE = 292,                     /* GTE  */
    LT = 293,                      /* LT  */
    LTE = 294,                     /* LTE  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    NOT = 297,                     /* NOT  */
    PLUS = 298,                    /* PLUS  */
    MINUS = 299,                   /* MINUS  */
    STAR = 300,                    /* STAR  */
    DIVISION = 301,                /* DIVISION  */
    ADDRESS = 302,                 /* ADDRESS  */
    LENGTH = 303,                  /* LENGTH  */
    ARG_ARROW = 304,               /* ARG_ARROW  */
    SEMICOLON = 305,               /* SEMICOLON  */
    COMMA = 306,                   /* COMMA  */
    COLON = 307,                   /* COLON  */
    LPAREN = 308,                  /* LPAREN  */
    RPAREN = 309,                  /* RPAREN  */
    LBRACKET = 310,                /* LBRACKET  */
    RBRACKET = 311,                /* RBRACKET  */
    LBRACE = 312,                  /* LBRACE  */
    RBRACE = 313,                  /* RBRACE  */
    BTRUE = 314,                   /* BTRUE  */
    BFALSE = 315,                  /* BFALSE  */
    ARGS = 316                     /* ARGS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "part1.y"

    char* string;
    int num;
    Result res;

#line 131 "part1.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PART1_TAB_H_INCLUDED  */
