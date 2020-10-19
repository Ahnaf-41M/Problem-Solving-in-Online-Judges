#include<bits/stdc++.h>
using namespace std;
///Got TLE -_-

#define ll long long
vector<ll> v;

void find_primes(ll mx)
{
     ll i,j;
     ll a1[mx];
     memset(a1,0,sizeof(a1));
     a1[1]=1;

     for(i = 3; i <= sqrt(mx); i++)
     {
          if(a1[i]==0)
          {
               for(j = 2; i*j <= mx; j++)
               {
                    a1[i*j]=1;
               }
          }
     }
     v.push_back(2);
     for(i = 3; i <= mx; i+=2)
     {
          if(a1[i]==0)
               v.push_back(i);
     }
}
int main()
{
     ll i,j,n,mxe=0;
     cin>>n;
     ll a[n];
     ll sum[n];
     for(i = 0; i < n; i++)
     {
          cin>>a[i];
          sum[i]=0;
          if(a[i]>=mxe)
               mxe=a[i];
     }

     find_primes(mxe/2+1);
     ll k= 0;

     for(i = 0; i < v.size(); i++)
     {
          for(j = 0; j < n; j++)
          {
               if(a[j]%v[i]!=0)
               {
                    sum[k]++;
                    if(a[j]-(a[j]%v[i])>1&&(a[j]-(a[j]%v[i])<(a[j]-1)))
                       sum[k]=INT_MAX;
               }

          }
          k++;
     }
     ll mn = *min_element(sum,sum+k);
     cout<<mn<<endl;
}
