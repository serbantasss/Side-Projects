//
//  main.cpp
//  lgput
//
//  Created by Serban Bantas on 22/02/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//
 
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1.e-14;///10^-14
struct POINT
{
    double x,y;
};
double aria_triunghi_directionat(POINT A,POINT B,POINT C)
{
    double cp=(B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-B.x);
    return cp*0.5;
}
int main()
{
    POINT a,b,c;
    scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    if(aria_triunghi_directionat(a, b, c)<eps && aria_triunghi_directionat(a, b, c)>-eps)
        printf("TOWARDS");
    else
        if(aria_triunghi_directionat(a, b, c)>eps)
            printf("LEFT");
        else
            printf("RIGHT");
    return 0;
}