// Include our header file for our my_bst.c


// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode{
    int data;               
    struct bstnode* leftChild; 
    struct bstnode* rightChild;
}bstnode_t;



typedef struct bst{
    unsigned int size; 
    bstnode_t* root;   
}bst_t;
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


//help_insert function
int bst_help_insert(bstnode_t* pos,int item){
    if(pos == NULL){
       pos = (bstnode_t*)malloc(sizeof(bstnode_t));
       pos->leftChild = NULL;
       pos->rightChild = NULL;
       pos->data = item; 
       return;
    }

    if(pos->data <= item){
      bst_help_insert(pos->leftChild,item);
    }else{
      bst_help_insert(pos->rightChild,item);
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

          if(item <= val){            
               pos =  pos->leftChild;
          }else{
               pos = pos->rightChild;
          }
                  
        }

        if(item <= t->root->data){
             t->root->leftChild = new_node;
        }else{
             t->root->rightChild = new_node;
        }   
    }
      
    t->size++;
    return 1;    
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    }
         bstnode_t* pos = t->root;
      
         bst_print_help(pos,order);                    
             
          
 }    


int bst_print_help(bstnode_t* pos,int order){
    if(pos == NULL){
            return;
    }else{
          if(order == 0){
               bst_print_help(pos->leftChild,order);
               printf("%d\n",pos->data);
               bst_print_help(pos->rightChild,order);
           }else{
               bst_print_help(pos->rightChild,order);
               printf("%d\n",pos->data);
               bst_print_help(pos->leftChild,order);
           }      
    }

}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
    if(NULL == t){
            exit;   
    }
   
    if(t->size == 1){
          return t->root->data;
    } else{
         bstnode_t* pos = t->root;
         int sum = 0;
         while(!pos){
              int m = pos->data;
              int l = pos->leftChild->data;
              int r = pos->rightChild->data;
              sum = m + l + r;
         } 
         return sum;
    }
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
    bstnode_t* pos = t->root;
    int val =pos->data;

    if(NULL == t){
            exit;   
    }

    if(t->size == 1){
          if( val == value){
                          return 1;
          }else{
                          return 0;
          }
    }else{
          while(pos != NULL){
              if(val <= value){
                    pos = pos->leftChild;
              }else{
                    pos = pos->rightChild;
              }
          }
           
          if(val = value){
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
        exit;
   }else{    
        return t->size;
   }
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
     bst_freenode(t->root);
}

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

int unitTest1(){
    int result;
    bst_t * testBST = bst_create();
    if (testBST!=NULL){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;    
}


int unitTest2(){
    int result;
    bst_t * testBST = bst_create();
    bst_add(testBST,79);
    bst_add(testBST,77);



    bst_add(testBST,81);
    bst_add(testBST,76);
    bst_add(testBST,78);
    bst_add(testBST,80);
    result = bst_find(testBST,80);
bst_print(testBST,0);
bst_print_help(testBST->root,1);

    bst_free(testBST);    
    return result;
}


int unitTest3(){
    int result;
    bst_t * testBST = bst_create();
    bst_add(testBST, 10);
    bst_add(testBST, 8);
bst_add(testBST, 11);
bst_add(testBST, 7);
bst_add(testBST, 9);
bst_add(testBST, 12);
bst_print(testBST, 1);
bst_print_help(testBST->root,0);

  
    result = bst_sum(testBST);
    bst_free(testBST);   

    if(result==0){ 
        return 1;
    }
    return 0;
}



int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    NULL
};


int main(){
	
    unsigned int testsPassed = 0;

    int counter =0;
    while(unitTests[counter]!=NULL){
		printf("========unitTest %d========\n",counter);
		if(1==unitTests[counter](1)){
			printf("passed test\n");
			testsPassed++;	
		}else{
			printf("failed test, missing functionality, or incorrect test\n");
		}
        counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);

    return 0;
}

