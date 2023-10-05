%{
    int ws = 0;
%}

delim [ \t\n]

%%
{delim}+ {ws++;}
. {}
%%

int yywrap(){
    return 1;
}

int main(){
    yylex();

    printf("number of whiteSpaces : %d\n", ws);

    return 0;
}