#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main()
{
    FILE *fp;
    fp = fopen("M", "w");

    int size = 50;
    int high1 = 125;
    int high2 = 75;

    for (int i = 0; i < size; i++)
    {   
        int r = rand() % high1 + 1;
        fprintf(fp, "%d ", r);
    }

    fp = fopen("N", "w");
    for (int i = 0; i < size; i++)
    {
        int r = rand() % high2 + 1;
        fprintf(fp, "%d ", r);
    }
    
    return 0;
}
