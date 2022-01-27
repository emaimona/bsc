#include <iostream>
#include "Funtions.h"

using namespace std;

void sort_arr(vector<int> &a){
    int s = a.size();
    int j, key;

    for(int i = 1; i < s; i++){
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

}

int main(){
    vector<int> a = gen_array(10);
    display_arr(a);
    sort_arr(a);
    display_arr(a);
    return 0;
}