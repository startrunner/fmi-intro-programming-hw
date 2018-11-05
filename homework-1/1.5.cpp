#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=2019;;i++)
    {
        int digitSum = 0;
        int iCopy = i;

        do
        {
            digitSum+=iCopy%10;
            iCopy/=10;
        }while(iCopy!=0);

        if(digitSum==n)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
