#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,i,j;
     int a[10];
     bool c1,c2;

     scanf("%d",&n);
     printf("Lumberjacks:\n");
     while(n--)
     {
           c1=true,c2=true;

          for(i = 0; i < 10; i++)
               cin>>a[i];
          for(i=1,j=9; i<10,j>=1; i++,j--)
          {
               if(a[i]<a[i-1])
                    c1 = false;
               if(a[j]>a[j-1])
                    c2 = false;
          }
          if(c1||c2)
               printf("Ordered\n");
          else
               printf("Unordered\n");
     }
}
