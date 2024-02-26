#include <stdio.h>

// aauntadores y arreglos.

void main(void)
{
    int x = 5, y = 8, v[5] = {1, 3, 5, 7, 9};
    int *ay, *ax;
    ay = &y;
    x = *ay;
    *ay = v[3] + v[2];
    printf("\nx = %d    y = %d  v[0] = %d   v[1] = %d   v[2] = %d   v[3] = %d   v[[4] = %d", x, y, v[0], v[1], v[2], v[3], v[4]);
    ax = &v[v[0]*v[1]];
    x = *ax;
    y = *ax * v[1];
    *ax = *ay - 3;
    printf("\nx = %d    y = %d  v[0] = %d   v[1] = %d   v[2] = %d   v[3] = %d   v[[4] = %d", x, y, v[0], v[1], v[2], v[3], v[4]);
}
