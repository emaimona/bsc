#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


/* 
This is a program that generates and calculates 20 different
random numbers that can be divided by 2 or 5 and the random 
numbers must be generated from 1 to 200, the same number 
cannot be included in the array! 

Restriction: The random number generation should be written in a function, 
ie the return value of the function should be an array

*** Warning: In the output, the index start at 1! because of the final user ***

*/

using namespace std;

/* Checks if the given number is in the vector
Return: true if found, otherwise false. 
*/
bool isInTheVector(vector<int> vet, int num) {
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] == num)
            return true;
    }

    return false;
}


/* Generate 20 distinct numbers, divisible by 2 or 5
Return: a vector filled with the generated numbers. 
*/
vector<int> generateRandNumber(){

    vector<int> vet;
    int randNum;

    srand (time(NULL));

    for (int i = 0; i < 20; i++)
    {
        randNum = rand() % 201 + 1;

        if ((randNum % 2 == 0) || (randNum % 5 == 0)){
            if (!isInTheVector(vet, randNum)){
                vet.push_back(randNum);
            }
            else
                i--;
        }
        else
            i--;
    }
    return vet;
}


/* Prints the elements of a given vector
Return: void 
*/
void printVector(vector<int> vet)
{
    for (int i = 0; i < vet.size(); i++)
        cout<<"["<< i+1 << "] ==> "<< vet[i]<< endl;
}

int main(){
    
    cout<<"OUTPUT"<<endl << endl;
    printVector(generateRandNumber());

    return 0;
}