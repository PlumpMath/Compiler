%option yylineno
%pointer

%{
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"
#include "parser.hpp"

void yyerror(const char *);
%}

/***************************************************************************
	Replace with your code from this point on
***************************************************************************/

%%

return                    {return T_RETURN    ;}  
\|\|                      {return T_OR        ;}  
\&\&                      {return T_AND       ;} 
==                        {return T_EQ        ;} 
\!\=                      {return T_NEQ       ;} 
\<\=                      {return T_LEQ       ;} 
\>\=                      {return T_GEQ       ;} 
intarray                  {return T_INTARRAY  ;} 
function                  {return T_FUNCTION  ;} 
var                       {return T_VAR       ;} 
for                       {return T_FOR       ;} 
int                       {return T_TYPE_INT  ;} 
if                        {return T_IF        ;} 
else                      {return T_ELSE      ;} 
bool                      {return T_TYPE_BOOL ;}  
true                      {return T_TRUE      ;}  
false                     {return T_FALSE     ;}  
[a-zA-Z][a-zA-Z0-9]*      {return T_ID        ;}  
[\=\,\:\;\|\{\}\[\]\!\<\>\*\(\),\+\-\*\/]   {return *yytext     ;}   
0[0-7]*                   {return T_OCT       ;}
[1-9][0-9]*               {yylval.u_base_int = atoi(yytext); return T_DEC ;}
(0x|0X)[0-9A-F][0-9A-F]*  {return T_HEX       ;}
0[0-1]*b                  {return T_BIN       ;}
[ \t\n]                   ; /* skip whitespace */

(\[\$([^$]|[\r\n]|(\$+([^*\]]|[\r\n])))*\$+\])  ;/*skip comments the carraige symbol is for windows only, but I included it becuase the regex tester I was useing complained*/                      
.                     yyerror((char *) "invalid character");


%%

/***************************************************************************
	Stop replacing code here
***************************************************************************/

int yywrap(void) {
	return 1;
}
