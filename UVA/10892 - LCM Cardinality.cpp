#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll n,i,j;

     while(cin>>n && n)
     {
          ll cnt=0;
          vector<ll> div;

          for(i = 1; i <= sqrt(n); i++)
          {
               if(n%i == 0)
               {
                    if(n/i==i)
                         div.push_back(i);
                    else
                    {
                         div.push_back(i);
                         div.push_back(n/i);
                    }
               }
          }
          for(i = 0;  i < div.size(); i++)
          {
               for(j = i+1; j < div.size(); j++)
               {
                    if(__gcd(div[i],div[j]) == 1)
                         cnt++;
               }
          }
          cout<<n<<" "<<cnt+1<<endl;
     }
}
