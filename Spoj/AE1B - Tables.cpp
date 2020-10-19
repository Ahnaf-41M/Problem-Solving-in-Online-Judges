#include<bits/stdc++.h>
using namespace std;

int main()
{
     int c=0,n,k,s,i,sum=0;
     scanf("%d%d%d",&n,&k,&s);
     int a[n];

     for(i = 0; i < n; i++)cin>>a[i];
     sort(a,a+n);

     for(i = n-1; i>=0 ; i--)
     {
          sum+=a[i];
          c++;
          if(sum>=s*k)
               break;
     }
     printf("%d\n",c);
}
