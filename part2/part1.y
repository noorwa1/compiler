%{
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
%}

%union
{
    struct node *node;
    char *string;
	char* num;
}
%token <num> ARGS
%token <string> DO WHILE FOR IF ELSE  
%token <string>  BOOL STRING CHARPTR CHAR INT INTPTR REAL REALPTR
%token <string> ADDRESS ASSIGNMENT LENGTH NOT EQ NOTEQ GTE GT LTW LT AND OR
%token <string> DIVISION PLUS MINUS STAR
%token <string> STR_VAL REAL_VAL CHAR_VAL DEC_VAL HEX_VAL NULLL BTRUE BFALSE
%token <string> SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE  BEG END COLON ARG_ARROW
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
%type <node> varblock typedecls typedecl vardecls vardecl str_item
%type <node> project program ret ref expr lhs derefrence_expr expr_list call_func paren_expr
%type <node> params parameters par value var_asis str_dec  declartions statements statement
%type <node> stmnt_block if if_block if_else while do for for_declars 
%type <node> proc procedures functype  body body_ret assignment block 


%start project

%%

project:    program {printTree($1);}

program:   procedures  {$$=mknode("CODE ",$1,NULL);}

procedures: procedures proc {$$=mknode("",$1,$2);}
			| {$$=NULL;}
			;


proc:
    DEF ID LPAREN params RPAREN COLON RETURNS functype declartions BEG body_ret END
    {
		parm_num=1;
		clear_var_scope();
        if (func_exists($2)) {
            yyerror("Error: Function name already defined.");
            YYABORT;
        }
        register_func($2);

        $$ = mknode("(FUNC\n\t ",
                    mknode($2,
                           mknode("\n",
                                  mknode("\t\t(PARS\n ", $4, NULL),
                                  mknode("\n\t\t(RET ", $8,
                                         mknode("\n\t\t(DECLS\n", $9, NULL))
                           ),
                           NULL
                    ),
                    $11);
    }

  | DEF ID LPAREN params RPAREN COLON declartions BEG body END
    {
		parm_num=1;
		clear_var_scope();
        if (func_exists($2)) {
            yyerror("Error: Function name already defined.");
            YYABORT;
        }
        register_func($2);

        $$ = mknode("(FUNC\n\t ",
                    mknode($2,
                           mknode("\n",
                                  mknode("\t\t(PARS\n\t ", $4, NULL),
                                  mknode("\n\t\t(RET ",
                                         mknode("\n\t\t(DECLS\n", $7, NULL),
                                         NULL)
                           ),
                           NULL
                    ),
                    mknode(")\n", $9, NULL));
    }

  | DEF MAIN LPAREN params RPAREN COLON RETURNS functype BEG body_ret END
    {
        if (main_defined) {
            yyerror("Error: Multiple 'main' functions are not allowed.");
            yyerror($2);
            YYABORT;
        }
        if (main_defined && $4 != NULL) {
            yyerror("Main function does not accept parameters!");
            YYABORT;
        }
        main_defined = 1;

        $$ = mknode("(FUNC\n\t ",
                    mknode($2,
                           mknode("\n",
                                  mknode("\n\t\t(None\n ", NULL, NULL),
                                  mknode("\n\t\t(RET ", $8, NULL)
                           ),
                           NULL
                    ),
                    mknode(")\n", $10, NULL));
    }
;



functype:   BOOL {$$=mknode(" BOOL ",NULL,NULL);}
			| CHAR {$$=mknode(" CHAR ",NULL,NULL);}
            | INT {$$=mknode(" INT ",NULL,NULL);}
            | REAL {$$=mknode(" REAL ",NULL,NULL);}
			| CHARPTR {$$=mknode(" CHAR* ",NULL,NULL);}
			| REALPTR {$$=mknode(" REAL* ",NULL,NULL);}
			| INTPTR {$$=mknode(" INT* ",NULL,NULL);}
			;

params:		parameters {$$= mknode("PARAMLIST\n",$1,NULL);}
			| {$$=mknode("NONE",NULL,NULL);}
			;
																						
