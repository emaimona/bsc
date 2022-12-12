#include <iostream>
#include "Funtions.h"

using namespace std;

void shell_sort(vector<int> &array){
    
    for(int gap = (array.size()-1); gap != 0; gap /= 2){

        int i = 0;
        int j = gap;

        while (i >= 0 && j < array.size()){
            if(array[i] > array[j]){
                my_swap(array[i], array[j]);
                i--; j--;
                while (i >= 0 && array[i] > array[j])
                {
                    my_swap(array[i], array[j]);
                    i--; j--;
                }
                
            }
            i++; j++;
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