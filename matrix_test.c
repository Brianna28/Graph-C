#include "graph.h"


int main()
{ 
  size_t size = 3;
  N = size;
  Graph G = new_graph(size);
  size_t array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  init_graph_from_array(G,array);
  graph_print(G);
#if 0
  Graph C = iden(new_graph(4));
  graph_print(C);
  int* st_row = col_i(G,1);
  for (size_t i=0;i<G.size;++i) {
    printf("%d\n", st_row[i]);
  }
  printf("%d\n", mat_at(G,0,0));
  //free(G.data);
#endif
  int connect[] = {0,1};

  size_t numConnections = sizeof(connect)/sizeof(connect[0]);  // Increase the size of the matrix and copy old data
  add_node(&G,connect,numConnections);
  //rem_node(&G,0);
  graph_print(G);
  //free(C.data);
  //free(st_row);
  return 0;
}
