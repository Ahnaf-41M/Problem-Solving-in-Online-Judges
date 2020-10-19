#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,b1,b2,p;

    cin>>n;

    while(n--)
    {
        cin>>m;
        p = m;
        b1=0,b2=0;

        while(p>0)
        {
            if(p%2==1)
                b1++;

            p = p/2;
        }
        while(m>0)
        {
            if(m%2==1)
                b2++;

            m = m/10;
        }

        cout<<b1<<" "<<b2<<endl;
    }
    return 0;
}
