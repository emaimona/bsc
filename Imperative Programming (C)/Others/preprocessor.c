#include <stdio.h>
#include <stdlib.h>
//#include "headers/sqrt.h"

#define BIGGER(x, y) ((x) < (y)) ? (y) : (x)
#define LIST_PARAMS(a, b, c) #a, #b, #c
#define FOR(var, from, to) for (int var = (form); var < (to); ++var)


// extern int glob;

// int** transpose(int* mtx[], int row, int col) {
//     int** result = (int**)malloc(sizeof(int*)*col);

//     for (int i=0; i<col; ++i) {
//         result[i] = (int*)malloc(sizeof(int*)*row);
//         for (int j=0; j<row; j++) {
//             result[i][j] = mtx[j][i];
//         }
//     }

//     return result;
// }

int main() {
    int m[2][3] = {
    {1,2},
    {3,5}
    };
    
   // printf("%d %d\n", BIGGER(1,2),  sqt(2));
    printf("%s %s %s\n", LIST_PARAMS(42, hello, A));

    // int row1[] = {1,2,3};
    // int row2[] = {4,5,6};
    // int* mtx[] = {row1, row2};

    // int **t = transpose(mtx, 2, 3);

    // for (int i=0; i<3; ++i) {
    //     for (int j=0; j<2; ++j)
    //         printf("%d", t[i][j]);
    //     printf("\n");
    // }

    return 0;
}