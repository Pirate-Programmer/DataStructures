#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include "func.h"


int main(int argv, char *argc[])
{
    // end program if no arguments passed
    if (argv < 2)
    {
        printf("Usage: ./linkedlist 4 6 2 ...\n");
        return 2;
    }

    node *list = NULL;
    // adding a node to list

//prepending
    for (int i = 1; i < argv; i++)
    {
        node* temp = addFirst(list, atoi(argc[i]));
        if (temp == NULL)
        {
            freelist(list);
            return 1;
        }
        list = temp;
    }

  // bubblesort(list);
   
//postpending
    // for(int i = 1; i < argv; i++)
    // {
    //     node* temp = addLast(list, atoi(argc[i]));
    //     if(temp == NULL)
    //     {
    //         freelist(list);
    //         return 1;
    //     }
    //     list = temp;
    // }

//inserting nodes in sorted manner
    //     for(int i = 1; i < argv; i++)
    // {
    //     node* temp = add_sort(list, atoi(argc[i]));
    //     if(temp == NULL)
    //     {
    //         freelist(list);
    //         return 1;
    //     }
    //     list = temp;
    // }

     print(list);


//    printf("Reverse List\n");
//    reverseIterative(&list);
//     print(list);

//     // printf("After Deleting\n");

//     // if(delete_node(&list,5)) printf("Deletion Failed");
//     // else  print(list);

     freelist(list);
}
