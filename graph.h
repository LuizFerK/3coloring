#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "edge.h"

typedef struct graph Graph;

Graph* GRAPH(int n);

void GRAPHinsert_edge(Graph *g, Edge e);

void GRAPHremove_edge(Graph *g, Edge a);

int GRAPHget_e_num(Graph *g);

int GRAPHget_v_num(Graph *g);

void GRAPHprint(Graph *g);

bool GRAPHpath(Graph *g, int v, int w);

void GRAPHbfs(Graph *g, int v);

int GRAPH3coloring(Graph *g, int v, int colors[]);

void GRAPHwipe(Graph *g);

#endif /* GRAPH_H */
