// Armstrong number program
// 153 has 3 digits so 1^3+5^3+3^3=1+125+27 = 153
#include<stdio.h>
#include<math.h>
int main() {
int a =153,ndigits=0,i,temp=a,rem,sum=0;
while(a){
ndigits++;
a/=10; // how would we count 3 digits out of 153->15->1->0
}
printf("\n\t Total digits in %d = %d",temp,ndigits);
a = temp;
while(a){
rem = a;
sum=sum+pow(rem,ndigits);// rem^ndigits
a%=10;
}
if(sum==temp)
 printf("\n\t Yes %d is Armstrong number",temp); 
 else 
 printf("\n\t %d is not an Armstrong number",temp); 
 return 0;
}
