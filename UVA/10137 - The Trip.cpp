#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,i;
     double sum=0.0;

     while(scanf("%d",&n)&& n>0)
     {
          vector<double> v;
          double respPos=0,respNeg=0,sol=0;
          sum=0.0;
          for(i = 0; i < n; i++)
          {
               double x;
               cin>>x;
               v.push_back(x);
               sum+=x;
          }
          sum/=(n*1.0);
          sort(v.begin(),v.end());
          for(i = 0; i < n; i++)
          {
               double ans=0;
                    ans+=(double)(long)((v[i]-sum)*100.0)/100.0;
               if(ans>0)
                    respPos+=ans;
               else
                    respNeg+=ans;
          }
          sol = (-respNeg>respPos)? -respNeg : respPos;
          printf("$%.2lf\n",abs(sol));

     }
}
