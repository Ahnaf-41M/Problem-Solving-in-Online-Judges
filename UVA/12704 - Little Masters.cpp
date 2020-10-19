#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,x,y,r;
    double res,s;
    cin>>t;

    while(t--)
    {
        cin>>x>>y>>r;

        res = (x*x+y*y)*1.0;
        s = sqrt(res);

        printf("%.2lf %.2lf\n",r-s,r+s);
    }
    return 0;
}
