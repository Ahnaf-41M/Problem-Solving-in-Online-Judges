#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,i,cnt=0,j;

     scanf("%d",&n);
     for(i = 2; i <= n; i++)
     {
          for(j = i; j*i <= n; j++)
          {
               cnt++;
          }
     }
     cnt+=n;
     printf("%d\n",cnt);
}
