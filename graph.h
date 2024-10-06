#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAT_AT(g, i, j) (g).data[(i) * g.size + (j)]
#define MAT_AT_PTR(g, i, j) (g->data)[(i) * (g->size) + (j)]

// TODO:
// Add adding nodes to graphs [X]
// Add removing nodes from graph [X]

size_t N; // Size of matrix

typedef struct {
  int head;
  int *con_points;
  int size;

} Connector;

typedef struct {
  size_t size; // We will only use square matrices
  int *data;   // the pointer to the matrix we need
} Graph;

Connector create_connect(int head, int *con_points) {
  Connector C;
  C.head = head;
  C.con_points = con_points;
  C.size = sizeof(con_points) / sizeof(con_points[0]);
  return C;
}

Graph new_graph(size_t size) {
  Graph g;
  g.size = size;
  g.data = (int *)malloc(sizeof(int) * size * size);
  return g;
}

void free_graph(Graph *graph) {
  graph->size = 0;
  free(graph->data);
}

void graph_print(Graph g) {
  for (size_t i = 0; i < g.size; ++i) {
    for (size_t j = 0; j < g.size; ++j) {
      printf("%d", MAT_AT(g, i, j));
    }
    printf("\n");
  }
}

Graph iden(Graph m) {
  for (size_t i = 0; i < m.size; ++i) {
    for (size_t j = 0; j < m.size; ++j) {
      if (i == j) {
        MAT_AT(m, i, j) = 1;
      }
    }
  }
  return m;
}

void init_graph_from_array(Graph g, size_t array[N][N]) {
  for (size_t i = 0; i < g.size; ++i) {
    for (size_t j = 0; j < g.size; ++j) {
      MAT_AT(g, i, j) += array[i][j];
    }
  }
}

int *row_i(Graph g, size_t row_index) {
  assert(row_index < g.size);
  int *row = (int *)malloc(sizeof(int) * g.size);
  for (size_t i = 0; i < g.size; ++i) {
    row[i] = MAT_AT(g, row_index, i);
  }
  return row;
}
int *col_i(Graph g, size_t col_index) {
  assert(col_index < g.size);
  int *col = (int *)malloc(sizeof(int) * g.size);
  for (size_t i = 0; i < g.size; ++i) {
    col[i] = MAT_AT(g, i, col_index);
  }
  return col;
}

int mat_at(Graph g, int row, int col) { return MAT_AT(g, row, col); }

void add_node(Graph *g) {
  size_t new_size = g->size + 1;
  // sizeof(connect) /
  // Reallocate memory    sizeof(connect[0]); for the new matrix
  int *new_data = (int *)malloc(sizeof(int) * new_size * new_size);

  // Copy the existing matrix data to the new matrix
  for (size_t i = 0; i < g->size; ++i) {
    for (size_t j = 0; j < g->size; ++j) {
      new_data[i * new_size + j] = MAT_AT_PTR(g, i, j);
    }
  }

  // Initialize the new row and column for the new node and its connections
  for (size_t i = 0; i < new_size; ++i) {
    new_data[i * new_size + g->size] = 0;
    new_data[g->size * new_size + i] = 0;
  }

  // Update the graph properties
  free_graph(g);
  g->size = new_size;
  g->data = new_data;
}

void connect_node(Graph *g, Connector c) {
  for (size_t i = 0; i < c.size; ++i) {
    if (c.con_points[i] >= 0 && c.con_points[i] < g->size) {
      MAT_AT_PTR(g, c.head, c.con_points[i]) = 1;
      MAT_AT_PTR(g, c.con_points[i], c.head) = 1;
    }
  }
}

void rem_node(Graph *g, size_t n) {
  if (n >= g->size) {
    printf("Invalid vertex index.\n");
    return;
  }

  // Shift rows and columns to remove the vertex
  for (size_t i = n; i < g->size - 1; i++) {
    for (size_t j = 0; j < g->size; j++) {
      MAT_AT((*g), i, j) = MAT_AT((*g), i + 1, j);
    }
  }

  for (size_t j = n; j < g->size - 1; j++) {
    for (size_t i = 0; i < g->size - 1; i++) {
      MAT_AT((*g), i, j) = MAT_AT((*g), i, j + 1);
    }
  }

  g->size--;
}