parameters:
    parameters SEMICOLON ARGS functype COLON par {
        if (atoi(&$3[3]) != parm_num) {
            printf("Error: Expected par%d but got %s\n", parm_num, $3);
            yyerror("Parameter order mismatch.");
            YYABORT;
        }
        printf("  %d      %d\n", parm_num, atoi(&$3[3]));
        parm_num++;

        $$ = mknode("",
                    $1,
                    mknode(" (", mknode($3, $4, $6), mknode(" )\n", NULL, NULL)));
    }
  | ARGS functype COLON par {
        if (atoi(&$1[3]) != parm_num) {
            printf("Error: Expected par%d but got %s\n", parm_num, $1);
            yyerror("Parameter order mismatch.");
            YYABORT;
        }
        printf("  %d      %d\n", parm_num, atoi(&$1[3]));
        parm_num++;

        $$ = mknode(" (", mknode($1, $2, $4), mknode(" )\n", NULL, NULL));
    }
;


par:		ID COMMA par {$$=mknode($1,mknode(" ",$3,NULL),NULL);}
			| ID {$$=mknode($1, NULL, NULL);}
			;

body:		procedures  statements
{
			$$=mknode("body ",mknode("",$1,NULL),mknode("",$2,mknode("}",NULL,NULL)));
}

body_ret:	procedures  statements ret
{
			$$=mknode("body ",mknode("",$1,NULL),mknode("",$2,mknode("}",NULL,NULL)));
}

ret: 		RETURN expr SEMICOLON {$$=mknode("return",$2,NULL);};



declartions: varblock declartions {$$=mknode("",$1,$2);}
			|{$$=NULL;}



varblock: VAR typedecls{ $$ = mknode("DECLARE_BLOCK\n\t\t\t", $2, NULL); }

typedecls:
    typedecls typedecl          { $$ = mknode("TYPELIST\n\t\t\t", $1, $2); }
  | typedecl                    { $$ = $1; }
    ;

typedecl:
    TYPE functype COLON vardecls SEMICOLON  { $$ = mknode("TYPE", mknode($2->token, $4, NULL), NULL); }
	| TYPE STRING COLON str_dec SEMICOLON {
        $$ = mknode("TYPE", mknode("string", $4, NULL), NULL);
      }
    ;

vardecls:
    vardecls COMMA vardecl      { $$ = mknode("VARLIST", $1, $3); }
  | vardecl                     { $$ = $1; }
    ;

vardecl:	ID COLON value    { 
		if (var_exists($1)){
			yyerror("two variables have the same name in the scope! $17\n");
			YYABORT;
		}		
		register_var($1);
		$$ = mknode("VAR_DEF", mknode($1, $3, NULL), NULL); 
		}
		| ID {
        if (var_exists($1)) {
            yyerror("Error: variable already declared in this scope.");
            YYABORT;
        }
        register_var($1);
        $$ = mknode("VAR_DEF", mknode($1, NULL, NULL), NULL);
    }
		
    ;







for_declars: VAR functype var_asis {$$=mknode("var",$2,$3);}
			| lhs ASSIGNMENT expr {$$=mknode("=",$1,$3);}
			| {$$=NULL;}

str_dec:
      str_item COMMA str_dec { $$ = mknode("VARLIST", $1, $3); }
    | str_item    { $$ = $1; }
    ;

str_item:
      ID LBRACKET DEC_VAL RBRACKET COLON STR_VAL {
        validate_array_index($3);
        if (var_exists($1)) {
            yyerror("Variable already defined!");
            YYABORT;
        }
        register_var($1);
        $$ = mknode("VAR_DEF",
                    mknode($1,
                           mknode("size", mknode($3, NULL, NULL), NULL),
                           mknode($6, NULL, NULL)),
                    NULL);
      }
    | ID LBRACKET DEC_VAL RBRACKET {
        validate_array_index($3);
        if (var_exists($1)) {
            yyerror("Variable already defined!");
            YYABORT;
        }
        register_var($1);
        $$ = mknode("VAR_DEF",
                    mknode($1,
                           mknode("size", mknode($3, NULL, NULL), NULL),
                           NULL),
                    NULL);
      }
    ;


