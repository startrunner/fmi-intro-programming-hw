#include <cstdio>
#include <iostream>
using namespace std;

int digitCount = 0;
int digits[32];

int main()
{
    int x;
    cin>>x;

    int xCopy = x;
    do
    {
        digits[digitCount++] = xCopy%10;
        xCopy/=10;
    }while(xCopy!=0);

    for(int i=0;i<digitCount;i++)
    {
        if(digits[i]%3 == 0)digits[i]/=3;
        else
        {
            if(digits[i]%2==0)digits[i]+=1;
            else digits[i]+=2;
        }
    }

    int newX = 0;
    for(int i = digitCount-1;i>=0;i--)newX = newX*10 + digits[i];

    //printf("%d\n", newX);
    printf("outcome: %d\n", newX*2);

    return 0;
}
