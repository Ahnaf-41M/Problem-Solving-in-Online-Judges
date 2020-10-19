#include<bits/stdc++.h>
using namespace std;

int main()
{
     int t,n,i,sum=0;

     cin>>t;

     while(t--)
     {
          cin>>n;
          int man[n],woman[n];
          for(i = 0; i < n;i++)cin>>man[i];
          for(i = 0; i < n;i++)cin>>woman[i];

          sort(man,man+n);
          sort(woman,woman+n);

          for(i = 0; i < n; i++)
               sum+=(man[i]*woman[i]);
          cout<<sum<<endl;
          sum=0;

     }


}
