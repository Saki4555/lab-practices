%{
    
%}

%%
if|else|while|for|do|break|continue|return|main|int|double|switch { printf("keyword found: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* {}
. {}

%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}
