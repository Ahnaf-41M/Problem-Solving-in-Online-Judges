#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k,p,i;

    cin>>t;

    for(i = 1; i <= t; i++)
    {
        cin>>n>>k>>p;

        if(k+p <= n)
        {
            cout<<"Case "<<i<<": "<<k+p<<endl;
        }

        else
        {
            if((k+p)%n != 0)
            cout<<"Case "<<i<<": "<<(k+p)%n<<endl;
            else
                cout<<"Case "<<i<<": "<<n<<endl;
        }
    }

    return 0;


}
