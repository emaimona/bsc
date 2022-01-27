#include <iostream>

using namespace std;
class Queue{
private:
    int size, front, rear, counter;
    int *arr;
    bool *copy;

public:
    Queue(int sis){
        counter = 0;

        size = sis;
        front = -1;
        rear = -1;
        arr = new int(size);

        //to keep track if it has a value
        copy = new bool(size);
    }

    ~Queue(){
        delete[] arr;
        arr =  NULL;

        delete[] copy;
        copy =  NULL;
    }

    bool isFull(){
        if(((rear + 1) % size) == front )
            return true;
        else
            return false; 
    }

    bool isEmpty(){
        if(rear == -1 && front == -1)
            return true;
        else
            return false;
    }

    void enqueue(int val){
        if(isFull())
            cout<<"The queue is full.\n";
        else if(isEmpty()){
            rear = 0;
            front = 0;
            arr[rear] = val;

            copy[rear] = 1;
            counter++;

            cout<<"Enqueued .\n";
        }
        else{
            rear = (rear + 1) % size;
            arr[rear] = val;

            copy[rear] = 1;
            counter++;

            cout<<"Enqueued .\n";
        }
        
    }

    int dequeue(){
        int x;
        if(isEmpty()){
            cout<<"The que is empty .\n";
            return 0;
        }
        else if(rear == front){
            x = arr[rear];
            arr[rear] = 0;

            copy[rear] = 0;
            counter--;

            rear = -1;
            front = -1;

            return x;
        }
        else{
            x = arr[front];
            arr[front] = 0;

            copy[front] = 0;
            counter--;

            front = (front + 1) % size;
            return x; 
        }
    }

    int count(){
        return isEmpty()? 0: counter;
    }

    void display(){
        for(int i = 0; i < size; i++){
            if(copy[i] == 1)
                cout<<arr[i]<< " ";
            else   
                cout<<"X ";
        }
        cout<<"\n";
    }

};
int main(){

    int size, op, val;

    cout<<"Input the size of the DS: ";
    cin>> size;

    Queue q(size);

    do{
        
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
                cout<<"Input the value: ";
                cin>> val;
                q.enqueue(val);
                break;
            case 2:
                cout<< q.dequeue()<< " Dequed\n";
                break;
            case 3:
                cout<<"Is empty? "<<q.isEmpty()<<".\n";
                break;
            case 4:
                cout<<"Is full? "<<q.isFull()<<".\n";
                break;
            case 5:
                cout<<"The queue has: "<< q.count()<<" elements.\n";
                break;
            case 6:
                q.display();
                break;
            case 7:
                system("clear");
                break;
        }

    }while(op != 0);
    


    return 0;
}