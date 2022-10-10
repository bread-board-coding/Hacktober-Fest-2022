#include<iostream>
using namespace std;
int * decToBinary(int n)
{
    int binaryNum[32];

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
     return binaryNum;
}
int fun(int num1,int num2)
{
    int answer=0;
    int *arr1=new int[32];
    int *arr2=new int[32];
    arr1=decToBinary(num1);
    arr2=decToBinary(num2);

    for(int i=0;i<32;i++)
    {
        if(arr1[i]!=arr2[i])
        answer++;
    }

    return answer;
}

int main()
{
    int ans=fun(7,10);
    cout<<ans<<endl;

    return 0;
}
