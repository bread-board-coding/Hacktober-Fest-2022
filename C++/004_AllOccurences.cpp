//wap to find out all occurences of an element in an array

#include <iostream>

using namespace std;

int main(){

    int arr[1000000];

    int n;
    cin>>n;

    bool flag=false; //assuming that the target is not present in the array

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the value of the target: ";
    cin>>target;

    for(int i=0; i<n; i++){
        if(arr[i]==target){
            flag=true;
            cout<<i<<endl;
        }
    }

    if(!flag){
        cout<<"Target is not present in the array! "<<endl;
    }

    return 0;
}