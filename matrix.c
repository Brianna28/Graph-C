#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#define MAT_AT(g,i,j) (g).data[(i)*g.size + (j)]

//TODO:
//Add adding nodes to graphs 
//Add removing nodes from graph


size_t N; //Size of matrix

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



void init_graph(Graph g, size_t array[N][N]){
  assert(N == g.size);
  for (size_t i = 0; i<g.size;++i){
    for (size_t j = 0; j<g.size;++j){
      MAT_AT(g,i,j) =  array[i][j];
    }
  }
}

int *row_i(Graph g, size_t row_index){
  assert(row_index < g.size);
  int* row = malloc(sizeof(int)*g.size);
  for (size_t i = 0; i<g.size; ++i){
    row[i] = MAT_AT(g,row_index,i);
  }
  return row;
}
int* col_i(Graph g, size_t col_index){
  assert(col_index < g.size);
  int* col = malloc(sizeof(int)*g.size);
  for (size_t i= 0; i<g.size; ++i){
    col[i] = MAT_AT(g,i,col_index); 
  }
  return col;
}

int mat_at(Graph g, int row, int col){
  return MAT_AT(g,row,col);
}

int main()
{ 
  size_t size = 2;
  N = size;
  Graph G = new_graph(size);
  size_t array[2][2] = {{0,1},{1,0}};
  init_graph(G,array);
  graph_print(G);
  Graph C = iden(new_graph(4));
  graph_print(C);
  int* st_row = col_i(G,1);
  for (size_t i=0;i<G.size;++i) {
    printf("%d\n", st_row[i]);
  }
  printf("%d\n", mat_at(G,0,0));
  return 0;
}
