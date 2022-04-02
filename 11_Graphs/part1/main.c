// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

int main(int argc, const char * argv[]) {
    graph_t * graph = create_graph();
//    printf("find 1 %d\n",find_node(graph,1));
    printf("add 1 %d\n",graph_add_node(graph, 1));
//    find_node(graph,1);
  //  printf("find 1 %d\n",find_node(graph,1)->data);
//    printf("add 1 %d\n", graph_add_node(graph, 1));
   // printf("find 2%d\n",find_node(graph,2));
    printf("add 2 %d\n",graph_add_node(graph, 2));
//    find_node(graph,2);
  //  printf("find 2 %d\n",find_node(graph,2)->data);
    printf("total nodes: 2==%d\n", graph_num_nodes(graph));
    

printf("add 3 %d\n",graph_add_node(graph, 3));
//printf("find 3 %d\n",find_node(graph,3)->data);
printf("add 4 %d\n",graph_add_node(graph, 4));
//printf("find 4 %d\n",find_node(graph,4)->data);
printf("add 5 %d\n",graph_add_node(graph, 5));
//printf("find 5 %d\n",find_node(graph,5)->data);
printf("add 6 %d\n",graph_add_node(graph, 6));
//printf("find 6 %d\n",find_node(graph,6)->data);
printf("total nodes: 6==%d\n", graph_num_nodes(graph));
//show_list(graph->nodes);

printf("###########\n");
//printf("add 1-3 %d\n",graph_add_edge(graph,1,3));
//printf("1-3 %d\n",contains_edge(graph,1,3));
printf("add 1-2 %d\n",graph_add_edge(graph,1,2));
//printf("find 2  %d\n",find_node(graph,2)->data);
//printf("1-2 %d\n",contains_edge(graph,1,2)); 
printf("add 2-4 %d\n",graph_add_edge(graph,2,4));
//printf("find 4 %d\n",find_node(graph,4)->data);
//printf("2-4 %d\n",contains_edge(graph,2,4)); 
//printf("add 3-5 %d\n",graph_add_edge(graph,3,5));
//printf("3-5  %d\n",contains_edge(graph,3,5));
//show_list(find_node(graph,1)->outNeighbors);
//show_list(find_node(graph,2)->outNeighbors);
//show_list(find_node(graph,3)->outNeighbors);
printf("add 4-6 %d\n",graph_add_edge(graph,4,6));
//printf("total edges: 5=%d\n", graph_num_edges(graph));
//printf("1-6 is reachable ?%d\n",is_reachable(graph,2,6));
//printf("3-6 is reachable ?%d\n",is_reachable(graph,1,6));


printf("is_reachable(graph,1,6) is :%d\n",is_reachable(graph,1,6));
printf("has cycle is %d\n",has_cycle(graph));
printf("print_path 1-4\n");
print_path(graph,1,4);


/*
printf("rm edges\n###############################################\n");
printf("del 1-2 %d\n",graph_remove_edge(graph,1,2));
//printf("find 1-3 %d\n",contains_edge(graph,1,3));

printf("del 2-4 %d\n",graph_remove_edge(graph,2,4));
//printf("find 1-2 %d\n",contains_edge(graph,1,2));
printf("total edges: 3=%d\n", graph_num_edges(graph));
show_list(find_node(graph,1)->outNeighbors); 
show_list(find_node(graph,2)->inNeighbors);
show_list(find_node(graph,2)->outNeighbors);
show_list(find_node(graph,3)->outNeighbors);


show_list(graph->nodes);
printf("Remove Nodes\n###########################################\n");
printf("del node_1,result: %d\n",graph_remove_node(graph, 1));

//printf("find 6 %d\n",find_node(graph,6)->data);  
printf("del node_2,result: %d\n",graph_remove_node(graph, 2));
//printf("find 5 %d\n",find_node(graph,5)->data);  
printf("del node_6,result:  %d\n",graph_remove_node(graph, 6));


printf("total nodes: 3==%d\n", graph_num_nodes(graph));
*/
//show_list(graph->nodes);

 

free(graph);
return 0;
}
