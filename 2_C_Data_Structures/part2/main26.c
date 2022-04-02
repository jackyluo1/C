// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#tTest1(){

	stack_t* test1 = create_stack(MAX_DEPTH);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,1);	
	printf("Removing: %d\n",stack_dequeue(test1));	

	free_stack(test1);
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


viod push(stack_t* newhead,unsigned int capacity){
newhead -> capacity = capacaty +1;
return newhead;
}


viod pop(stack_t* newhead,unsigned int capacity){
newhead -> capacity = capacaty -1;
return newhead;
}

int main(){


if (stack_t = -1){
stack_t* newhead = push(capacity, count, node_t* newhead)
}

if (stack_t = 9999999){
stack_t* newhead = pop(capacity, count, node_t* newhead)
}

if (stack_t = 0, count = 0){
stack_t* newhead = push(capacity, count, node_t* newhead)
}

if (stack_t = 0, count > 0){
stack_t* newhead = pop(capacity, count, node_t* newhead)
}

    return 0;
}


	stack_t* newhead = create_stack(MAX_DEPTH);
	printf("Attempting to push %d\n",1);
	stack_enqueue(newhead,1);	
	printf("Removing: %d\n",stack_dequeue(newhead));	

	free_stack(newhead);



