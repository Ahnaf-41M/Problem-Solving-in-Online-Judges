#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a1[mx];
int main()
{
    ll n,i,j,c=1,mn = INT_MAX,c1=0,mnc = INT_MAX,d,k=0;
    scanf("%lld",&n);
    ll a[n+5];
    for(i = 1; i <= n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for(i = 1; i <= n/2+n%2; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i!=j)
            {
                if(__gcd(a[i],a[j])>1)
                {
                    c1=0;
                    mn = min(abs(i-j),mn);
                    if(mn<mnc)
                    {
                        mnc = mn;
                        d = j;
                        a1[k]=i;
                        k++;
                    }
                }
                else
                {
                    c=1;
                }
            }
        }
        if(c==1&&c1!=0)
        {
            c=0;
            printf("-1 ");
        }
        else
        {
           c1=1;
           printf("%lld ",d);
        }
        mn = INT_MAX;
        mnc = INT_MAX;
    }
    for(i = 0; i < k; i++)
        cout<<a[i]<< " ";
    printf("\n");
}
