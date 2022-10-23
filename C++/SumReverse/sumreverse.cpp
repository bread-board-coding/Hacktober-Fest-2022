//Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.

#include<bits/stdc++.h>
using namespace std;

bool sumOfNumberAndReverse(int num) {
        
        for(int i=0;i<=num;i++)
        {
            int n=i;
            int m=0;
            while(n>0)
            {
                int r=n%10;
                m=m*10+r;
                n=n/10;
            }
            if(i+m==num)
            {
                return true;
            }
        }
        return false;
    }
    
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<sumOfNumberAndReverse(n);
}
