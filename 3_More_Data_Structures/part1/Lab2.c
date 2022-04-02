#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int winsofnubmer;
	struct node* next;
}node_t;


int main(){

    node_t year_2014;
    year_2014.winsofnubmer = 71;

    node_t year_2015;
    year_2015.winsofnubmer = 78;

    node_t year_2016;
    year_2016.winsofnubmer = 93;
    
    node_t year_2017;
    year_2017.winsofnubmer = 93;
   
    node_t year_2018;
    year_2018.winsofnubmer = 108;

 
    year_2014.next = &year_2015;
    year_2015.next = &year_2016;
    year_2016.next = &year_2017;
    year_2017.next = &year_2018;
    year_2018.next = NULL;


    
    
    node_t* iter;
    iter = &year_2014;
    
    while(iter != NULL){
          printf("year %d\n ",iter->winsofnubmer);
          iter = iter->next;
                        
    }


    return 0; 
}
