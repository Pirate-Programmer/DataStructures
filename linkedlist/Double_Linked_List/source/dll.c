#include"dll.h"

//add new nodes in front of existing linkedlist
/*
@param list: head ptr of list
@param data: data to be stored in list
*/
node* prepend(node* list, Object data)
{
    node* temp = (node* )malloc(sizeof(node));
    if(temp == NULL)
        return list;

 //connect this new node in front of the linked list
    temp->data = data;
    temp->next = NULL;  
    temp->prev = NULL;
    if(list == NULL)
        return temp;

 //set head to new node
    temp->next = list;
    list->prev = temp;
    list = temp; 
    return list;
}

//appends new nodes in  linkedlist
node* append(node* list, Object data)
{
    node* temp = (node* )malloc(sizeof(node));
    if(temp == NULL)
        return list;
    
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;

    if(list == NULL)
        return temp;

//iterate to the last node in linkedlist
    node* iterator = list;
    while(iterator->next != NULL)
        iterator = iterator->next;
//connect new node
    iterator->next = temp;
    temp->prev = iterator;
    return list;
}

node* insert(node* head, Object data, int idx)
{
    node* temp = (node* )malloc(sizeof(node));
    if(temp == NULL)
        return head;

    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;
    if(head == NULL)
        return temp;

    //if condition of prepend are meet (idx <= 1)
    if(idx <= 1)
    {
        temp->next = head;
        head->prev = temp;
        return temp;
    }

    node* iterate = head;
    //we start at postion to begin with
    //if idx = 2 ie one after the first node
    //if we don't idx-- then for idx == 2
    //iterate will move to the second idx
    idx--;
    while((idx--) > 1 && iterate->next != NULL)
        iterate = iterate->next;

    if(idx == 0 && iterate->next != NULL)
    {
        temp->next = iterate->next; 
        temp->prev = iterate;
        iterate->next->prev = temp;
        iterate->next = temp;
    }
    else //condition where idx != 0 ie iterate == NULL
    {
        iterate->next = temp;
        temp->prev = iterate;
    }
    return head;
}

bool deleteByValue(node** list,Object data)
{
    if(*list == NULL)
        return false;

    node* curr = *list;
    if((*list)->data == data)
    {
        *list = (*list)->next;
        (*list)->prev = NULL;
        free(curr);
        return true;
    }
    while((curr = curr->next) != NULL)
    {
        if(curr->data == data)
        {
           curr->prev->next = curr->next;
           if(curr->next != NULL)
                curr->next->prev = curr->prev;
            free(curr);
            return true;
        }
    }
    return false;
}

bool deleteByPosition(node** list,int postion)
{
    if(*list == NULL)
        return false;
    
    node* curr = *list;
    if(postion == 1)
    {
        *list = (*list)->next;
        (*list)->prev = NULL;
        free(curr);
        return true;
    }

    while((postion--) > 1 && curr->next != NULL)
        curr = curr->next;

    if(postion == 0)
    {
        curr->prev->next = curr->next;
        if(curr->next != NULL)
            curr->next->prev = curr->prev;
        free(curr);
        return true;
    }
    return false;
}

node* get_tail(node* list)
{
    if(list == NULL)
        return NULL;
    else if(list->next == NULL)
        return list;
    return get_tail(list->next);
}

int get_length(node* list)
{
    if(list == NULL)
        return 0;
    int len = 1;
    while((list = list->next) != NULL)
        len++;
    return len;
}


void print_list(node* list)
{
    if(list == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        //prints start to end
        printf("%d  ",list->data);
        print_list(list->next);
    }
    //prints end to start
    //printf("%d -> ",list->data);
    return;
}


node* reverse_iterative(node* list)
{
    node* iterative = list;
    while(iterative != NULL)
    {
        list = iterative;
        node* temp = iterative->next;
        iterative->next = iterative->prev;
        iterative->prev = temp;
        iterative = temp;
    }
    return list;
}

node* reverse_recursion(node* list)
{}


void print_list_reverse(node* head)
{
    print_using_tail(get_tail(head));
    printf("\n");
    return;

}

void print_using_tail(node* tail)
{
    if(tail == NULL)
        return;
    else
    {
        printf("%d  ",tail->data);
        print_using_tail(tail->prev);
    }
    return;
}




void free_node(node* list){
    if(list != NULL)
        free_node(list->next);
    free(list);
    return;
}
