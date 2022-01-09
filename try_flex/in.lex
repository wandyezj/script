/*
flex tutorials
https://www.geeksforgeeks.org/flex-fast-lexical-analyzer-generator/

*/

/*
Definitions

*/
%{
   
   int count = 0;
%}


/*
pattern  action
*/
%%
[A-Z] {
    printf("\n[%s] - capitol letter", yytext);
    count++;
}
\r {}
.     {printf("\n[%s] - not a capital letter", yytext);}
\n    {return 0;}
%%

/*
    Code

    yywrap()
        - wraps the rules section
    yyin
        - take file pointer
    yylex()
        - runs the rules section
    yytext
        - text in the buffer
*/
int yywrap(){
    return 0;
}

int main(int argc, char **argv) 
{
    if (argc != 2) {
        // should pass in the file path
        printf("usage: script file");
        return 1;
    }
    
    char* file_path = argv[1];

    FILE *file;
    file = fopen(file_path, "r");
    if (!file) {
        printf("failed to open file [%s]", file_path);
        return 1;
    }

    yyin = file;

    // place output between two bars
    printf("\n-----\n");

    
    yylex();

    printf("\n-----\n");
  
  return 0;
}
