#include <iostream>
#include "Funtions.h"

using namespace std;

void shell_sort(vector<int> &array){
    for(int i = 0, gap = (array.size()-1); gap != 0; gap /= 2, i = 0){
        for (int j = gap; j < array.size(); i++, j++){
            if(array[i] > array[j]){
                my_swap(array[i], array[j]);
                i--; j--;
                for (;i >= 0 && array[i] > array[j]; my_swap(array[i], array[j]), i--, j--);  
            }
        }
    }
}


int main(){
    vector<int> array = generate_array(10);
    display_array(array);
    shell_sort(array);
    display_array(array);

    return 0;
}