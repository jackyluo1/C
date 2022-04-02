// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
}


// ====================================================
// ================== Program Entry ===================
// ====================================================

struct quene{

       unsigned int T0  = 0x00;
       unsigned int T2  = 0x02;
       unsigned int T4  = 0x04; 
       unsigned int T6  = 0x06;
       unsigned int T8  = 0x08;
       unsigned int T10 = 0x0A;
       unsigned int T12 = 0x0C;
       unsigned int T14 = 0x0E;
       unsigned int T16 = 0x10;
       unsigned int T18 = 0x12;
       unsigned int T20 = 0x14;
       unsigned int T22 = 0x16;
       int* create_queue;
}
 
typedef struct queue queue_t;

    queue_t* create_queue(int create _queue){
             queue_t* myQueue = 
        
        





