#include <iostream>
#include <vector>
#include <cmath>
#include "Funtions.h"

int get_max_number(vector<int> array){
    int greater = array[0];
    for(int i = 0; i < array.size(); i++){
        if(greater < array[i])
            greater = array[i];
    }

    return greater;
}


int get_number_of_digits(int number){
    return (number == 0)? 1: ((log10((number < 0) ? (number *(-1)) : number) + 1));
}

void count_sort(vector<int> &array, int div){
    vector<int> count_array(10, 0);
    vector<int> track_array(array.size(), 0);
    vector<int> output_array(array.size(), 0);
    int number, remainder;

    for(int i = 0; i < array.size(); i++){
        number = array[i];
        for(int k = 0; k < div; k++){
            remainder = number % 10;
            number /= 10;
        }
        track_array[i] = remainder;
        ++count_array[remainder];
    }

    for(int i = 1; i < 10; i++){
        count_array[i] =  count_array[i] + count_array[i - 1];
    }

    for(int i = array.size()-1; i >=0 ; i--){
        output_array[--count_array[track_array[i]]] = array[i];
    }

    copy_array(output_array, array);
}

void radix_sort(vector<int> &array){
    int number_of_digits = get_number_of_digits(get_max_number(array));

    for(int i = 1; i <= number_of_digits; i++){
        count_sort(array, i);
    }   

}

int main(){
    vector<int> array = generate_array(10);
    display_array(array);
    radix_sort(array);
    display_array(array);

    return 0;
}