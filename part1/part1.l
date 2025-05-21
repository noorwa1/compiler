%{
#include<stdio.h>
#include "y.tab.h"
%}
%x comment
%%

bool {return BOOL;}
char {return CHAR;}
int {return INT;}
real {return REAL;}
string {return STRING;}
int\* {return INTPTR;}
char\* {return CHARPTR;}
real\* {return REALPTR;}
void {return VOID;}

if {return IF;}
else {return ELSE;}
do {return DO;}
while {return WHILE;}
for {return FOR;}
var { return VAR;}
function {return FUNCTION;}
def {return DEF;}
null {return NULLL;}
begin {return BEG;}
end {return END;}
type {return TYPE; }
return {return RETURN;}
returns {return RETURNS;}
";" {return SEMICOLON;}

"par"[0-9]+  {
    yylval.num = strdup(yytext);
    return ARGS;
}
"->" {return ARG_ARROW;}
"and" {return AND;}
"/" {return DIVISION;}
"=" {return ASSIGNMENT;}
"==" {return EQ;}
">" {return GT;}
">=" {return GTE;}
"<" {return LT;}
"<=" {return LTE;}
"-" {return MINUS;}
"!" {return NOT;}
"!=" {return NOTEQ;}
"||" {return OR;}
"+" {return PLUS;}
"*" {return STAR;}
"&" {return ADDRESS;}

"_main_" {yylval.string = strdup(yytext); return MAIN;}
"|" {return LENGTH;}
"," {return COMMA;}
"{" {return LBRACE;}
"}" {return RBRACE;}
"(" {return LPAREN;}
")" {return RPAREN;}
"[" {return LBRACKET;}
"]" {return RBRACKET;}
":" {return COLON;}


 "#->"   BEGIN comment;
 <comment>[^\n] ;
 <comment>\n    yylineno++;
 <comment>"<-#"  BEGIN 0;
 "<-#"

TRUE                                    {return BTRUE;}
FALSE                                   {return BFALSE;}
[a-zA-Z][a-zA-Z0-9_]*                   {yylval.string = strdup(yytext); return ID;}
"\""[^"]*"\""                           {yylval.string = strdup(yytext); return STR_VAL;}
\'.\'                                   {yylval.string = strdup(yytext); return CHAR_VAL;}
[1-9][0-9]*|[0-9]                       {yylval.string = strdup(yytext); return DEC_VAL;}
0(x|X)[0-9A-F]+                         {yylval.string = strdup(yytext); return HEX_VAL;}
[0-9]+\.[0-9]+([eE][-+]?[0-9]+)?       {yylval.string = strdup(yytext); return REAL_VAL;}

[\n]                                    {yylineno++;} 
[ \t]+                                  ;
.                                       return yytext[0];

%%
int yywrap(void)        
{
    return 1;           
}
