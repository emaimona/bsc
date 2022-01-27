#include <iostream>
#include "Funtions.h"

using namespace std;

void sort_arr(vector<int> &a){
    int s = a.size();
    bool flag; int round = 0;
    for(int i = 0; i < s; i++){
        flag = false; round++;
        for(int j = 1; j < (s-i); j++){
            if(a[j] < a[j-1]){
                my_swap(a[j], a[j-1]);
                flag = true;
            }
        }
        if(!flag)break;
    }
    cout<<"Number of rounds: "<< round<<endl;
}

int main(){
    vector<int> a = gen_array(10);
    display_arr(a);
    sort_arr(a);
    display_arr(a);
    return 0;
}