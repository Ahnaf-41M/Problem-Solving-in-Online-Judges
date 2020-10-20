#include<bits/stdc++.h>
using namespace std;
int coin[] = {1,5,10,25,50};

int Ks(int make)
{
     int amount[make+1]={};
     amount[0]=1;

     for(int i = 0; i < 5; i++)
     {
          for(int j = 1; j <= make; j++)
          {
               if(j>=coin[i])
               {
                    amount[j]+=amount[j-coin[i]];
               }
          }
     }
     return amount[make];
}

int main()
{
     int make;

     //printf("%d\n",Ks(make,coin));
     while(scanf("%d",&make)!=EOF)
     {
          printf("%d\n",Ks(make));
     }
}

