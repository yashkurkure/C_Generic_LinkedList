#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/LinkedList.h"

void main()
{
  printf("Running Linked List Program...\n");
  LinkedList* l = newLinkedList();
  printf("Linked List Created\n");
  printf("Enter the number of random number to add to the LinkedList:\n");

  int length;
  scanf("%d", &length);
  
  srand(time(NULL));
  int i;
  for(i = 0; i < length; i++)
  {
    int num = rand();
    addDataToLinkedList(l, &num, sizeof(int));
  }
  
  Node* j = l->head;
  int indexCount = 0;
  printf("Printing the Linked List:\n");
  while(j != NULL)
  {
    printf("at index %d\t%d\n", indexCount , *((int*)(j->data)));
    j = j->next;
    indexCount++;
  }

  printf("Enter a index to delete:\n");
  int del_index;
  scanf("%d", &del_index);
  
  if(deleteNodeAt(l, del_index) == 0)
  {
    Node* j = l->head;
    int indexCount = 0;
    printf("Printing the Linked List after deleting index %d:\n", del_index);
    while(j != NULL)
    {
      printf("at index %d\t%d\n", indexCount , *((int*)(j->data)));
      j = j->next;
      indexCount++;
    }
  }
  else
  {
    printf("delete at index %d failed.\n", del_index);
  }

  printf("Freeing the Linked List from memory...\n");
  freeLinkedList(l);
  printf("Linked List memory freed\n");
}
