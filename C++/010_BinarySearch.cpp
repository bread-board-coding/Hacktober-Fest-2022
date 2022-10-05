#include <iostream>

using namespace std;

void print(int arr[], int s, int e){
    for(int i=s; i<=e; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool BinarySearch(int arr[], int s, int e, int k){

    print(arr, s, e);

    int mid=s+(e-s)/2;

    //base case
    if(s>e){
        return false;
    }

    //element found
    if(arr[mid]==k){
        return true;
    }

    //recursive case
    if(arr[mid]<k){
        return BinarySearch(arr, mid+1, e, k);
    }
    else{
        return BinarySearch(arr, s, mid-1, k);
    }
}

int main(){
    int arr[1000000];

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int s=0;

    int e=n-1;

    int k;
    cin>>k;

    cout<<"Found or not: "<<BinarySearch(arr, s, e, k)<<endl;

    return 0;
}


