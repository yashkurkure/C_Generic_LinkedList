//Header file for a generic linked list in C


//Linked List node struct
struct node
{
  void* data;
  struct node* next;
};

//LinkeD List struct
struct linkedlist
{
  int length;
  struct node* head;
  struct node* tail;
};


typedef struct node Node;
typedef struct linkedlist LinkedList;

//Function that returns a pointer to a new empty linked list
LinkedList* newLinkedList();

//Function that adds data to the linked list.
//it returns a pointer to the old tail node.
//Note that this function appends to the linked list.
Node* addDataToLinkedList(LinkedList* _linkedlist, void *data, size_t size);


//Function frees the memeory of the linked list that was allocated on the heap.
//frees the nodes and the data.
void freeLinkedList(LinkedList* _linkedlist);
