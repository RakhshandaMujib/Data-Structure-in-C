#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct Node
{
    int item;
    struct Node* next;

}node;

node* create_list(); //Reads and creates a singly linked list of MAX elements.

int main()
{
    node *myList; 

    myList = create_list(); //myList stores the pointer to the head of the linked list.
    
    return 0;
}

node* create_list()
{
    int i;
    node *head, *temp, *current;

    current = (node*)malloc(sizeof(node*)); //Create an empty space for the first node.
    head = current; //Let the head point to the first node.
  
    printf("Enter %d values:\n", MAX);
     scanf("%d", &current->item);
  
    current->next = NULL;

    for(i = 1; i < MAX; i++)
    {
        temp = (node*)malloc(sizeof(node*)); //Create a temporary node.
          scanf("%d", &temp->item); //Store the item.
        current->next = temp; //Make the second last node created point to the newest created node.
        temp->next = NULL; //Let the newest created node point to NULL.
        current = temp; //Let the current node point to the newest node.
    }
  
    return head; //Return the head of the linked list.
}
