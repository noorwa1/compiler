%{
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

%}

%union {
    char *temp;   // Temporary variable for expressions
    char *string; // For identifiers and literals
    char *num;    // For numbers
    struct {
        char *name;
        int size;
    } array;
    int dummy;    // Dummy value for non-value rules
}

%token <num> ARGS
%token <string> DO WHILE FOR IF ELSE  
%token <string> BOOL STRING CHARPTR CHAR INT INTPTR REAL REALPTR
%token <string> ADDRESS ASSIGNMENT LENGTH NOT EQ NOTEQ GTE GT LTW LT AND OR
%token <string> DIVISION PLUS MINUS STAR
%token <string> STR_VAL REAL_VAL CHAR_VAL DEC_VAL HEX_VAL NULLL BTRUE BFALSE
%token <string> SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE BEG END COLON ARG_ARROW
%token <string> VOID FUNCTION MAIN RETURN ID DEF RETURNS
%token <string> VAR TYPE

%left PLUS MINUS RETURN
%left STAR DIVISION
%left EQ NOTEQ LT LTE GTE GT OR AND
%left SEMICOLON
%right NOT END

%nonassoc ID
%nonassoc MAIN
%nonassoc LPAREN
%nonassoc IF
%nonassoc ELSE

// Individual type declarations
%type <temp> expr value call_func expr_list paren_expr derefrence_expr
%type <string> lhs ref
%type <dummy> project program procedures proc functype 
%type <dummy> params parameters par declartions varblock 
%type <dummy> typedecls typedecl vardecls vardecl 
%type <dummy> str_dec str_item var_asis statements 
%type <dummy> stmnt_block statement if if_else while do 
%type <dummy> for for_declars if_block block assignment
%type <dummy> body body_ret ret

%start project

%%

project:    program { YYACCEPT; }

program:   procedures  {  }

procedures: procedures proc { }
            | { }
            ;

proc:
    DEF ID LPAREN params RPAREN COLON RETURNS functype declartions BEG body_ret END
    {
        currentFunc = $2;
        resetCounters();
        genCode("%s:\n", $2);
        genCode("    BeginFunc\n");
        genCode("    EndFunc\n\n");
    }
  | DEF ID LPAREN params RPAREN COLON declartions BEG body END
    {
        currentFunc = $2;
        resetCounters();
        genCode("%s:\n", $2);
        genCode("    BeginFunc\n");
        genCode("    EndFunc\n\n");
    }
  | DEF MAIN LPAREN params RPAREN COLON declartions BEG body END
    {
        currentFunc = "main";
        resetCounters();
        genCode("main:\n");
        genCode("    BeginFunc\n");
        genCode("    EndFunc\n\n");
    }
    ;

functype:   BOOL { }
            | CHAR { }
            | INT { }
            | REAL { }
            | CHARPTR { }
            | REALPTR { }
            | INTPTR { }
            ;

params:        { }
            | parameters { }
            ;
                                                                                            
parameters:
    parameters SEMICOLON ARGS functype COLON par { }
  | ARGS functype COLON par { }
    ;

par:        ID COMMA par { }
            | ID { }
            ;

body:        procedures  statements { }

body_ret:    procedures  statements ret { }

ret:         RETURN expr SEMICOLON { 
                genCode("    Return %s\n", $2);
            };

declartions: varblock declartions { }
            | { }
            ;

varblock: VAR typedecls { } ;

typedecls: typedecls typedecl { } | typedecl { } ;

typedecl: TYPE functype COLON vardecls SEMICOLON  { }
        | TYPE STRING COLON str_dec SEMICOLON { }
        ;

vardecls: vardecls COMMA vardecl { } | vardecl { } ;

vardecl:    ID COLON value { 
                genCode("    %s = %s\n", $1, $3);
            }
            | ID {
                // Declaration without initialization
            }
            ;

str_dec: str_item COMMA str_dec { } | str_item { } ;

str_item:   ID LBRACKET DEC_VAL RBRACKET COLON STR_VAL { }
            | ID LBRACKET DEC_VAL RBRACKET { }
            ;

var_asis:   ID ASSIGNMENT value COMMA var_asis { 
                genCode("    %s = %s\n", $1, $3);
            }
            | ID COMMA var_asis { }
            | ID ASSIGNMENT ref COMMA var_asis { 
                genCode("    %s = %s\n", $1, $3);
            }
            | ID ASSIGNMENT ref { 
                genCode("    %s = %s\n", $1, $3);
            }
            | ID ASSIGNMENT value { 
                genCode("    %s = %s\n", $1, $3);
            }
            | ID { }
            ;

