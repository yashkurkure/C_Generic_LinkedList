#include <stdio.h>
#include <stdlib.h>
#include "lib/LinkedList.h"

void main()
{
  printf("Running Linked List Program...\n");
  LinkedList* l = newLinkedList();
  printf("Linked List Created\n");
  int i = 1212;
  if( l == NULL) exit(0);
  addDataToLinkedList(l, &i, sizeof(int));
  
  Node* j = l->head;
  printf("***PRINTING LINKED LIST***\n");
  while(j != NULL)
  {
    printf("0 \t%d\n", *((int*)(j->data)));
    j = j->next;
  }
  freeLinkedList(l);
}
