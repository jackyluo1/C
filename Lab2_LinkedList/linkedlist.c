// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here
typedef struct node{
        int data;
        int year;
        struct node* next;
}node_t;

// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

void create_list(node_t *head){
     node_t* p = head;
     p->data = 0;
     p->year = 0;
     p->next = NULL;
     
}

void free_list(node_t* head){
     node_t* pos = head;               
     while(pos != NULL){
           pos = pos->next;
           free(pos);
     }
     
}

void print_list(node_t* head){
     node_t* pos = head;
     while(pos->next != NULL){
           pos = pos->next;
           printf("%d,%d wins\n",pos->year,pos->data);
     
     }
} 

void add_node(node_t* head,int year,int data){
     node_t* pos= head;
     node_t* newnode = (node_t*)malloc(sizeof(node_t));
     newnode->year = year;
     newnode->data = data;
     
        
     while(pos->next != NULL){
           pos = pos->next;
     }   
     
     pos->next = newnode;
     newnode->next = NULL;
}

int main(){
    node_t* head = (node_t*)malloc(sizeof(node_t));
    create_list(head);
    add_node(head,2014,71);
    add_node(head,2015,78);
    add_node(head,2016,93);
    add_node(head,2017,93);
    add_node(head,2018,108);
    print_list(head);  
   
    return 0;
}









