//
//  main.cpp
//  kadane's algo
//
//  Created by Ishnoor Singh Sethi
//

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int sum=0, mx=INT_MIN, st=1, tst=0, en=0,ans=-1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        mx=max(mx,sum);
        if(sum>=0){
            if(sum>ans){
                ans=sum;
            st=tst;
            en=i;
            }
        }
        else{
            sum=0;
            tst=i+1;
        }
    }
    cout<<mx<<endl<<st<<endl<<en<<endl;
    return 0;
}
