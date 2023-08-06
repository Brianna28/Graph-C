#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define MAT_AT(g,i,j) (g).data[(i)*g.size + (j)]

int N; //Size of matrix

typedef struct{
  size_t size; //We will only use square matrices
  int *data; //the pointer to the matrix we need
}Graph;

Graph new_graph(size_t size){
  Graph g;
  g.size = size;
  g.data = malloc(sizeof(int)*size*size);
  return g;
}


void graph_print(Graph g){
  for (size_t i = 0; i<g.size;++i){
    for (size_t j = 0; j<g.size;++j){
      printf("%d",MAT_AT(g,i,j));

    }
    printf("\n");
  }
}

Graph iden(Graph m){
  for (size_t i = 0; i<m.size; ++i){
    for (size_t j = 0; j<m.size; ++j){
      if (i==j){
        MAT_AT(m,i,j) = 1;
      }
    }
  }
  return m;
}



void init_graph(Graph g, int array[N][N]){
  for (size_t i = 0; i<g.size;++i){
    for (size_t j = 0; j<g.size;++j){
      MAT_AT(g,i,j) =  array[i][j];
    }
  }
}




int main()
{ 
  int size = 2;
  N = size;
  Graph G = new_graph(size);
  int array[2][2] = {{0,1},{1,0}};
  init_graph(G,array);
  graph_print(G);
  Graph C = iden(new_graph(4));
  graph_print(C);
  
  return 0;
}
