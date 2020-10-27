#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int modThreshold = 1;

void printLists(int M[], int N[], int P[], int Q[], int R[], int size){
    printf(" %4s %4s %4s %4s %4s\n", "M:", "N:", "P:", "Q:", "R:");
    for (int i = 0; i < size; i++)
    {
         printf(" %4d %4d %4d %4d %4d\n", M[i], N[i], P[i], Q[i], R[i]);
    }
}

void findQandR ( int list1[], int list2[], int outputList[], int size ){
    for (int i = 0; i < size; i++)
    {   
        if (list1[i] == list2[i]){
            outputList[i] = 0;
        }
        else
        {
            int max = list1[i] > list2[i] ? list1[i] : list2[i];
            for (int j = max-1; j > 0; j--)
            {
                if( list1[i] % j <= modThreshold && list2[i] % j <= modThreshold ){
                    outputList[i] = j;
                    break;
                }
            }
        }    
    }
}

int main(int argc, char *argv[])
{
    int size = 50;
    if ( argc != 3){
        printf("must provide two input file names (M and N).\n");
        exit(-1);
    }

    char *mFile = argv[1];
    char *nFile = argv[2];

    //change to pointer to allow dynamic allocation for very large lists
    int M[size];
    int N[size];
    int P[size];
  
    FILE *fp;
    fp = fopen(mFile, "r");

    for (int i = 0; i < size; i++)
    {
        int num;
        fscanf(fp, "%d", &num);
        M[i] = num;
    }

    fp = fopen(nFile, "r");

    for (int i = 0; i < size; i++)
    {
        int num;
        fscanf(fp, "%d", &num);
        N[i] = num;
        if(M[i] > N [i])
            P[i] = M[i] - N[i];
        else
            P[i] = N[i] - M[i];
    }
    
    int Q[size];
    findQandR(M, N, Q, size);

    int R[size];
    findQandR(M, P, R, size);

    printLists(M,N,P,Q,R,size);
    
    return 0;
}

