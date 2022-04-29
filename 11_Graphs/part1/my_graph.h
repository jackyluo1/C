// =================== Support Code =================
// Graph.
//
//
//
using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Create a graph data structure
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* nodes;     //an array of nodes storing all of our nodes.
}graph_t;

typedef struct graph_node{
    int data;
    dll_t* inNeighbors;
    dll_t* outNeighbors;
    int visited;
}graph_node_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t* create_graph(){
    // Modify the body of this function as needed.
    graph_t* myGraph= malloc(sizeof(graph_t));
    myGraph->nodes = create_dll();
    myGraph->numEdges = 0;
    myGraph->numNodes = 0;
    return myGraph;
}

// Returns the node pointer if the node exists.
// Returns NULL if the node doesn't exist or the graph is NULL
graph_node_t* find_node( graph_t * g, int value){
     if(NULL == g){
        return NULL;
     }
     if(NULL == g->nodes){
        return NULL;
     }

     if(NULL == g->nodes->head){
       return NULL;
     }

     node_t* temp = g->nodes->head;   
      
     while(temp != NULL){
          
           graph_node_t* g_node = temp->data;
           if(g_node->data == value){
              return g_node;
           }

           temp = temp->next;
               
     }

     return NULL;
}


// Creates a graph node
// Note: This relies on your dll implementation.
graph_node_t * create_graph_node(int value){
    graph_node_t * graph_node = malloc(sizeof(graph_node_t));
    
    if ( graph_node == NULL ) return NULL;
    
    graph_node->data = value;
    graph_node->inNeighbors = create_dll();
    graph_node->outNeighbors = create_dll();
    graph_node->visited = 0;   
    return graph_node;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node already exists )
// Returns -1 if the graph is NULL.
int graph_add_node(graph_t* g, int value){
    if ( g == NULL ) return -1;
    
    if (find_node(g, value) != NULL) return 0;
        
    graph_node_t * newNode = create_graph_node(value);
    if ( newNode == NULL ) return 0;

    assert(g->nodes);
    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    
    return 1;
}

int contains_edge( graph_t * g, int source, int destination){
    if ( g == NULL ) return -1; 
    if (find_node(g,source) == NULL) return 0; 
    if (find_node(g,destination) == NULL) return 0; 
    graph_node_t* s_node = find_node(g,source);  
    graph_node_t* d_node = find_node(g,destination);

    node_t* temp = s_node->outNeighbors->head;
    while(temp != NULL){
      if(temp->data == d_node){
          return 1;
      }
      temp = temp->next;
    }     
    return 0;  
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
// Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t * g, int source, int destination){
    //The function removes an edge from source to destination but not the other way.
    //Make sure you remove destination from the out neighbors of source.
    //Make sure you remove source from the in neighbors of destination.
    if ( g == NULL ) return -1; 
    if (find_node(g,source) == NULL) return 0;
    if (find_node(g,destination) == NULL) return 0;
    if (contains_edge(g,source,destination) == 0) return 0;    
    graph_node_t* s_node = find_node(g,source);
    graph_node_t* d_node = find_node(g,destination);
       
    node_t* temp = s_node->outNeighbors->head;
    while(temp != NULL){
          if(temp->data == d_node){ 
               
             dll_remove_nodes(s_node->outNeighbors,d_node);   
             dll_remove_nodes(d_node->inNeighbors,s_node); 
             g->numEdges--;
             return 1;     
          }
               
          temp = temp->next;
    }

    return 0;
    
}

// Returns 1 on success
// Returns 0 on failure ( or if the node doesn't exist )
// Returns -1 if the graph is NULL.
int graph_remove_node(graph_t* g, int value){
    // The function removes the node from the graph along with any edges associated with it.
    // That is, this node would have to be removed from all the in and out neighbor's lists that countain it.
    if(g == NULL) return -1;
    if(find_node(g,value) == NULL)  return 0; 
    
    graph_node_t* temp = find_node(g,value); 
/*
    if(temp->outNeighbors->count == 1 && temp->inNeighbors->count == 1){
           dll_remove_nodes(g->nodes, temp);
           node_t* in = temp->inNeighbors->head; 
           graph_node_t* indata = in->data;  
           dll_remove_nodes(indata->outNeighbors,temp);
           node_t* out = temp->outNeighbors->head;
           graph_node_t* outdata = out->data;
           dll_remove_nodes(outdata->inNeighbors,temp);
           
           dll_remove_nodes(temp->outNeighbors,outdata);
           dll_remove_nodes(temp->inNeighbors,indata);       
           free_dll(temp->inNeighbors);
           free_dll(temp->outNeighbors);
           free(temp);           
           g->numNodes--;
           g->numEdges--;
           g->numEdges--;
           return 1;
    }   
*/
    node_t* iter= temp->outNeighbors->head;
    while(iter != NULL){
          graph_node_t* Nei = iter->data;                 
//          dll_remove_nodes(temp->outNeighbors,Nei);
          dll_remove_nodes(Nei->inNeighbors,temp);
          g->numEdges--;      
          iter = iter->next;
    }

    node_t* iter1 = temp->inNeighbors->head;
    while(iter1 != NULL){
          graph_node_t* Nei1 = iter1->data;    
  //        dll_remove_nodes(temp->inNeighbors,Nei1);   
          dll_remove_nodes(Nei1->outNeighbors,temp);
          g->numEdges--;        
          iter1 = iter1->next;
    }

    
   free_dll(temp->inNeighbors);
   free_dll(temp->outNeighbors);
   dll_remove_nodes(g->nodes,temp);
   free(temp);   
   g->numNodes--;

    return 1;
}




// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
// Returns -1 if the graph is NULL.
int graph_add_edge(graph_t * g, int source, int destination){
    // The function adds an edge from source to destination but not the other way.
    // Make sure you are not adding the same edge multiple times.
    // Make sure you modify the in and out neighbors appropriatelly. destination will be an out neighbor of source.
    // Source will be an in neighbor of destination.
    if ( g == NULL ) return -1;  
    if (find_node(g,source) == NULL) return 0;
    if (find_node(g,destination) == NULL) return 0;
    if (contains_edge(g,source,destination) == 1) return 0; 
    graph_node_t* s_node = find_node(g,source);
    graph_node_t* d_node = find_node(g,destination);   
    dll_push_back(s_node->outNeighbors,d_node);
    dll_push_back(d_node->inNeighbors,s_node);
        
    g->numEdges++;
    return 1;
}


int show_edges_help(graph_t*g,int source){
    graph_node_t* s_node = find_node(g,source);
    if (find_node(g,source) == NULL) return 0;
    show_list_l(s_node->outNeighbors);
    show_list_l(s_node->inNeighbors);
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
// Returns -1 if the graph is NULL.
/*int graph_remove_edge(graph_t * g, int source, int destination){
    The function removes an edge from source to destination but not the other way.
    Make sure you remove destination from the out neighbors of source.
    Make sure you remove source from the in neighbors of destination.
    if ( g == NULL ) return -1; 
    if (find_node(g,source) == NULL) return 0;
    if (find_node(g,destination) == NULL) return 0;
    if (contains_edge(g,source,destination) == 0) return 0;    
    graph_node_t* s_node = find_node(g,source);
    graph_node_t* d_node = find_node(g,destination);
       
    node_t* temp = s_node->outNeighbors->head;
    while(temp != NULL){
          if(temp->data == d_node){ 
               
             dll_remove_nodes(s_node->outNeighbors,d_node);   
             dll_remove_nodes(d_node->inNeighbors,s_node); 
             g->numEdges--;
             return 1;     
          }
               
          temp = temp->next;
    }

    return 0;
    
}*/

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist )
// Returns -1 if the graph is NULL.
/*   move to before the remove_node function
int contains_edge( graph_t * g, int source, int destination){
    if ( g == NULL ) return -1; 
    if (find_node(g,source) == NULL) return 0; 
    if (find_node(g,destination) == NULL) return 0; 
    graph_node_t* s_node = find_node(g,source);  
    graph_node_t* d_node = find_node(g,destination);

    node_t* temp = s_node->outNeighbors->head;
    while(temp != NULL){
      if(temp->data == d_node){
          return 1;
      }
      temp = temp->next;
    }     
    return 0;  
}  move to before the remove_node function
*/
// Returns dll_t* of all the in neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getInNeighbors( graph_t * g, int value ){
   if(g == NULL) return NULL;
   if(find_node(g,value) == NULL) return NULL; 

   graph_node_t* temp = find_node(g,value);
   
   return temp->inNeighbors;
}

// Returns the number of in neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors( graph_t * g, int value){
    if(g == NULL) return -1; 
    if(find_node(g,value) == NULL) return -1;
    graph_node_t* temp = find_node(g,value);  

    return temp->inNeighbors->count;
}

// Returns dll_t* of all the out neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getOutNeighbors( graph_t * g, int value ){
    if(find_node(g,value) == NULL) return NULL;
    if(g == NULL) return NULL;  
    graph_node_t* temp = find_node(g,value);

    return temp->outNeighbors;
}

// Returns the number of out neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors( graph_t * g, int value){
    if(g == NULL) return -1; 
    if(find_node(g,value) == NULL) return -1;

    graph_node_t* temp = find_node(g,value); 

    return temp->outNeighbors->count;
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t* g){
    if(g == NULL) return -1; 
    
    return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t* g){
    if(g == NULL) return -1; 

    return g->numEdges;
}
int show_list(dll_t* l){
    if(NULL == l) return 0;
    node_t* p = l->head;
    if(p == NULL) return 0;
    printf("\nprint list->count is %d\n",l->count);
    for(int i = 0;i < l->count;i++){
      graph_node_t* temp = p->data;
      printf("%d,",temp->data);
      p = p->next;
    }
    printf("\n");
}

//Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the program terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t* g){
     while(g->numNodes){       
          node_t* pos = g->nodes->head;
          graph_node_t* temp = pos->data;
       for(int i = 0; i < dll_size(temp->outNeighbors);i++){
            graph_node_t* Nei = dll_get(temp->outNeighbors,i);
              dll_remove_nodes(temp->outNeighbors,Nei);
          }
         for(int i = 0; i < dll_size(temp->inNeighbors);i++){
           graph_node_t* Nei1 = dll_get(temp->inNeighbors,i);
             dll_remove_nodes(temp->inNeighbors,Nei1);
          }
         free(temp->outNeighbors);
         free(temp->inNeighbors);
         dll_remove_nodes(g->nodes,pos);
          g->nodes->head = g->nodes->head->next;
          g->numNodes--;
     }      
}


// returns 1 if we can reach the destination from source
// // returns 0 if it is not reachable
// // returns -1 if the graph is NULL (using BFS)
int is_reachable(graph_t * g, int source, int dest){
    if(NULL == g) return -1;

    dll_t* list = create_dll();
    graph_node_t* s_node = find_node(g,source);
    graph_node_t* d_node = find_node(g,dest);
 
    
    if(NULL == s_node) return 0;
    if(NULL == d_node) return 0;

    dll_push_back(list,s_node);       
    while(dll_size(list) != 0){
       graph_node_t* node = dll_pop_front(list);
           return 1;} 

          for(int i = 0; i < dll_size(node->outNeighbors); i++){
              graph_node_t* Nei = dll_get(node->outNeighbors,i);
              if(dll_contain_nodes(list,Nei) == 0){
                 dll_push_back(list,Nei);
              }
          }
    }
    free_dll(list);
    return 0;
}



void* print_path_help(graph_t* g,graph_node_t* destination, dll_t* stack){
    graph_node_t* pos = dll_pop_back(stack);
    dll_push_back(stack,pos);
    if(pos == destination) return stack;
    for(int i = 0; i < dll_size(pos->outNeighbors); i++){
       graph_node_t* Nei = dll_get(pos->outNeighbors,i);
       dll_push_back(stack,Nei);
       dll_t* l =  print_path_help(g,destination,stack); 
       if( l != NULL){
               return l;
       }
    }
    dll_pop_back(stack);
    return NULL;     
}

//     // prints any path from source to destination if there 
//     // exists a path from the source to the destination.
//     // Note: Consider using one of the other functions to help you
//     //       determine if a path exists first
//     // (Choose either BFS or DFS, typically DFS is much simpler)
//     //
//     // Returns 1 if there is a path from source to destination
//     // Returns 0 if there is not a path from a source to destination
//     // Returns -1 if the graph is NULL
int print_path(graph_t * g, int source, int destination){
   
    if(NULL == g)  return -1;
    if(is_reachable(g,source,destination) == 0) return 0;
   
    graph_node_t* s_node =find_node(g,source);
    graph_node_t* d_node =find_node(g,destination);
    dll_t* stack = create_dll();
    dll_push_back(stack,s_node);       
    print_path_help(g,d_node,stack);
    show_list(stack);
    free_dll(stack);
    return 1;         
}

/*
int has_cycle_help(graph_t* g, dll_t* list){
   graph_node_t *source = dll_pop_back(list);
   if(source->visited == 1) return 1; 
   source->visited = 1;
   for(int i = 0; i < dll_size(source->outNeighbors); i++){
        graph_node_t* node = dll_get(source->outNeighbors,i);
        dll_push_back(list,node);
        has_cycle_help(g,list);
   }
   dll_pop_back(list);
   return 0; 
} */


       
 // returns 1 if there is a cycle in the graph
// // returns 0 if no cycles exist in the graph
// // returns -1 if the graph is NULL 
// // You may use either BFS or DFS to complete this task.
int has_cycle(graph_t * g){
    if(NULL == g) return -1;
    
    dll_t* list= create_dll(); 
    node_t* node = g->nodes->head;
    graph_node_t* g_node = node->data;
    
    dll_push_back(list,g_node);       
    while(dll_size(list) != 0){
       graph_node_t* node = dll_pop_front(list);
       if( node->visited == 1){return 1;}  
       node->visited = 1;
       for(int i = 0; i < dll_size(node->outNeighbors); i++){
              graph_node_t* Nei = dll_get(node->outNeighbors,i);       
              dll_push_back(list,Nei);        
       }
    }
    for(int i = 0; i < dll_size(list); i++){
         graph_node_t* graph_node = dll_get(list,i);
         graph_node->visited = 0;
    }
    free_dll(list);    
    return 0;
}




#endif
