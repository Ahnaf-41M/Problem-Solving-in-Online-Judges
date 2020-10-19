#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n;

     while(cin>>n)
     {
          int a[n],i;
          set<int> s;
          for(i = 0; i < n ; i++)cin>>a[i];
          for(i = 1; i < n; i++)
          {
               if(abs(a[i]-a[i-1])<=(n-1))
                    s.insert(abs(a[i]-a[i-1]));
          }
          if(s.size()==n-1)
               cout<<"Jolly\n";
          else
               cout<<"Not jolly\n";
     }
}
