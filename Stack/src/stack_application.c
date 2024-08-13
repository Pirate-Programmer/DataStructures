#include "stack.h"
#include<unistd.h>
#include<string.h>


int main(int argc, char* argv[])
{
     if(argc < 4)
    {
        printf("Usage: ./[path/file_name].exe -f [\"expression\"] -a/-p/-ap");
        return 0;
    }
    //Parsing Cmd Line Arguments
    int opt;
    bool a_flag = false, p_flag = false;
    char* expression;
    while((opt = getopt(argc, argv, ":apf:")) != -1)
    {
        switch(opt)
        {
            case 'f':
                expression = optarg;
                break;
        
            case 'a':
                a_flag = true;
                break;

            case 'p':
                p_flag = true;
                break;
        
            case ':':
                printf("Missing Req Argument for %c\n",optopt);
                break;

            defaut:
                printf("Invalid Flag --%c\n",optopt);
        }
    }

    //Parse the Expression

    //check if the expression is sematically correct ie contains only the req characters
    if(strspn(expression,"()[]{}0123456789+-*/ ") == strlen(expression));
    {
        printf("Expressions is semantically correct\n");
    }
}
