#include<iostream>
using namespace std;
int ma(int arr[],int n)
{
    int maximum = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    return maximum;
}
int mi(int arr[],int n)
{
    int minimum = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }
    return minimum;
}

int main(){
    int n;
    cout<<"enter length of array: ";
    cin>>n;
    //int arr[n]; not a good practice
    int arr[1000];
    for(int i = 0; i<n;i++)
    {
        cout<<"enter element "<<i+1<<": "<<endl;
        cin>>arr[i];
    }
    int max = ma(arr,n);
    int min = mi(arr,n);
    cout<<"maximum element is: "<<max<<endl;
    cout<<"minimum element is: "<<min<<endl;

return 0; 
}