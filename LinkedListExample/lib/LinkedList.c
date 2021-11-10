#include <stdio.h>
#include <stdlib.h>

struct node
{
  void* data;
  struct node* next;
};

struct linkedlist
{
  int length;
  struct node* head;
  struct node* tail;
  
};

typedef struct node Node;
typedef struct linkedlist LinkedList;



LinkedList* newLinkedList()
{
  LinkedList* _linkedlist = (LinkedList*) malloc(sizeof(LinkedList));
  _linkedlist->head = NULL;
  _linkedlist->tail = NULL;
  _linkedlist->length = 0;
  
  return _linkedlist;
}


Node* addDataToLinkedList(LinkedList* _linkedlist, void *data, size_t size)
{
  //printf("[DEBUG] function: addDataToLinkedList()\n");
  Node* _node = (Node*) malloc(sizeof(Node));
  _node->data =  (void*) malloc(size);
  void* dataCopy = _node->data;
  
  //Copy the bytes of data at *data to *dataCopy.
  //We can do this by casting the pointer to a caharacter.
  //Since a character is 1 byte we can copy the data byte by byte.
  //This can work with any sort of data type that is 1 byte long.
  //TODO: create a files util.c and util.h.
  //TODO: util will define functions like copyBytes()
  char *pdata = (char*)data;
  char *pdataCopy = (char*)dataCopy;
  
  int i;
  //printf("[DEBUG]\tinitialized vairiables. Preparing to copy %ld bytes of data...\n", size);
  for(i = 0; i < size; i++)
  {
    pdataCopy[i] = pdata[i];
   // printf("[DEBUG]\t copied byte %d...\n", i);
  }
  //printf("[DEBUG]\tdone copying. Updatiung tail reference...\n");
  
  _node->data = dataCopy;
  _node->next = NULL;
  
  //printf("[DEBUG]\tassigned vales to new node\n");
  
  if(_linkedlist->tail == NULL)
  {
    //printf("[DEBUG]\tlinkedlist was empty...\n");
    _linkedlist->tail = _node;
    _linkedlist->head = _node;
    _linkedlist->length = 1;
    return NULL;
  }
  
  _linkedlist->tail->next = _node;
  Node* oldTail = _linkedlist->tail;
  _linkedlist->tail = _node;

  //printf("[DEBUG]\tupdated tail pointer. Returning with oldTail reference...\n");
  
  _linkedlist->length++;
  return oldTail;  
}


void freeLinkedList(LinkedList* _linkedlist)
{
  
  Node* head = _linkedlist->head;
  while(head!=NULL)
  {
    Node* temp = head->next;
    free(head->data);
    free(head);
    head = temp;
  }
  free(_linkedlist);

}

int deleteNodeAt(LinkedList* _linkedlist, int index)
{
  //LinkedList is empty, or something is wring is with the linked list
  if(_linkedlist->head == NULL || _linkedlist->tail == NULL)
    return -1;

  //Provided index is out of bound
  if(index < 0 || index >= _linkedlist->length)
    return -1;

  //Iterate over the linked list
  Node* curr;
  Node* prev = NULL;
  int indexCounter = 0;
  for(curr = _linkedlist->head; curr != NULL; curr = curr->next)
  {
    if(indexCounter == index)
    {
      break;
    }
    prev = curr;
    indexCounter++;
  }

  //delete the node at curr and reconnect the connections
  
  //index == 0, i.e, we are deleting the head
  if(prev == NULL)
  {
    _linkedlist->head = curr->next;
    free(curr->data);
    free(curr);
    return 0;
  }
  
  prev->next = curr->next;
  free(curr->data);
  free(curr);
  return 0;

}

LinkedList*  appendLinkedList(LinkedList* _linkedlist1, LinkedList* _linkedlist2)
{
  if(_linkedlist1 == NULL) return NULL;
  if(_linkedlist2 == NULL) return NULL;
  if(_linkedlist1->head == NULL)
  {
    if(_linkedlist1->tail == NULL)
    {
      return _linkedlist2;
    }
    else return NULL;
  }
  if(_linkedlist2->head == NULL)
  {
    if(_linkedlist2->tail == NULL)
    {
      return _linkedlist1;
    }
    else return NULL;
  }

  _linkedlist1->tail->next = _linkedlist2->head;
  _linkedlist1->tail = _linkedlist2->tail;
  return _linkedlist1;
}

/*
void main()
{
  //printf("Running Linked List Program...\n");
  LinkedList* l = newLinkedList();
  //printf("Linked List Created\n");
  int i = 1212;
  if( l == NULL) exit(0);
  addDataToLinkedList(l, &i, sizeof(int));
  
  Node* j = l->head;
  //printf("***PRINTING LINKED LIST***\n");
  while(j != NULL)
  {
    printf("0 \t%d\n", *((int*)(j->data)));
    j = j->next;
  }
  freeLinkedList(l);
}
*/






