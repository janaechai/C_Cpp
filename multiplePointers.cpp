#include <iostream>
#define ROW 3
#define COLUMN 5
#define BREADTH 10
#define SPACE4 2
int ****create4D(int row,int column,int breadth,int space4){
    int ****hypercube = new int***[space4];
    int count=1;
    for(int i=0;i<space4;i++){
        hypercube[i] = new int**[breadth];
        for(int j=0;j<breadth;j++){
            hypercube[i][j] = new int*[row];
            for(int k=0;k<row;k++){
                hypercube[i][j][k]=new int[column];
                for(int m=0;m<column;m++){
                    hypercube[i][j][k][m]=count;
                    std::cout<<"["<<i<<"]["<<j<<"]["<<k<<"]["<<m<<"] = "<<hypercube[i][j][k][m]<<"\t";
                    count++;
                }
                std::cout<<std::endl;
            }
        }
    }
    return hypercube;
}
void free4Darray(int *****pHypercube,int row,int column,int breadth,int space4){
    for(int a=0;a<space4;a++){
        for(int b=0;b<breadth;b++){
            
            for(int c=0;c<row;c++){
                delete [](*pHypercube)[a][b][c];
            }
            delete [](*pHypercube)[a][b];
        }
        delete [](*pHypercube)[a];
    }
    delete [](*pHypercube);
}

int main(){
    int ****hypercube = create4D(ROW,COLUMN,BREADTH,SPACE4);
    free4Darray(&hypercube,ROW,COLUMN,BREADTH,SPACE4);
//freed all dynamically allocated memory on heap, no leak
//Error summay from valgrind: 0 error
    std::cout<<"total = "<<ROW*COLUMN*BREADTH*SPACE4<<std::endl;
    return 0;
}