ref:        ID { $$ = $1; }
            | ADDRESS ID { 
                char* temp = newTemp();
                genCode("    %s = &%s\n", temp, $2);
                $$ = temp;
            }
            ;

value:      STR_VAL { $$ = $1; }
            | CHAR_VAL { $$ = $1; }
            | DEC_VAL { $$ = $1; }
            | MINUS DEC_VAL { 
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, $2);
                $$ = temp;
            }
            | HEX_VAL { $$ = $1; }
            | REAL_VAL { $$ = $1; }
            | PLUS REAL_VAL { $$ = $2; } // Ignore unary plus
            | MINUS REAL_VAL {
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, $2);
                $$ = temp;
            }
            | BTRUE { $$ = "1"; } 
            | BFALSE { $$ = "0"; } 
            | NULLL { $$ = "0"; } 
            ;

statements:    statement statements { }
            | { }
            ;

stmnt_block:    if_block { }
                | block { }
                | assignment { }
                | ret { }
                ;

statement:  expr SEMICOLON { }
            | call_func { }
            | assignment { }
            | if { }
            | if_else { }
            | while { }
            | do { }
            | for { }
            | block { }
            ;

for_declars: 
    VAR functype var_asis 
    {
    }
    | lhs ASSIGNMENT expr 
    {
        genCode("    %s = %s\n", $1, $3);
    }
    | 
    {
    }
    ;

if:         IF expr COLON stmnt_block  
            {
                char* trueLabel = newLabel();
                char* falseLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    if %s Goto %s\n", $2, trueLabel);
                genCode("    goto %s\n", falseLabel);
                genCode("%s:\n", trueLabel);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", falseLabel);
                genCode("%s:\n", endLabel);
            }

if_else:    IF  expr COLON stmnt_block  ELSE COLON stmnt_block
            {
                char* trueLabel = newLabel();
                char* falseLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    if %s Goto %s\n", $2, trueLabel);
                genCode("    goto %s\n", falseLabel);
                genCode("%s:\n", trueLabel);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", falseLabel);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", endLabel);
            }

while:      WHILE  expr COLON stmnt_block
            {
                char* startLabel = newLabel();
                char* bodyLabel = newLabel();
                char* endLabel = newLabel();
                genCode("%s:\n", startLabel);
                genCode("    ifFalse %s Goto %s\n", $2, endLabel);
                genCode("    goto %s\n", bodyLabel);
                genCode("%s:\n", bodyLabel);
                genCode("    goto %s\n", startLabel);
                genCode("%s:\n", endLabel);
            }

do:         DO COLON stmnt_block WHILE  expr SEMICOLON
            {
                char* startLabel = newLabel();
                char* endLabel = newLabel();
                genCode("%s:\n", startLabel);
                genCode("    if %s Goto %s\n", $5, startLabel);
                genCode("%s:\n", endLabel);
            }

for:        FOR LPAREN for_declars SEMICOLON expr SEMICOLON lhs ASSIGNMENT expr RPAREN COLON BEG stmnt_block END
            {
                char* startLabel = newLabel();
                char* bodyLabel = newLabel();
                char* updateLabel = newLabel();
                char* endLabel = newLabel();
                
                genCode("    goto %s\n", updateLabel);
                genCode("%s:\n", startLabel);
                genCode("    ifFalse %s Goto %s\n", $5, endLabel);
                genCode("    goto %s\n", bodyLabel);
                genCode("%s:\n", bodyLabel);
                genCode("%s:\n", updateLabel);
                genCode("    %s = %s\n", $7, $9); 
                genCode("    goto %s\n", startLabel);
                genCode("%s:\n", endLabel);
            }
            ;

if_block:    BEG declartions statements ret END { }
            | BEG declartions statements END { }
            ;

block:      BEG declartions statements END { } ;

assignment: lhs ASSIGNMENT expr SEMICOLON { 
                genCode("    %s = %s\n", $1, $3);
            }
            | lhs ASSIGNMENT STR_VAL SEMICOLON { 
                genCode("    %s = %s\n", $1, $3);
            }
            ;

lhs:        ID { $$ = $1; }
            | ID LBRACKET expr RBRACKET { 
                char* temp = newTemp();
                genCode("    %s = %s[%s]\n", temp, $1, $3);
                $$ = temp;
            }
            | STAR ID { 
                char* temp = newTemp();
                genCode("    %s = *%s\n", temp, $2);
                $$ = temp;
            }
            ;

