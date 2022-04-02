// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Modify the body of this function as needed.
    bst_t* myBST= NULL; 
    
    myBST =(bst_t*)malloc(sizeof(bst_t));
    myBST->size = 0;
    myBST->root = NULL;

    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    if( NULL == t){
        return 1;
    }else{
        return 0;
    }
}

// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item){
    bstnode_t* new_node;
    new_node = (bstnode_t*)malloc(sizeof(bstnode_t));
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->data = item;

    if(!new_node){
        return -1;
    }

    if(!t->root){
        t->root = new_node;
    }else{

        bstnode_t* pos = t->root;
        while(pos != NULL){
          int val = pos->data;

          if(item >= val){
             if(pos->leftChild != NULL){
                 pos =  pos->leftChild;
             }else{
                 pos->leftChild = new_node;
                 break;
             }
          }else{
             if(pos->rightChild != NULL){
                 pos = pos->rightChild;
             }else{
                 pos->rightChild = new_node;
                 break;
             }
          }

       }
    }
    
    t->size++;
    return 1;
     
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
/*int bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    }
    
    bstnode_t* pos = t->root;
    bst_print_help(pos,order);
}*/

int bst_print_help(bstnode_t* pos,int order1){
    if(pos == NULL){
            return 0;
    }else{
          if(order1 == 0){
               bst_print_help(pos->leftChild,order1);
               printf("%d\n",pos->data);
               bst_print_help(pos->rightChild,order1);
           }else{
               bst_print_help(pos->rightChild,order1);
               printf("%d\n",pos->data);
               bst_print_help(pos->leftChild,order1);
           }
    }
}

void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    }

    bstnode_t* p = t->root;
    bst_print_help(p,order);
    
}



// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
/*
int bst_sum(bst_t *t){
    if(NULL == t){
            exit(0);
    }

    if(t->size == 0){
          return 0;
    }
 
    bstnode_t* p = t->root;
    bst_sum_help(p);      
}
*/
int bst_sum_help(bstnode_t* pos){
    if(NULL == pos){
            return 0;
    }

    return pos->data + bst_sum_help(pos->leftChild)+bst_sum_help(pos->rightChild);
}


int bst_sum(bst_t *t){
    if(NULL == t){
            exit(0);
    }

    if(t->size == 0){
          return 0;
    }

    bstnode_t* p = t->root;
    return   bst_sum_help(p);
}




// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
    bstnode_t* pos = t->root;
    int val =pos->data;

    if(NULL == t){
            exit(0);
    }

    if(t->size == 1){
          if( val == value){
                          return 1;
          }else{
                          return 0;
          }
    }else{
          while(pos != NULL){
              if(val >= value){
                    pos = pos->leftChild;
              }else{
                    pos = pos->rightChild;
              }
          }

          if(val == value){
                          return 1;
          }else{
                          return 0;
          }
    }
} 
          
 

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
   if(NULL == t){
        exit(0);
   }else{    
        return t->size;
   }
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
/*
 void bst_free(bst_t* t){
 
     bst_freenode(t->root);
}
*/
int bst_freenode(bstnode_t* node){
    if(node){
      if(node->leftChild == NULL&&node->rightChild ==NULL){
           free(node);
      }else{
           bst_freenode(node->leftChild);
           bst_freenode(node->rightChild);
           free(node);
      }
    }
}

void bst_free(bst_t* t){
      bst_freenode(t->root);
      return;
}
