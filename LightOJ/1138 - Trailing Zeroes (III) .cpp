
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
int zeroes(int n)
{
     int ret=0;
     while(n)
     {
          n/=5;
          ret+=n;
     }
     return ret;
}
int find_zero(int start,int endd)
{
     int mid,cnt=0;
     mid = (start+endd)/2;
     if(start>endd)
          return -1;

     cnt = zeroes(mid);

     if(cnt==n)
     {
          while(zeroes(mid)==n)
          {
               mid--;
          }
          return ++mid;
     }
     if(cnt<n)
     {
          return find_zero(mid+1,endd);
     }
     if(cnt>n)
     {
          return find_zero(start,mid-1);
     }
}

int main()
{
    IOS
    int t,ans,i;

    cin>>t;
    for(i = 1; i <= t; i++)
    {
         cin>>n;
         ans = find_zero(1,INT_MAX);
         if(ans!=-1)
         {
              printf("Case %d: %d\n",i,ans);
         }
         else
          printf("Case %d: impossible\n",i);
    }
    return 0;
}
