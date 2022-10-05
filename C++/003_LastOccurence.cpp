//wap to find out the last occurence of an element in an array

#include <iostream>

using namespace std;

int main(){

    int arr[1000000];

    int n;
    cin>>n;

    int i;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target value: ";
    cin>>target;

    for(i=n-1; i>=0; i--){
        if (arr[i]==target)
        {
            break;
        }
        
    }

    if(i==-1){
        cout<<"Target not found!"<<endl;
    }
    else{
        cout<<i<<endl;
    }

    return 0;
}