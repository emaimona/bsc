#include <iostream>
#include <vector>
using namespace std; 

void insertSort(vector<int> &a) 
{ 
    for (int i = 1; i < a.size()-1; i++)
    { 
        if ( a[i-1] > a[i]){ 
            int current = a[i]; 
            a[i] = a[i-1]; 
            int j = i - 2; 
        while ( j >= 0 && a[j] > current) {
             a[j+1] = a[j]; j--; 
        } 
        a[j+1] = current; 
        } 
        } 

        for ( int i = 0; i < a.size(); i++){ 
            cout<<a[i] << " "; 
        } 
} 
        
int main () 
{ 
    vector<int> b (5);
    b[0] = 3;
    b[1] = 4;
    b[5] = 5;
    b[6] = 6;
    insertSort(b); 
}