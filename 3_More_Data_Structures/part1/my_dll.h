#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>
// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
    int count;        // count keeps track of how many items are in the DLL.
    node_t* head;        // head points to the first node in our DLL.
    node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll(){
    // Modify the body of this function as needed.
    dll_t* myDLL= malloc(sizeof(dll_t));
    myDLL->count =0;
    myDLL->head = NULL;
    myDLL->tail = NULL;
    return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
// Returns -1 if the dll is NULL.
int dll_empty(dll_t* l){
    if(l == NULL) return -1;
    if(l->count > 0) return 0;
    if(l->count == 0) return 1;
}


// push a new item to the front of the DLL ( before the first node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){
    if( l == NULL) return -1;
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node==NULL)return 0;
    new_node->data = item;

    if(l->count == 0){
       new_node->next = NULL;
       new_node->previous = NULL;
       l->head = new_node;
       l->tail = new_node;

    }else{
       new_node->previous = NULL;
       new_node->next = l->head;
       l->head->previous = new_node;
       l->head = new_node;
    }
    l->count++;
    return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
    if( l == NULL) return -1;
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node==NULL)return 0;
    new_node->data = item;    

    if(l->count == 0){
       new_node->next = NULL;       
       new_node->previous = NULL;
       l->head = new_node;
       l->tail = new_node;

    }else{    
//FIXED
    new_node->previous = l->tail;
    new_node->next = NULL;
    l->tail->next = new_node;
    l->tail = new_node;
    }
  
    l->count++;
    return 1;
}

//Returns the first item in the DLL and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t* l){
      if(l->count == 0)
        return 0;
    if(l->count == 1)
    {   
        int value = l->head->data;
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->count = 0;
        return value;
    }
    
    node_t* tmp = l->head;
    l->head = tmp->next;
    l->head->previous = NULL;
    int val = tmp->data;   
    free(tmp);
    tmp = NULL;
    l->count--;

       return val; // Note: This line is a 'filler' so the code compiles
}
// Returns the last item in the DLL, and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t* l){
    if(l == NULL) return -1;
    if(l->count == 0)
        return 0;
    if(l->count == 1)
    {   int value = l->tail->data;
        free(l->tail);
        l->tail = NULL;
        l->head = NULL;
        l->count = 0;
        return value;
    }
    
    node_t* tmp = l->tail;
    l->tail = tmp->previous;
    l->tail->next = NULL;
    int val = tmp->data;
    free(tmp);
    tmp = NULL;
    l->count--;
    
        return val; // Note: This line is a 'filler' so the code compiles.
}

// Inserts a new node before the node at the specified position.
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
// Returns -1 if the list is NULL
int dll_insert(dll_t* l, int pos, int item){
    if(l == NULL)return -1;
    if(pos < 0 || pos >l->count)return 0;
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node==NULL)return 0;
    new_node->data = item;
  
    if(pos == 0){
       dll_push_front(l,item);
       return 1;
    }
    if(pos == l->count){
      dll_push_back(l,item);
      return 1;
    }
  
    
    node_t* p = l->head;
    
    for(int i = 0;i < pos; i++){
          p = p->next;
    }

    new_node->previous = p->previous;
    p->previous->next = new_node;
    new_node->next = p;
    p->previous = new_node;     
        l->count++;
        return 1; // Note: This line is a 'filler' so the code compiles.
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
//  (does not remove the item)
// Retruns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.


int dll_get(dll_t* l, int pos){
      if(l == NULL) return -1;
      if(pos < 0 || pos > l->count) return 0;
      node_t* p = l->head;
      for(int i = 0; i < pos;i++){         
           p = p->next;
      }
      if(p == NULL) return 0;
      return p->data;
      
 // Note: This line is a 'filler' so the code compiles.
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// RetrL on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Returns NULL if the list is NULL
// Assume no negative numbers in the list or the number zero.

//help_function
int dll_remove(dll_t* l, int pos){
    if(l == NULL)return -1;
    if(pos<0 || pos >l->count)return -1;
    if(pos == 1){
         node_t* temp = dll_pop_front(l);
          return temp->data;
    }
    if(pos == l->count){
       node_t* temp1 =  dll_pop_back(l);
          return temp1->data;
    }
 
    node_t* p = l->head;
    
    for(int i = 0;i < pos-1;i++){      
         p = p->next;
    }
    int val = p->data;  
    p->next->previous = p->previous;
    p->previous->next = p->next;
    free(p);
    p = NULL;
    l->count--;
    return val;
}

int dll_remove_nodes(dll_t* l, int value){
      if(NULL == l) return 0;    
       
      if(l->head->data == value){
          dll_pop_front(l);
          return 1;
      }      
      if(l->tail->data == value){
         dll_pop_back(l);
         return 1;
      }      
      int pos = 1;
      node_t* temp = l->head;
      while(temp != NULL){
         
         if(temp->data == value){ 
              dll_remove(l,pos);
              return 1;
         }

         temp = temp->next;
         pos++;
         }

         // Note: This line is a 'filler' so the code compiles.
}

// DLL Size
// Queries the current size of a DLL
// Returns -1 if the DLL is NULL.
int dll_size(dll_t* l){
   if(l == NULL)return -1;   
 
        return l->count; // Note: This line is a 'filler' so the code compiles.
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
//     node_t* temp = t->head;
     while(t->count != 0){
         node_t* temp = t->head;
         t->head = temp->next;
         free(temp);
         temp = NULL;
         t->count--;
     }

}

void show_list(dll_t* l){
     node_t* p = l->head;
     for(int i = 0;i<l->count;i++){     
       
          printf("%d,",p->data);  
          p = p->next;       
     }
     printf("\n");
}

#endif

