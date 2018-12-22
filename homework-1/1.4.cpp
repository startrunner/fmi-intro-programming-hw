#include <cstdio>
#include <iostream>
using namespace std;

int digits[64];

constexpr int power(int x, int p)
{
    return
        (p==0)?1:
        (p==1)?x:
        (p==2)?x*x:
        power(power(x, p/2), 2) * power(x, p%2);
}

bool check(int x)
{
    int n = 0;

    int xCopy = x;
    do
    {
        digits[n++] = xCopy % 10;
        xCopy/=10;
    }while(xCopy!=0);

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=power(digits[i], n);
    }

    //printf("sum for %d is %d\n", x, sum);

    return sum == x;
}

int main()
{
    int a, b;
    cin>>a>>b;

    for(int i=a;i<=b;i++)
    {
        if(check(i))printf("%d ", i);
    }

    printf("\n");

    return 0;
}
