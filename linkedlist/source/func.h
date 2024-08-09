 #ifndef FUNC_H
 #define FUNC_H
 
 #include<stdbool.h>
 
 typedef struct node
{
    int element;
    struct node *next;
}node;

node *addFirst(node *list, int n); // prepends element
node *addLast(node* list, int n); //postpends element
node *add_sort(node* list, int n); // add element while maintaing order 

void print(node *list);  //print elements of node using recursion

void freelist(node *list);  //free up the memory of each node (recursive method) 

void reverselist(node **list); // calls reverselist and assign the new head(reverse order) to the current list pointer
node *reverse(node *list); //internal function used by reverselist

void reverseIterative(node** list); //iterative method to reverse the list
node* differnt_reverse_list(node*list, node*prev); //similar to reverse fun but joins the new chains before recursive call

bool delete_node(node** list,int value);

void sort(node** list); //sorts list by creating a clone and calling add_sort() to fill the new list

void bubblesort(node* list); //sorts using bubble_sort_algo
void selectionsort(node* list); //sorts using selection_sort_algo

bool contains(node* list, int k); //checks if the k is present in list return true if found or else false


#endif