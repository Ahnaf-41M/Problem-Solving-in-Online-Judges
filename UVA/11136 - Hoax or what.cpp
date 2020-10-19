#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll nofDays,nofBills;

    while(scanf("%lld",&nofDays) && nofDays!=0)
    {
        ll sum=0;
        multiset<ll> v;
        multiset<ll>:: iterator highest,lowest;
        while(nofDays--)
        {
            ll billAmnt;
            scanf("%lld",&nofBills);

            while(nofBills--)
            {
                scanf("%lld",&billAmnt);
                v.insert(billAmnt);
            }

            lowest = v.begin();
            highest = v.end();
            --highest;

            sum+=(*highest)-(*lowest);
            v.erase(lowest);
            v.erase(highest);


        }

        printf("%lld\n",sum);
    }
}
