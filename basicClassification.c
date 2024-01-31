#include <stdio.h>
#include "NumClass.h" 
int fact(int x);

int isPrime(int x){
if(x==1)
{
return 1;
}

if(x==2)
{
return 1;
}

    for (int i = x-1;i>1; i--)
    {
        if (x%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int isStrong(int x){
int num = x;
int sum =0;
int tmp;
while(x!=0){
tmp = x%10;
sum = sum + fact(tmp);
x= x/10;
}
if (sum == num){
return 1;    
}
return 0;

}

int fact(int x){
int f =1;
for (int i = 1; i <=x; i++)
{
    f= f*i;
}
    return f;
}
