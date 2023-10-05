%{
    
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* { printf("identifier found: %s\n", yytext); }
. {}

%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}