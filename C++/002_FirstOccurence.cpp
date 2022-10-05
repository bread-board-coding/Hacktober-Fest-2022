//wap to find the first occurence of the target value

#include <iostream>

using namespace std;

int main(){
    
    int arr[1000000];
    
    int n;
    cin>>n;

    int i=0;

    for(i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target value: ";
    cin>>target;

    for(i=0; i<n; i++){
        if(arr[i]==target){
            break;
        }
    }

    if(i==n){
        cout<<"Target is not present in the array!"<<endl;
    }
    else{
        cout<<i<<endl;
    }

    return 0;
}

