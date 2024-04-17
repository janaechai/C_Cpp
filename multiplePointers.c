#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COLUMN 5
#define BREADTH 10
#define SPACE4 2
// Function prototypes
void ****create4D(int row, int column, int breadth, int space4);
void free4Dmemory(int *****pHypercube, int row, int column, int breadth, int space4);

int main(){
    int ****multi4 = (int****)create4D(ROW,COLUMN,BREADTH,SPACE4);
    free4Dmemory(&multi4,ROW,COLUMN,BREADTH,SPACE4);

//No memory leaks, tested using valgrind
    printf("total = %d\n",ROW*COLUMN*BREADTH*SPACE4);
    return 0;
}

void ****create4D(int row, int column, int breadth, int space4){
    int ****hypercube=(int****)malloc(space4 * sizeof(int***));
    int count = 1;
    for(int i=0;i<space4;i++){
        printf("space #%d\n",i);
        hypercube[i] = (int***)malloc(breadth * sizeof(int**));
        for(int j=0;j<breadth;j++){
            hypercube[i][j] = (int**)malloc(row * sizeof(int*));
            for(int k=0;k<row;k++){
                hypercube[i][j][k] = (int*)malloc(column * sizeof(int));
                for(int m=0;m<column;m++){
                    hypercube[i][j][k][m]= count;
                    printf("[%d][%d][%d][%d] is %d\t",i,j,k,m,hypercube[i][j][k][m]);
                    count++;
                }
                printf("\n");
            }
        }
    }
    return hypercube;
}

void free4Dmemory(int *****pHypercube,int row, int column, int breadth,int space4){
    for(int a=0;a<space4;a++){
        for(int b=0;b<breadth;b++){
            for(int c=0;c<row;c++){
                free((*pHypercube)[a][b][c]);
            }
            free((*pHypercube)[a][b]);
        }
        free((*pHypercube)[a]);
    }
    free(*pHypercube);
}
