#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#include "func.h"  //contains all the decelarations of linkedfunction

//Function defn
node *addFirst(node *list, int n)
{
    node *temp = (node *) malloc(sizeof(node));
    if (temp == NULL)
    {
        return NULL;
    }

    temp->element = n;
    temp->next = NULL;

    // this will add the current node in front of the line
    // basically the created chain will join this one and the new chain is assigned to list
    temp->next = list;
    return temp;
}

node* addLast(node * head, int n)
{
    node* temp = (node* )malloc(sizeof(node));
    if(temp == NULL)
    {
        return NULL;
    }

    temp->element = n;
    temp->next = NULL;

    //for the first element of the list
    //the head points to nothing so can't postpend on it
    if(head == NULL)
    {
    return temp;
    }

    //iterating to the last node and postpend the new node
    node* iterator = head;
    while(iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = temp;
    return head;
}

void print(node *list)
{
    if (list == NULL)
    {
        return;
    }
    else
    {
        printf("%i\n", list->element); // to print the list from start to end
        print(list->next);
    }
    // printf("%i\n",list->element);     //to print the list from end to start
}

//recursion to reach the last node and delete from there
void freelist(node *list)
{
    if (list == NULL)
    {
        return;
    }
    else
    {
        freelist(list->next);
    }
    free(list);
}


//calls internal fucntion reverse
//sets list to point to the last node ie reverse 
void reverselist(node **list)
{
    *list = reverse(*list);
}

//stictch all the nodes in reverse order and return the new head
//using recursion
node *reverse(node *list)
{
    node *head = NULL;
    if (list->next == NULL)
    {
        return list; //returning the new head the last node of the list before reversing
    }
        head = reverse(list->next);
        //list_next ie the next node. then next_node->next = list basically assigning the next node's pointer to the prev node
        (list->next)->next = list;  
        list->next = NULL;

    return head;
}


//reverse the list using iterative method
void reverseIterative(node** list)
{
    node* currentNode = *list;
    node *previousNode = NULL;
    node* nextNode = NULL;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    *list = previousNode;
}


//effecient recursion method to reverse list
node* differnt_reverse_list(node*list, node*prev){
    if(list == NULL){
        return prev;
    }
    node* next = list->next;
    list->next = prev;
    prev = list;
    return differnt_reverse_list(next,prev);
}

//iterative method to delete the first node 
//whose element matches the value
bool delete_node(node** list,int value){
   node* curr = *list;
   node* prev = NULL;

   //if value matches element of the first node
   if(curr->element == value){
    *list = curr->next;
     free(curr);
     return true;  //element found
   }
   else
   {
    for(prev = curr, curr = curr->next ; curr != NULL ; prev = curr,curr = curr->next)
     {
       if(curr->element == value)
       {
            prev->next = curr->next;
            free(curr);
            return true;  //element found
       } 
    }
   }

  return false;   // element not found 
}

//Adding nodes in a sorted manner
node* add_sort(node* head, int n)
{
    bool flag = false;
    node* temp = (node* )malloc(sizeof(node));
    if(temp == NULL)
    {
        return NULL;
    }

    temp->element = n;
    temp->next = NULL;

     //if list is empty add the first node
    if(head == NULL)
    {
        return temp;
    }

    node* prev = head;
    node* curr = head;

    for(curr = head; curr != NULL; prev = curr, curr = curr->next)
    {
        if(curr->element > n)
        {
           if(curr == head) //for the case when new node is prepended in the beginning
            {
                temp->next = curr;
                head = temp;
            }
            else
            {
              prev->next = temp;
              temp->next = curr;
            }
            flag = true;
            break;
        }
    }
    //if element not found i.e. prev is the last node and new node needs to be postpended
    if(!flag)
    {
        prev->next = temp;
    }
    return head;
}

/*
@param: **list pointer to the og list pointer
used to directly change the og list to the new one

creates a new linkedlist and adds element in a sorted manner
free the old list and assigns it the new head*/
void sort(node** list)
{
    node* new_head = NULL; 
    for(node* iterator = *list; iterator != NULL; iterator = iterator->next)
    {
        new_head = add_sort(new_head, iterator->element);
    }

    if(new_head != NULL)
    {
        freelist(*list); 
        *list = new_head;
    }
}

void bubblesort(node* list)
{
  for(node* iterator = list; iterator->next != NULL; iterator = iterator->next)
  {
    for(node* comparator = list; comparator->next != NULL; comparator = comparator->next)
    {
        if(comparator->element > comparator->next->element)
        {
            int temp = comparator->next->element;
            comparator->next->element = comparator->element;
            comparator->element = temp;
        }
    }
  }
}

void selectionsort(node* list)
{
   for(node* iterator = list; iterator != NULL; iterator = iterator->next)
  {
    node* temp = NULL;
    int min = iterator->element;
    for(node* comparator = iterator->next; comparator != NULL; comparator = comparator->next)
    {
        if(iterator->element > comparator->element)
        {
            temp = comparator;
            min = comparator->element;
        }
    }
    if(temp != NULL)
    {
    int temp_value = iterator->element;
    iterator->element = min;
    temp->element = temp_value;
    }
  }
}

bool contains(node* list, int k)
{
    if(list == NULL)
    {
        return false;
    }

    if(list->element == k)
    {
        return true;
    }
    return contains(list->next, k);
}

