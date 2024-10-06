#include "graph.h"

int main() {
  size_t size = 3;
  N = size;
  Graph G = new_graph(size);
  size_t array[3][3] = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
  init_graph_from_array(G, array);
  graph_print(G);
  printf("\n");
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
  int connect[] = {0, 2};
  Connector c = create_connect(3, connect);
  add_node(&G);
  connect_node(&G, c);
  // rem_node(&G,0);
  graph_print(G);
  free_graph(&G);
  // free(C.data);
  // free(st_row);
  return 0;
}
