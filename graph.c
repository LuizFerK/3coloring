#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

struct graph {
  int v_num;
  int e_num;
  int **matrix;
};

Graph *GRAPH(int v_num) {
  Graph *g = malloc(sizeof(*g));;

  g->v_num = v_num;
  g->e_num = 0;

  g->matrix = malloc(v_num * sizeof(int*));

  for (int i = 0; i < v_num; i++) {
    g->matrix[i] = malloc(v_num * sizeof(int));
  }
  
  for (int i = 0; i < v_num; i++) {
    for (int j = 0; j < v_num; j++) {
      g->matrix[i][j] = 0;
    }
  }

  return g;
}

void GRAPHinsert_edge(Graph *g, Edge e) {
  if (g->matrix[e.v1][e.v2] == 0 && e.v1 != e.v2) {
    g->matrix[e.v1][e.v2] = 1;
    g->matrix[e.v2][e.v1] = 1;
    g->e_num++;
  }
}

void GRAPHremove_edge(Graph *g, Edge e) {
  if (g->matrix[e.v1][e.v2] != 0) {
    g->matrix[e.v1][e.v2] = 0;
    g->matrix[e.v2][e.v1] = 0;
    g->e_num--;
  }
}

int GRAPHget_e_num(Graph *g){
  return g->e_num;
}

int GRAPHget_v_num(Graph *g) {
  return g->v_num;
}

void GRAPHprint(Graph *g) {
  for(int i = 0; i < g->v_num; i++) {
    printf("%d:", i);
    for (int j = 0; j < g->v_num; j++) {
      if (g->matrix[i][j]) printf(" %d", j);
    }
    printf("\n");
  }
}

static bool path(Graph *g, int v, int w, int marked[], int indent) {
  for (int i = 0; i < indent; i++) printf(" ");
  printf("path (%d, %d)\n", v, w);

  if (v == w) return true;

  marked[v] = 1;

  for (int u = 0; u < g->v_num; u++) {
    if (g->matrix[v][u] != 0) {
      if (marked[u] == 0) {
        if (path(g, u, w, marked, (indent + 4))) {
            return true;
        }
      }
    }
  }

  return false;
}

bool GRAPHpath(Graph *g, int v, int w) {
  int marked[g->v_num];

  for (int i = 0; i < g->v_num; i++) marked[i] = 0;

  return path(g, v, w, marked, 0);
}

// Breadth First Search
void GRAPHbfs(Graph *g, int v) {
  Queue *q = QUEUE();
  int marked[g->v_num];
  int parent[g->v_num];
  int dist[g->v_num];
  
  for (int i = 0; i < g->v_num; i++) marked[i] = 0;

  marked[v] = 1;
  parent[v] = -1;
  dist[v] = 0;

  QUEUEinsert(q, v);
  
  while (!QUEUEempty(q)) {
    int w = QUEUEremove(q);
    
    for (int u = 0; u < g->v_num; u++)
      if (g->matrix[w][u] != 0) {
        if (marked[u] == 0) {
          marked[u] = 1;
          parent[u] = w;
          dist[u] = dist[w] + 1;
          QUEUEinsert(q, u);
        }
      }
  }

  // Prints
  int count = g->v_num;
	int max = 0;

  for (int i = 0; i < g->v_num; i++) {
    if (marked[i] == 0) {
      printf("%d: infinita, sem caminho ate %d\n", i, v);
			count --;
    } else if (i == v) {
      printf("%d: 0, %d\n", i, i);
    } else {
      printf("%d: %d,", i, dist[i]);

      int aux = i;

      while (parent[aux] != -1) {
        printf(" %d", aux);
        aux = parent[aux];
      }

      printf(" %d\n", v);
    }
  }

	for (int i= 0; i<g->v_num; i++)
    if(marked[i] == 1 && dist[i] > max) {
			max = dist[i];
		}

	printf("%d\n", count);
	printf("%d\n", max);

  QUEUEwipe(q);
}

int GRAPH3coloring(Graph *g, int v, int colors[]) {
  // Verifica cada aresta do grafo
  for (int i = 0; i < v; i++) {                                                   // ≤ v
    for (int j = 0; j < v; j++) {                                                 // ≤ v
      // Verificar se existe uma aresta entre os vértices i e j
      if (g->matrix[i][j] > 0) {                                                  // ≤ v
        // Se os vértices adjacentes têm a mesma cor, a coloração não é válida
        if (colors[i] == colors[j]) {                                             // ≤ v
          return 0;                                                               // ≤ 1
        }
      }
    }
  }

  int max = 0;                                                                    // ≤ 1

  // Encontra a quantidade de cores do grafo
  for (int i = 0; i < v; i++) {                                                   // ≤ v
    if (colors[i] > max) {                                                        // ≤ v
      max = colors[i];                                                            // ≤ v
    }
  }

  // Se o grafo precisa de mais de 3 cores, a coloração é inválida
  if (max > 2) {                                                                  // ≤ 1
    return 0;                                                                   // ≤ 1
  }

  // Se nenhum par de vértices adjacentes têm a mesma cor, a coloração é válida
  return 1;                                                                       // ≤ 1
}

void GRAPHwipe(Graph *g) {
  for (int i = 0; i < g->v_num; i++) free(g->matrix[i]);
  
  free(g->matrix);
  free(g);
}
