#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t,n,m,n1,m1,sum;

    scanf("%lld",&t);

    while(t--)
    {
        n1=0,m1=0;
        scanf("%lld%lld",&n,&m);

        while(n)
        {
            n1 = (n%10) + n1*10;
            n/=10;
        }
        while(m)
        {
            m1 = (m%10) + m1*10;
            m/=10;
        }
        sum = m1+n1;
        //cout<<n1<<" "<<m1;
        n1=0;
        while(sum)
        {
            n1 = n1*10+sum%10;
            sum/=10;
        }
        printf("%lld\n",n1);
    }
}
