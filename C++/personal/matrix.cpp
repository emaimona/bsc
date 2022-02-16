#include <iostream>

using namespace std;
int main(){

    int nrow, ncol;
    
    cin>> nrow>> ncol;

    int** row = new int*[nrow];

    for(int i=1; i <= nrow; i++){

        int* col = new int(ncol);

        for(int j=1; j <= ncol; j++){
            cout<< "a"<<i<<j<< " ";
            cin>> col[j-1];
        }
        row[i-1] = col;
        cout<< endl;
    }

    for(int i=0; i < nrow; i++){
        for(int j=0; j < ncol; j++){
            cout<<row[i][j]<< " ";
        }
        cout<< endl;
    }

    for(int i=0; i < nrow; i++){  
        delete[] row[i];
    }
    delete [] row;
    row = NULL;
     
    return 0;
}