expr:       LPAREN expr RPAREN { $$ = $2; }
            | expr EQ expr { 
                char* temp = newTemp();
                genCode("    %s = %s == %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr NOTEQ expr { 
                char* temp = newTemp();
                genCode("    %s = %s != %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr GTE expr { 
                char* temp = newTemp();
                genCode("    %s = %s >= %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr GT expr { 
                char* temp = newTemp();
                genCode("    %s = %s > %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr LTE expr { 
                char* temp = newTemp();
                genCode("    %s = %s <= %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr LT expr { 
                char* temp = newTemp();
                genCode("    %s = %s < %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr AND expr { 
                char* temp = newTemp();
                char* falseLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    ifFalse %s Goto %s\n", $1, falseLabel);
                genCode("    %s = %s\n", temp, $3);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", falseLabel);
                genCode("    %s = 0\n", temp);
                genCode("%s:\n", endLabel);
                $$ = temp;
            }
            | expr OR expr { 
                char* temp = newTemp();
                char* trueLabel = newLabel();
                char* endLabel = newLabel();
                genCode("    ifTrue %s Goto %s\n", $1, trueLabel);
                genCode("    %s = %s\n", temp, $3);
                genCode("    goto %s\n", endLabel);
                genCode("%s:\n", trueLabel);
                genCode("    %s = 1\n", temp);
                genCode("%s:\n", endLabel);
                $$ = temp;
            }
            | expr PLUS expr { 
                char* temp = newTemp();
                genCode("    %s = %s + %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr MINUS expr { 
                char* temp = newTemp();
                genCode("    %s = %s - %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr STAR expr { 
                char* temp = newTemp();
                genCode("    %s = %s * %s\n", temp, $1, $3);
                $$ = temp;
            }
            | expr DIVISION expr { 
                char* temp = newTemp();
                genCode("    %s = %s / %s\n", temp, $1, $3);
                $$ = temp;
            }
            | NOT expr { 
                char* temp = newTemp();
                genCode("    %s = !%s\n", temp, $2);
                $$ = temp;
            }
            | call_func { $$ = $1; }
            | DEC_VAL { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, $1);
                $$ = temp;
            }
            | MINUS DEC_VAL { 
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, $2);
                $$ = temp;
            }
            | HEX_VAL { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, $1);
                $$ = temp;
            }
            | CHAR_VAL { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, $1);
                $$ = temp;
            }
            | REAL_VAL { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, $1);
                $$ = temp;
            }
            | PLUS REAL_VAL { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, $2);
                $$ = temp;
            }
            | MINUS REAL_VAL {
                char* temp = newTemp();
                genCode("    %s = -%s\n", temp, $2);
                $$ = temp;
            }
            | BFALSE { 
                char* temp = newTemp();
                genCode("    %s = 0\n", temp);
                $$ = temp;
            }
            | BTRUE { 
                char* temp = newTemp();
                genCode("    %s = 1\n", temp);
                $$ = temp;
            }
            | ADDRESS ID { 
                char* temp = newTemp();
                genCode("    %s = &%s\n", temp, $2);
                $$ = temp;
            }
            | ADDRESS ID LBRACKET expr RBRACKET {
                char* temp = newTemp();
                genCode("    %s = &%s[%s]\n", temp, $2, $4);
                $$ = temp;
            }
            | LENGTH ID LENGTH {
                char* temp = newTemp();
                genCode("    %s = sizeof(%s)\n", temp, $2);
                $$ = temp;
            }
            | ID LBRACKET expr RBRACKET {
                char* temp = newTemp();
                genCode("    %s = %s[%s]\n", temp, $1, $3);
                $$ = temp;
            }
            | ID { 
                char* temp = newTemp();
                genCode("    %s = %s\n", temp, $1);
                $$ = temp;
            }
            | NULLL { 
                char* temp = newTemp();
                genCode("    %s = 0\n", temp);
                $$ = temp;
            }
            ;

derefrence_expr: STAR ID { 
                char* temp = newTemp();
                genCode("    %s = *%s\n", temp, $2);
                $$ = temp;
            }
            | STAR LPAREN expr RPAREN { 
                char* temp = newTemp();
                genCode("    %s = *(%s)\n", temp, $3);
                $$ = temp;
            }
            | STAR ID LBRACKET expr RBRACKET {
                char* temp = newTemp();
                genCode("    %s = *%s[%s]\n", temp, $2, $4);
                $$ = temp;
            }
            ;

expr_list:    expr COMMA expr_list { 

                genCode("    PushParam %s\n", $1);
            }
            | expr { 
                genCode("    PushParam %s\n", $1);
            }
            | { }
            ;

paren_expr:    LPAREN expr_list RPAREN { } ;

call_func: ID paren_expr SEMICOLON { 
                char* temp = newTemp();
                genCode("    %s = LCall %s\n", temp, $1);
                genCode("    PopParams\n");
                $$ = temp;
            } ;

%%
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