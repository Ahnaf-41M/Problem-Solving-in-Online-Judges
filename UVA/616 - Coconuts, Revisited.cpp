#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll n,rem=0;
     bool flag;

     while(cin>>n && n!=-1)
     {
          rem = n;
          while(rem)
          {
               if(rem%5==0)
               {
                    rem = rem-rem/5;
               }
               else if(rem%5==1)
               {
                    rem = rem/5;
                    flag = true;
                    break;
               }
               else
               {
                    flag = false;
                    break;
               }
          }
          if(flag){
               printf("%lld coconuts, %lld people and 1 monkey\n",n,(rem<=5)?rem:5);
          }
          else{
               printf("%lld coconuts, no solution\n",n);
          }

     }
}
