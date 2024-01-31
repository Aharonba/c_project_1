#include <stdio.h>
#include "NumClass.h"
int digit(int x);
int pow_1(int x, int y);


int isPalindrome(int x){

int n =x;
int reversed=0;
int remainder;

while(n!=0){
remainder = n%10;
reversed= reversed*10 + remainder;
n=n/10;
}
if (reversed==x)
{
   return 1;
}
else return 0;

}

int isArmstrong(int x){
int n=x;
int sum=0;
int remainder;

while (n!=0)
{
    remainder = n%10;
    sum = sum + pow_1(remainder,digit(x));
    n=n/10;
}
if(sum== x){
    return 1;
}
else{
    return 0;
}
}

int digit(int x){
int n=x;
int dig=0;
while(n!=0){
 dig=dig+1;   
n= n/10;
}
return dig;
}

int pow_1(int x, int y){
int n=x;
int sum=x;
for (int i=1; i<y; i++){
sum= sum*n;
}
return sum;
}