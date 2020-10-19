#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y,z,e;

    cin>>n;

    while(n--)
    {
        cin>>x>>y>>z;

        e = z*(x+(x-y))/(x+y);
        if(e<=0)
            cout<<"0\n";
        else
            cout<<e<<endl;
    }

    return 0;
}
