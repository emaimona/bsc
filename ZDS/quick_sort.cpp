#include <iostream>
#include <vector>
#include "Funtions.h"

using namespace std;

int partition(vector<int> &a, int s, int e){
    int pivot = a[e];
    int Pindex = s;

    for(int i = s; i <= e; i++){
        if(a[i] < pivot){
            my_swap(a[i], a[Pindex]);
            Pindex++;
        }
    }
    my_swap(a[Pindex], a[e]);

    return Pindex;
}

void quick_sort(vector<int> &a, int s, int e){
    if(s < e){
        int p = partition(a, s, e);
        quick_sort(a, s, (p-1));
        quick_sort(a, (p+1), e);
    }
}

int main(){
    vector<int> a = gen_array(10);
    display_arr(a);
    quick_sort(a, 0, a.size()-1);
    display_arr(a);

    return 0;
}