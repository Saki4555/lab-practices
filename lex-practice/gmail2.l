%{

int flag=0;
%}
%%
[a-z.0-9_]+@[a-z]+".com"|".in" {printf("gmail found : %s", yytext); }

. {}
%%

int yywrap(){
    return 1;
}
int main()
{
yylex();
return 0;
}
 
