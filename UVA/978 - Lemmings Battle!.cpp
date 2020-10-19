#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll n,i,j,b,gg,bb;
     cin>>n;

     while(n--)
     {
          cin>>b>>gg>>bb;
          vector<ll> blue,green;
          for(i = 0; i < gg;i++)
          {
               int x;
               cin>>x;
               green.push_back(x);
          }
          for(i = 0; i < bb; i++)
          {
               int x;
               cin>>x;
               blue.push_back(x);
          }
          sort(blue.begin(),blue.end());
          sort(green.begin(),green.end());

          while(blue||green)
          {
               if(blue.size()==0||green.size()==0)
                    break;
               if(blue[blue.size()-1]>green[green.size()-1])
               {
                    blue.push_front(1);
               }
          }
     }
}
