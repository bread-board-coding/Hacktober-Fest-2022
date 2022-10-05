#include <iostream>
#include <climits>

using namespace std;

int main(){

    int arr[1000000];

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int fL=INT_MIN;
    int sL=INT_MIN;
    int tL=INT_MIN;

    int fS=INT_MAX;
    int sS=INT_MAX;

    for(int i=0; i<n; i++){
        if(arr[i]>fL){
            tL=sL;
            sL=fL;
            fL=arr[i];
        }
        else if(arr[i]>sL){
            tL=sL;
            arr[i]=sL;
        }
        else if(arr[i]>tL){
            arr[i]=tL;
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i]<fS){
            sS=fS;
            fS=arr[i];
        }
        else if(arr[i]<sS){
            sS=arr[i];
        }
    }

    int product1= fL*sL*tL;
    int product2= fL*fS*sS;

    cout<<"The maximum product is: "<<max(product1, product2)<<endl;

    return 0;
}
