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

    node* list1 = NULL;
    node* list2 = NULL;
    for(int i = 1 ;i < argc; i++)
    {
        list1 = prepend(list1, atoi(argv[i]));
        list2 = append(list2, atoi(argv[i]));
    }
    print(list1);
    print(list2);
}