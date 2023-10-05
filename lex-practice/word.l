%{
int i = 0;
%}
  
%%
([a-zA-Z0-9])*    {i++;} 
. {}
%%
  
int yywrap(void){}
  
int main()
{   
    yylex();
    printf("number of words : %d\n", i);
    return 0;
}