%{

%}
letter [A-Za-z]
digit [0-9]
%%
{letter}({letter}|{digit})* {printf("identifier found : %s\n", yytext);}

. {}

%%


int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}