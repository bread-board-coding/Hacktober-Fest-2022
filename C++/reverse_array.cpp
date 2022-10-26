#include<iostream>
using namespace std;
void reverse(int arr[], int n)
{
    int temp = 0;
    for(int i = 0; i < n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n-(i+1)];
        arr[n-(i+1)] = temp;
    }
}
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        cout<<"enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    reverse(arr,n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


return 0; 
}