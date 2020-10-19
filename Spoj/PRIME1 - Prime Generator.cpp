#include<bits/stdc++.h>
using namespace std;

bool isprime(int a)
{
    if(a==0 || a==1)
        return false;
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

int main()
{
    int t,p,q,i,j;

    cin>>t;

    while(t--)
    {
        cin>>p>>q;
        for(i = p; i <= q; i++)
        {
            if(isprime(i))
                cout<<i<<endl;
        }

    }
}
