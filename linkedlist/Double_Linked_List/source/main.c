#include "dll.h"

bool palindrome(node* head);
node* rotateNodes(node* list, int k);

int main(int argc, char** argv)
{
   // if(argc < 2)
     //   return 1;
    int idx[] = {1,2,3,4,5};
        node* head = NULL;
    for(int i = 1; i < argc; i++)
    {
        head = insert(head,atoi(argv[i]),9);
    }
    //printf("tail: %d\n",get_tail(head)->data);
    print_list(head);
    head = rotateNodes(head,2);
    print_list(head);
 /*   if(palindrome(head))
        printf("Palindrome!!\n");
    else
        printf("Not Palindromic\n");
*/

    //deleteByPosition(&head,5);
    //deleteByValue(&head,4);
    //deleteByPosition(&head,1);
    //head = reverse_iterative(head);
    //print_list_reverse(head);
   // printf("lenght slow: %d\n",get_length(head));
    free_node(head);
    return 0;
}

bool palindrome(node* head)
{
    if(head == NULL)
        return false;
    
    node* tail = get_tail(head);
    do
    {
        if(tail->data != head->data)
            return false;
        tail = tail->prev;
        head = head->next;
    }while(tail != head && tail->next != head->prev);
    return  true;
}

node* rotateNodes(node* list, int k)
{
    int len = get_length(list);
    k = k%len;
    len = len - k;

    if(k == 0)
        return list;
    
    node* iterate = list;
    while(len-- > 0)
    {
        iterate = iterate->next;
    }
    
    node* head = iterate;
    iterate->prev->next = NULL;
    head->prev = NULL;

    while(iterate->next != NULL)
        iterate = iterate->next;

    iterate->next = list;
    list->prev = iterate;
    return head;  
}