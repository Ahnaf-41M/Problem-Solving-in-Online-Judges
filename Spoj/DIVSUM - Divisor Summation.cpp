#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 500005

ll sum[mx];

void div_sum()
{
     ll i,j;
     for(i = 1; i <= mx; i++)
     {
          for(j = 1; j <= sqrt(i); j++)
          {
               if(i%j==0)
               {
                    if(i/j==j)
                    {
                         sum[i]+=j;
                    }
                    else
                    {
                         sum[i]+=j;
                         sum[i]+=i/j;
                    }
               }
          }
          sum[i]-=i;
     }
}
int main()
{
     div_sum();
     ll n,i,x;
     cin>>n;

     while(n--)
     {
        cin>>x;
        cout<<sum[x]<<endl;
     }

}
