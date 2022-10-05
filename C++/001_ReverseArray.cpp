//wap to reverse an array:

#include <iostream>

using namespace std;


int main(){

    int arr[1000000];
    int n;
    cin>>n;

    int i=0;
    int j=n-1;

    for(int i; i<n; i++){
        cin>>arr[i];
    }    

    for(int i=0,j=n-1; i<j; i++,j--){
        swap(arr[i], arr[j]);
    }

    for(int i; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}

