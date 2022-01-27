#include <iostream>

using namespace std;
int main(){

    int size, op;

    cout<<"Input the size of the DS: ";
    cin>> size;

    do{
        system("clear");
        cout<<"\nWhat operations to  perfom? Press 0 to exit.\n";
        cout<<"1. Enqueue()."<<endl;
        cout<<"2. Dequeue()."<<endl;
        cout<<"3. IsEmpty()."<<endl;
        cout<<"4. IsFull()."<<endl;
        cout<<"5. Count()."<<endl;
        cout<<"6. Display()."<<endl;
        cout<<"7. Clear Screen\n"<<endl;

        cin>>op;

        switch(op){
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
        }

    }while(op != 0);
    


    return 0;
}