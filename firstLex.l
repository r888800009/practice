%option noyywrap
%%
[0-9]+ number(yytext);
%%

void number(char *str){
  printf("hello world: %s\n", str);
}

int main() {
  yylex();
  return 0;
}
