#include <cstdio>
#include <iostream>
using namespace std;

void swap_double(double &x, double &y)
{
    x+=y;
    y=x-y;
    x-=y;
}

bool is_outside(double x, double y)
{
    return x<-4 || x>9 || y<-2 || y>6;
}

bool is_on_contour(double x, double y, const double *xCoords, const double *yCoords, int coordCount)
{
    for(int i=0; i<coordCount; i++)
    {
        double x1 = xCoords[i], y1 = yCoords[i];
        double x2 = xCoords[(i+1)%coordCount];
        double y2 = yCoords[(i+1)%coordCount];


        if(x1 == x2)
        {
            if(y1>y2)swap_double(y1, y2);
            if(x == x1 && y>=y1 && y<=y2)return true;
        }
        else if(y1 == y2)
        {
            if(x1>x2)swap_double(x1, x2);
            if(y == y1 && x>=x1 && x<=x2)return true;
        }
        else printf("something wrong, LOL");
    }

    return false;
}

bool is_on_contour(double x, double y)
{
    const double OuterContourX[] = {-4, 9, 9, -4};
    const double OuterContourY[] = {6, 6, -2.5, -2.5};
    const double InnerContourX[] = {-1, 3, 3, 7, 7, 5.5, 5.5, 3, 3, -1};
    const double InnerContourY[] = {2, 2, 4.5, 4.5, 2, 2, -0.5, -0.5, -2, -2,};

    return
        is_on_contour(x, y, OuterContourX, OuterContourY, sizeof(OuterContourX)/sizeof(double))
        ||
        is_on_contour(x, y, InnerContourX, InnerContourY, sizeof(InnerContourX)/sizeof(double));
}

bool in_range(double x, double from, double to)
{
    if(from > to)swap_double(from, to);
    return x>=from && x<=to;
}

bool is_on_white_or_contour(double x, double y)
{
    return
        (in_range(x, -1, 3) && in_range(y, -2, 2))
        ||
        (in_range(x, 3, 5.5) && in_range(y, -0.5, 2))
        ||
        (in_range(x, 3, 7) && in_range(y, 2, 4.5));
}

int main()
{
    double x, y;
    cin>>x>>y;

    if(is_on_contour(x, y))puts("1");
    else if(is_on_white_or_contour(x, y) || is_outside(x, y))puts("0");
    else puts("2");

    return 0;
}
