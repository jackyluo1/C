// Compile this assignment with: gcc -g -Wall main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
      dll_t * dll = create_dll(){
      dll_t* newlist = (dll_t*)malloc(sizeof(dll_t));
      newlist -> head = NULL;
      newlist -> tail = NULL;
      newlist -> count = 0;
}

      item = create_item(dll_t* list,int data){
      node_t* item = (node_t*)malloc(sizeof(node_t));
      item -> data = data;
}
  
  void dll_push_front (dll_t* item, int data){
     item = head -> prevous;
     free(head);
     head = item;
     head -> previous = NULL;     
}

  void dll_push_back (dll_t* item, int data){
     tail -> next = item;
     tail = item;     
     item -> next = NULL;
}
     
  void dll_pop_front(dll_t* temp_node, int data){
     temp_node = head -> next;
     free(head);
     head = temp_node;
     head -> previous = NULL;
}

  void dll_pop_back(dll_t* temp_node, int data){
    temp_node -> next = tail;
    free(tail);
    tail = temp_node;
    tail -> next = NULL；
} 
    
  void dll_insert(dll_t* item, dll_t* pos, int data){
     item_next = pos;
        if(pos_previous = NULL and  item_previous = NULL;）{
            head = item;
        }
        else(item_previous = pos_previous and 
               pos_previous -> next = item){
               pos_previous = item;
         }
    
   void dll_get(dll_t* pos, int node, int data){
       pos -> next = head;
   if( head -> previous  = NULL; head = pos)
         }
 
   void dll_remove(dll_t* pos, int data){
   if(pos_previous = NULL){ free(head); head = pos_next;}   
   if(pos_next = NULL){ free(tail); tail = pos_previous;}
   }
           
   return 0;
}
