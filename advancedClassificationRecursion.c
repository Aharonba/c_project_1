
#include <stdio.h>
#include "NumClass.h"
int reverse(int num, int y);
int pow_1(int x, int y);
int CheckArmstrong(int x, int size);
int digit(int x);
int isPalindrome(int num);

int reverse(int num, int rev) {
    if (num == 0)
        return rev;
    else
        return reverse(num / 10, rev * 10 + num % 10);
}


int isPalindrome(int num) {
    
    if (num < 0)
        return 0; 

    int reversed = reverse(num, 0);

    return num == reversed;
}















int isArmstrong(int x){
if (x == CheckArmstrong(x,digit(x)))
{
  return 1;
}
return 0;
}

int CheckArmstrong(int x, int size) {
    if (x > 0){
        return (pow_1( x%10, size) + CheckArmstrong(x/10, size));
    }
    return 0;
}

int pow_1(int x, int y){
int n=x;
int sum=x;
for (int i=1; i<y; i++){
sum= sum*n;
}
return sum;
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