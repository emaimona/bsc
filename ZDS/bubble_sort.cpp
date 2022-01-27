#include <iostream>
#include "Funtions.h"

using namespace std;

void sort_arr(vector<int> &a){
    int s = a.size();
    
    for(int i = 0; i < s; i++){
        for(int j = 1; j < (s-i); j++){
            if(a[j] < a[j-1])
                my_swap(a[j], a[j-1]);
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