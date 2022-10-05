//wap to find out three largest numbers in an array

#include <iostream>
#include <climits>

using namespace std;

int main(){
    
    int arr[1000000];
    
    int n;
    cin>>n;

    int i;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int fL=INT_MIN;
    int sL=INT_MIN;
    int tL=INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i]>fL){
        tL=sL;
        sL=fL;
        fL=arr[i];
    }

        else if(arr[i]>sL){
            tL=sL;
            sL=arr[i];
        }
        else if(arr[i]>tL){
            tL=arr[i];
        }
    }

    
    cout<<fL<<" "<<sL<<" "<<tL<<" "<<endl;

    return 0;
}