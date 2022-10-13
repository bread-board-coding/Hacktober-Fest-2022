#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int i = 0;
    int j = 0;
    while(i<n && j<n){
        if(arr[j] == 1){
            j++;
        }
        else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j = i;
        }
    }

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
