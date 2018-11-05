#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;
    cin>>x;


    double top = 11*x*x + 3*x + 15;
    double bottom = x*x*x - 25;

    double value = top/bottom;

    printf("value is: %f\n", value);

    return 0;
}
