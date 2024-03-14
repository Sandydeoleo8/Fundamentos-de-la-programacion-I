#include <stdio.h>

//Apuntadores y arreglos.

void main(void)
{
    int v1[4] = {2, 3, 4, 7}, v2[4] = {6};
    int *ax, *ay;
    int i;
    int *ptr;

    for (ptr = &v1[2], i = 0; i < 4; i++)
    {
        *ptr += 1;
    }
    for (i = 0, ptr = &v1[0]; i < 4; i++, ptr++)
    {
        printf("\nv1[d]=%d", i, *ptr);
    }
    return;

    printf("\n-------------1------------");
    for(int i = 0; i < 4; i++)
    {
        printf("\nv1[%d]=%d", i, v1[i]);
    }
    printf("\n");
    for(int i = 0; i < 4; i++)
    {
        printf("\nv2[%d]=%d", i, v2[i]);
    }
    return;
    ax = &v1[3];
    ay = &v2[2];
    v1[v2[0]-v1[2]] = *ay;
    *ay = *ax - v1[0];
    printf("\nv1[0]=%d v1[1]=%d v1[2]=%d v1[3]=%d \tv2[0]=%d v2[1]=%d v2[2]=%d v2[3]=%d", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]);
    v2[1] = ++*ax;
    v2[3] = (*ay)++;
    *ax += 2;
    printf("\nv1[0]=%d v1[1]=%d v1[2]=%d v1[3]=%d \tv2[0]=%d v2[1]=%d v2[2]=%d v2[3]=%d", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]);

}
