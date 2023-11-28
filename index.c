#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "graph.h"

int main() {
  int v, e, c, x, y;

  printf("Insira o número de vértices e arestas do Grafo:\n");
  scanf("%d %d", &v, &e);

  int colors[v];
  
  Graph *g = GRAPH(v);

  for (int i = 0; i < e; i++) {
    printf("Aresta %d: ", i + 1);
    scanf("%d %d", &x, &y);

    GRAPHinsert_edge(g, EDGE(x, y));
  }

  for (int i = 0; i < v; i++) {
    printf("Cor do vértice %d: ", i);
    scanf("%d", &c);
    colors[i] = c;
  }

  if (GRAPH3coloring(g, v, colors)) {
    printf("3-COLORAÇÃO CORRETA!\n");
  } else {
    printf("3-COLORAÇÃO INCORRETA!\n");
  }

  GRAPHwipe(g);
}
