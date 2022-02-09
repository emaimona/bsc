#include <iostream>
#include <vector>
#include "Funtions.h"

using namespace std;

void merge_interval(vector<int> &a, int left, int mid, int right){
    int i = left;
    int j = mid+1;

    vector<int> temp(10, 0);

    while(i <= mid && j <= right){
        if(a[i] >= a[j]){
            temp.push_back(a[j]); ++j;
        }else{
            temp.push_back(a[i]);
            ++i;
        }
    }

    while(i <= mid){
        temp.push_back(a[i]);
        ++i;
    }

    while(j <= right){
        temp.push_back(a[j]);
        ++j;
    }

    display_array(temp);

    for(int n = left; n <= right; n++)
        a[n] = temp[n];

}

void merge_sort(vector<int> &a, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);
        merge_interval(a, left, mid, right);
    }
}


int main(){
    vector<int> a = generate_array(10);
    display_array(a);
    merge_sort(a, 0, a.size()-1);
    display_array(a);

    return 0;
}