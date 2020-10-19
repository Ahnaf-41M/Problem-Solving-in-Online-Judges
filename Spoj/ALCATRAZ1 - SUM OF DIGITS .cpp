#include<bits/stdc++.h>
using namespace std;

int main()
{
     int t,i,sum=0;
     string s;

     scanf("%d",&t);

     while(t--)
     {
          cin>>s;

          for(i = 0; i < s.size(); i++)
          {
               sum+=s[i]-48;
          }
          printf("%d\n",sum);
          sum=0;
     }
}
