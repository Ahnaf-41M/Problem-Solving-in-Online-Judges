#include<bits/stdc++.h>
using namespace std;
int a[10000];

int main()
{
     int n,i,j;

     scanf("%d",&n);
     getchar();
     while(n--)
     {
          string s;
          int k=0;
          getline(cin,s);
          stringstream ss(s);

          while(ss>>a[k])
               k++;
          int gcd = 0;
          for(i = 0; i < k; i++)
          {
               for(j = i+1; j < k; j++)
               {
                    gcd = max(gcd,__gcd(a[i],a[j]));
               }
          }
          printf("%d\n",gcd);
     }
}
