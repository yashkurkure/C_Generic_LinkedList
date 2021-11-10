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

  LinkedList* l1 = newLinkedList();
  LinkedList* l2 = newLinkedList();

  int m;
  int k = 2;
  for(m = 1; m < 10 ; m = m + 2)
  {
    addDataToLinkedList(l1, &m, sizeof(int));
    addDataToLinkedList(l2, &k, sizeof(int));
    k = k+2;
  }

  LinkedList* l3 = appendLinkedList(l1,l2);
  
  j = l3->head;
  indexCount = 0;
  printf("Printing the Appended Linked List:\n");
  while(j != NULL)
  {
    printf("at index %d\t%d\n", indexCount , *((int*)(j->data)));
    j = j->next;
    indexCount++;
  }





}
