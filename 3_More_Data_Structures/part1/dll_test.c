// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall dll_test.c -o dll_test
//
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


// A sample collection of tests for your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.


// Tests creation and deletion of list
// Ideally does not cause any segfaults, and this
// is considered passing.
// Dll should also be empty.
int unitTest1(int status){
    int passed = 0;
    dll_t* test = create_dll();
    if(dll_empty(test)){

    	passed = 1;
    }
    free_dll(test);


    return passed;
}

// Tests push_front and size functions
int unitTest2(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_front(test,789);
    dll_push_front(test,788); 
    dll_push_front(test,787);
    dll_push_front(test,786);
    dll_push_front(test,785);
    dll_push_front(test,784);
    dll_push_back(test,790);
    show_list(test);
printf("%d\n",dll_size(test));
printf("pos2 = %d\n",dll_get(test, 2)) ; 
printf("pos4 = %d\n",dll_get(test, 4));
//   dll_pop_back(test);
  //  printf("remove 788\n");
//dll_remove_nodes(test,7855555);
//:w
printf("%d\n",dll_remove(test,4));
//show_list(test);
//printf("remove 786\n");
//dll_remove(test,3);
//show_list(test);

printf("%d\n",   dll_pop_front(test));

//printf("%d\n",dll_get(test, 789));
//printf("%d\n",dll_get(test, 788));
//printf("%d\n",dll_get(test, 787));
//    dll_insert(test, 3, 11);
show_list(test);
 /*   dll_pop_front(test);  
    dll_pop_front(test);   
    dll_pop_front(test);  
   */ 
   if(8==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_dll(test);

    return passed;
}


// Tests push_back and size functions
int unitTest3(int status){
    int passed = 0;
    dll_t* test = create_dll();
  //  dll_push_back(test,142);
// dll_push_back(test,143);  
 dll_push_back(test,144); 
// dll_push_back(test,145); 
// dll_push_back(test,146); 

// dll_push_back(test,147);
// dll_push_back(test,148);
// dll_push_back(test,149);
// dll_push_back(test,150);
// dll_insert(test,3,11);

show_list(test);
//   dll_remove(test,4);
// dll_remove_nodes(test,146);
//  show_list(test);
//dll_remove(test,7);
// dll_remove_nodes(test,149);
//  show_list(test);  
 
printf("%d\n",dll_pop_back(test)); 
dll_pop_back(test); 
show_list(test);
dll_pop_back(test);
show_list(test);  
 dll_pop_back(test); 
show_list(test); 
    if(2==dll_size(test)){
       passed = 1;
    }else{
       passed = 0;
    }
   free_dll(test);

    return passed;
}

// Tests push_front and dll_pop_back functions
int unitTest4(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test,142);
    dll_pop_back(test);
    if(0==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push_back twice, then pops once
// then should compute the correct size.
int unitTest5(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test,142);
    dll_push_back(test,132);
  dll_push_front(test,142);
dll_pop_back(test); 
dll_pop_front(test); 
    dll_pop_back(test);
    if(0==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_dll(test);

    return passed;
}

// TODO: Add more tests here at your discretion
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    NULL
};


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
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
