#include <iostream>
using namespace std;

class stackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

    stackUsingArray(int capacity){
        data = new int[capacity];
        nextIndex = 0;
        this -> capacity = capacity;
        }

    int numberOfElements(){
        return nextIndex;
    }

    void push(int element){
        if(nextIndex == capacity){
            cout << "stack is full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int top(){
        if(nextIndex == 0){
            cout << "stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

    int pop(){
        if(nextIndex == 0){
            cout << "stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    void display(){
        if(nextIndex == 0){
            cout << "stack is empty" << endl;
            return;
        }
        for(int i = 0;i < nextIndex;i++){
            cout << data[i] << endl;
        }
        return;
    }
    };

int main(){

    cout << "enter the sizeof LL" << endl;
    int size;
    cin >> size;
    stackUsingArray s(size);

    cout << "MENU" << endl;
    cout << "1.push" << endl;
    cout << "2.top" << endl;
    cout << "3.display" << endl;
    cout << "4.pop" << endl;
    cout << "5.exit" << endl;
    int n;

    do{
        cout << "enter the choice" << endl;
    cin >> n;
        switch(n){
            case 1:{
                int t;
                cout << "enter the value" << endl;
                cin >> t;
                s.push(t);
                break;
            }

            case 2:{
               cout << s.top() << endl;
                break;
            }

            case 3:{
                s.display();
                break;
            }

            case 4:{
                cout << s.pop() <<endl;
                break;
            }

            case 5:{
                break;
            }
        }
    }while(n != 5);
    return 0;
}