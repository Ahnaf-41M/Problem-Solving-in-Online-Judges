#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,x1,y1,x2,y2,r,t;

    cin>>t;

    while(t--)
    {
        cin>>x>>y>>x1>>y1>>x2>>y2>>r;

        int l = abs(x1-x);
        int w = abs(y1-y);

        if(6*l == 10*w && 5*r==l && 20*(x2-x)==9*l
            && 2*(y2-y) == w)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
