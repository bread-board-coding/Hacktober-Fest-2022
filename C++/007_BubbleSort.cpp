#include <iostream>

using namespace std;

void sortArray(int arr[], int n){

    //base case
    if(n==0||n==1){
        return;
    }

    //recursive case
    for(int i=0; i<n; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    sortArray(arr, n-1);
}

int main(){

    int arr[1000000];

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sortArray(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


// #include <iostream>

// using namespace std;

// void sortArray(int arr[], int n){
//     //base case
//     if(n==0||n==1){
//         return;
//     }

//     //recursive case
//     for(int i=0; i<n; i++){
//         if(arr[i]>arr[i+1]){
//             swap(arr[i], arr[i+1]);
//         }
//     }

//     sortArray(arr, n-1);
// }

// int main(){

//     int arr[5]={2, 5, 1, 6, 9};

//     sortArray(arr, 5);

//     for(int i=0; i<5; i++){
//         cout<<arr[i]<<endl;
//     }

//     return 0;
// }