var_asis:	ID ASSIGNMENT value COMMA var_asis {$$=mknode($1,mknode("",$3,NULL),$5);}
			| ID COMMA var_asis {$$=mknode($1,$3,NULL);}

			| ID ASSIGNMENT ref COMMA var_asis {$$=mknode($1,$3,mknode("",$5,NULL));}
			| ID ASSIGNMENT ref {$$=mknode($1,$3,NULL);}
			| ID ASSIGNMENT value {$$=mknode($1,$3,NULL);}
			| ID {$$=mknode($1,NULL,NULL);}
			;
ref:		ID {$$=mknode($1,NULL,NULL);}
			| ADDRESS ID {$$=mknode("&",mknode($2,NULL,NULL),NULL);}
			;

value:		STR_VAL {$$=mknode($1,NULL,NULL);}
			| CHAR_VAL {$$=mknode($1,NULL,NULL);}
			| DEC_VAL {$$=mknode($1,NULL,NULL);}
			| MINUS DEC_VAL {$$=mknode(" -",mknode($2,NULL,NULL),NULL);}
			| HEX_VAL {$$=mknode($1,NULL,NULL);}
			| REAL_VAL {$$=mknode($1,NULL,NULL);}
			| PLUS REAL_VAL {$$=mknode(" +",mknode($2,NULL,NULL),NULL);}
			| MINUS REAL_VAL {$$=mknode(" +",mknode($2,NULL,NULL),NULL);}
			| BTRUE {$$=mknode("TRUE ",NULL,NULL);}
			| BFALSE {$$=mknode("FALSE ",NULL,NULL);}
			| NULLL {$$=mknode("null",NULL,NULL);}
			;

statements:	statement statements {$$=mknode("",$1,$2);}
			| {$$=NULL;}
			;

//stmnt_block
stmnt_block: 	if_block {$$=$1;}
				| block {$$=$1;}
				| assignment {$$=$1;}
				| ret {$$=$1;}
				;

statement:  expr SEMICOLON {$$=$1;}
			| call_func {$$=$1;}
			| assignment {$$=$1;}
			| if {$$=$1;}
			| if_else {$$=$1;}
			| while {$$=$1;}
			| do {$$=$1;}
			| for {$$=$1;}
			| block {$$=$1;}
			;

if: IF expr COLON stmnt_block  {
    if (!isBooleanExpression($2->token)) {
        yyerror("Condition in 'if' must be a boolean expression.");
        YYABORT;
    }
    $$ = mknode("if", mknode("", $2, mknode("", NULL, NULL)), $4);
}%prec IF


if_else: 	IF  expr COLON stmnt_block  ELSE COLON stmnt_block
			{
					if (!isBooleanExpression($2->token)) {
        yyerror("Condition in 'if' must be a boolean expression.");
        YYABORT;
    }
				$$=mknode("if-else",
				mknode("", $2,
				mknode("",NULL,NULL)),
				mknode("",$4,
				mknode("",$7,NULL)));
			}

while:		WHILE  expr COLON stmnt_block
			{
			if (!isBooleanExpression($2->token)) {
        		yyerror("Condition in 'While' must be a boolean expression.");
        		YYABORT;
    		}	
				$$=mknode("while",
				mknode(" ", $2,
				mknode(" ",NULL,NULL)),$4);
			};

do:			DO COLON stmnt_block WHILE  expr SEMICOLON
			{
				$$=mknode("do",
				mknode("{", $3,
				mknode("}",NULL,NULL)),
				mknode("while",$5,NULL));
			};

for:		FOR LPAREN for_declars SEMICOLON expr SEMICOLON lhs ASSIGNMENT expr RPAREN COLON BEG stmnt_block END
			{
			if (!isBooleanExpression($5->token)&& !isBooleanExpression($9->token)) {
        		yyerror("Condition in 'for' must be a boolean expression (comparison or 0/1).");
        		YYABORT;
    		}
				$$=mknode("for",
				mknode("(",$3,mknode("",$5,mknode("=",$7,mknode("",$9,mknode(")",NULL,NULL))))),
				$13);
			}
			;


if_block:	BEG declartions statements ret END
			{
				$$=mknode("{",$2,mknode("", $3, mknode("",$4,mknode("}",NULL,NULL))));
			};

block: 		BEG declartions statements END
			{
				$$=mknode("{",$2,mknode("", $3, mknode("}",NULL,NULL)));
			};

