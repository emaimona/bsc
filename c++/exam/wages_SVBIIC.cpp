#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>



/* 
A program that determines what the average wage is, who has the highest wage,
who has the lowest wage, and who has the wages below average of a list in which
the wages of 50 people are stored (in EUR).

*** Warning: In the output, the index start at 1! because of the final user ***

*/

using namespace std;


/* Struct to hold variables 
*/
struct Wage{
    vector<double> vet;
    double randWage, averageWage, highestWage, lowestwage, highestWage_Id, lowestwage_Id;
};

/* Checks if the given number is in the vector
Return: true if found, otherwise false. 
*/
bool isInTheVector(vector<double> vet, double num) {
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] == num)
            return true;
    }

    return false;
}


/* Return: The average wage of the vector  
*/
double getAverageWage(vector<double> vet)
{
    double sum = 0;

    for (int i = 0; i < vet.size(); i++)
        sum += vet[i];

    return (sum / 50);
}


/* Generates random points between 0 and 1 */
double random_fun(){
    return (double)rand() / RAND_MAX; 
}


/* Generate 20 distinct numbers, divisible by 2 or 5
Return: a struct with a vector filled with the generated 
numbers and the av, lowest and highest wages. 
*/
struct Wage generateRandWages(){

    struct Wage myWage;
    
    vector<double> vet;
    double randWage, averageWage, highestWage = 0, lowestwage = 1000;
    double min = 150.0, max = 1000.0;

    int highestWage_Id, lowestWage_Id;

    srand((unsigned)time(NULL));

    for (int i = 0; i < 50; i++)
    {
        randWage = min + (max-min)*random_fun();;

        if (!isInTheVector(vet, randWage)){
            vet.push_back(randWage);

            if (randWage > highestWage){
                highestWage = randWage;
                highestWage_Id = i;
            }
            if (randWage < lowestwage){
                lowestwage = randWage;
                lowestWage_Id = i;
            }

        }
        else
            i--;
    }

    myWage.vet = vet;
    myWage.highestWage = highestWage;
    myWage.lowestwage = lowestwage;

    myWage.highestWage_Id = highestWage_Id;
    myWage.lowestwage_Id = lowestWage_Id;

    myWage.averageWage = getAverageWage(vet);

    return myWage; 
}


/* Prints the wages of a given vector in Eur
Return: void 
*/
void printWage(vector<double> vet)
{
    for (int i = 0; i < vet.size(); i++)
        cout<<"Person ["<< i+1 << "] ==> "<< vet[i]<<" EUR"<< endl;

}


/* Prints the wages bellow the average
Return: void 
*/
void printWageBellowAverage(vector<double> vet, int average)
{
    for (int i = 0; i < vet.size(); i++)
        if (vet[i] < average)
        cout<<"Person ["<< i+1 << "] ==> "<< vet[i]<<" EUR"<< endl;

}




int main(){

    struct Wage myWage = generateRandWages();

    cout<< "\nLIST OF ALL WAGES"<<endl;
    printWage(myWage.vet);

    cout<< "\nLIST OF ALL WAGES BELLOW THE AVERAGE"<< endl;
    printWageBellowAverage(myWage.vet, myWage.averageWage);

    cout<<"\n\nSTATUS"<< endl;
    cout<< "Average wage: " << myWage.averageWage<<" EUR"<< endl;
    cout<< "The Highest wage: " << "Person ["<< myWage.highestWage_Id+1 << "] ==> "<< myWage.highestWage <<" EUR"<< endl;
    cout<< "The Lowest wage: "<< "Person ["<< myWage.lowestwage_Id+1 << "] ==> "<< myWage.lowestwage <<" EUR"<< endl;

    return 0;
}