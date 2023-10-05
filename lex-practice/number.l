%{
    
%}
digit [0-9]
%%
[+-]?{digit}+(\.{digit}+)?(E[+-]?{digit}+)? {printf("number found : %s\n", yytext);}

. {}
%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}