assignment:	lhs ASSIGNMENT expr SEMICOLON {$$=mknode("=",$1,mknode("",$3,mknode("",NULL,NULL)));}
			| lhs ASSIGNMENT STR_VAL SEMICOLON {$$=mknode("=",$1,mknode($3,NULL,NULL));}
			;

lhs:		ID {$$=mknode($1,NULL,NULL);}
			| ID LBRACKET expr RBRACKET {$$=mknode($1,mknode("[",$3,mknode("]\n",NULL,NULL)),NULL);}
			| STAR ID {$$=mknode("POINTER ",mknode($2,NULL,NULL),NULL);}
			;


expr:  LPAREN expr RPAREN {$$=mknode("(",$2,mknode(")",NULL,NULL));}
//bool oper
    | expr EQ expr {$$=mknode("==",$1,$3);}
	| expr NOTEQ expr {$$=mknode("!=",$1,$3);}
	| expr GTE expr {$$=mknode(">=",$1,$3);}
	| expr GT expr {$$=mknode(">",$1,$3);}
	| expr LTE expr {$$=mknode("<=",$1,$3);}
	| expr LT expr {$$=mknode("<",$1,$3);}
	| expr AND expr {$$=mknode("and",$1,$3);}
	| expr OR expr {$$=mknode("||",$1,$3);}
//aritmetical operator
	| expr PLUS expr {$$=mknode("+",$1,$3);}
	| expr MINUS expr {$$=mknode("-",$1,$3);}
	| expr STAR expr {$$=mknode("*",$1,$3);}
	| expr DIVISION expr {$$=mknode("/",$1,$3);}
//not operator
	| NOT expr {$$=mknode("not ",$2,NULL);}
	| derefrence_expr {$$=$1;}
	| call_func {$$=$1;}
	| DEC_VAL {$$=mknode($1,NULL,NULL);}
	| MINUS DEC_VAL {$$=mknode(concat("-",$2),NULL,NULL);}
	| HEX_VAL {$$=mknode($1,NULL,NULL);}
	| CHAR_VAL {$$=mknode($1,NULL,NULL);}
	| REAL_VAL {$$=mknode($1,NULL,NULL);}
	| PLUS REAL_VAL {$$=mknode(concat("+",$2),NULL,NULL);}
	| MINUS REAL_VAL {$$=mknode(concat("-",$2),NULL,NULL);}
	| BFALSE {$$=mknode("FALSE ",NULL,NULL);}
	| BTRUE {$$=mknode("TRUE ",NULL,NULL);}
	| ADDRESS ID {$$=mknode("&",mknode($2,NULL,NULL),NULL);}
	| ADDRESS ID LBRACKET expr RBRACKET
	{
		$$=mknode("&",mknode("[",mknode($2,NULL,NULL),mknode("]",NULL,NULL)),$4);
	}
	| LENGTH ID LENGTH
	{
		$$=mknode("|",
		mknode($2,NULL,NULL),
		mknode("|",NULL,NULL));
	}
	| ID LBRACKET expr RBRACKET
	{$$=mknode($1,mknode("[",$3,mknode("]",NULL,NULL)),NULL);}
	| ID {$$=mknode($1,NULL,NULL);}
	| NULLL {$$=mknode("null",NULL,NULL);};
	;

derefrence_expr: STAR ID {$$=mknode("POINTER ",mknode($2,NULL,NULL),NULL);}
	| STAR LPAREN expr RPAREN {$$=mknode("POINTER ",mknode("(",$3,NULL),mknode(")",NULL,NULL));}
	| STAR ID LBRACKET expr RBRACKET
	{$$=mknode("POINTER ", mknode($2,NULL,NULL), mknode("[",$4,mknode("]",NULL,NULL)));}
	;

//list of expression
expr_list:	expr COMMA expr_list {$$=mknode("",$1,mknode("",$3,NULL));}
				| expr {$$=mknode("",$1,NULL);}
				| {$$=NULL;};

paren_expr:	LPAREN expr_list RPAREN {$$=$2;};

call_func: ID paren_expr SEMICOLON {
	if (!func_exists($1)){
		yyerror("function is not defined!");
		YYABORT;
	}
	$$=mknode("Call func",mknode($1,NULL,NULL),mknode("args ",$2,NULL));} ;

%%

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