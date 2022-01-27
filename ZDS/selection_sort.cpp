#include <iostream>
#include <vector>
#include "Funtions.h"

using namespace std;

void sort_arr(vector<int> &arr){
    int temp;
    int s = arr.size();

    for(int i = 0; i < s; i++){
        for(int j = i + 1; j < s; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    vector<int> a = gen_array(10);
    display_arr(a);
    sort_arr(a);
    display_arr(a);

    return 0;
}