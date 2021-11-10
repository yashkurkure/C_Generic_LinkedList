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

//Function that deletes and frees a node at index.
//returns 0 on success
//returns -1 on error
int deleteNodeAt(LinkedList* _linkedlist, int index);

//Function that appends _linkedlist2 to _linkedlist1 and returns an pointer to the 
// _linkedlist1 after append
LinkedList* appendLinkedList(LinkedList* _linkedlist1, LinkedList* _linkedlist2);



