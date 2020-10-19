#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

int main()
{
    double r,area,angle,n,q;

    while(cin>>r>>n)
    {
        angle = (360*pi)/(n*180);
        q = sin(angle);
        area = (r*r*n*q)/2;

        cout<<fixed<<setprecision(3)<<area<<endl;
    }
    return 0;
}
