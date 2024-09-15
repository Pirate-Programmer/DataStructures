#include<ctype.h>
#include<stdio.h>

#include"cll.h"



int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: ./[filename].exe [data]\n");
        printf("Ex: ./list.exe 3 2 5 2 235 2 \n");
        return 1;
    }

    node* list = NULL;
    for(int i = 1 ;i < argc; i++)
    {
        list = append(list, atoi(argv[i]));
    }
    print(list);
}