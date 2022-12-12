#ifndef FUNTIONS
#define FUNTIONS

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


void copy_array(vector<int> &a, vector<int> &b){
    for(int i = 0; i < a.size(); i++)
        b[i] = a[i];
}

template<typename T>
void my_swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}


void display_array(int array[], int size){
    for(int i = 0; i < size; i++)
        cout<< array[i]<< " ";
    cout<<endl;
}

void fill_array(int array[], int size, int value){
    for(int i = 0; i < size; i++)
        array[i] = value;
}


void fill_array(vector<int> array, int value){
    for(int i = 0; i < array.size(); i++)
        array[i] = value;
}

void display_array(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout<< array[i]<< " ";
    cout<<endl;
}

vector<int> generate_array(int size){
    vector<int> array;

    srand(time(NULL));

    for(int i = 0; i < size; i++)
        array.push_back(rand() % 1000);
    return array;
}

void generate_array(int array, int size){
    srand(time(NULL));

    for(int i = 0; i < size; i++)
        array[i] = rand() % 50;
}


#endif