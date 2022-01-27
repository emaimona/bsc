#include <iostream>
#include <vector>
#include "Funtions.h"


void count_sort(vector<int> &array, int range){

    vector<int> output_array(array.size());
    vector<int> count_array(range, 0);

    //fill_array(count_array, 10, 0);

    for(int i = 0; i < array.size(); i++)
        count_array[array[i]]++;

    for(int i = 1; i < 10; i++)
        count_array[i] = count_array[i] + count_array[i-1];       

    for(int i = 0; i < array.size(); i++)
        output_array[--count_array[array[i]]] = array[i];

    for(int i = 0; i < array.size(); i++)
        array[i] = output_array[i];

}


int main(){
    vector<int> array = generate_array(10);
    display_array(array);
    count_sort(array, 10);
    display_array(array);
    return 0;
}