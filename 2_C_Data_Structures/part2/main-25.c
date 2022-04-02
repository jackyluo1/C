// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	stack_t* test1 = create_stack(MAX_DEPTH);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,1);	
	printf("Removing: %d\n",stack_dequeue(test1));	

	free_stack(test1);
}


// ====================================================
// ================== Program Entry ===================
// ====================================================

# include <stdio.h>
# include <stdlib.h>


# ifndef main_c
# define main_c
# define max_depth 32

typedef struct node{
        int data;
        struct node* next;
   }node_t;

typedef struct stack{
        int count;
        unsigned int capacity;
        node_t* head;
    }stack_t;

stack_t* create_stack(unsigned int capacity){
	
	stack_t* myStack = NULL;	

	return myStack;
}

int stack_empty(stack_t* s){

	return 0;
}

int stack_full(stack_t* s){

	return 0;
}

int stack_enqueue(stack_t* s, int item){
		return -1; 
}

int stack_dequeue(stack_t* s){

		return 9999999; 
}

unsigned int stack_size(stack_t* s){
	return 0;
}

void free_stack(stack_t* s){

}
