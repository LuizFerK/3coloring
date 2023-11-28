#include <stdio.h>
#include <stdlib.h>
#include "edge.h"

Edge EDGE(int v1, int v2) {
  Edge e;
  e.v1 = v1;
  e.v2 = v2;

  return e;
}
