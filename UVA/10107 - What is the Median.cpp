#include<bits/stdc++.h>
using namespace std;
#define sort(v) sort(v.begin(),v.end())
int main()
{
     int n,l;
     vector<int> v;

     while(scanf("%d",&n)!=EOF)
     {
          v.push_back(n);
          sort(v);
          //l = v.size();

          if(v.size()&1)
               cout<<v[v.size()/2]<<endl;
          else
               cout<<(v[v.size()/2-1]+v[v.size()/2])/2<<endl;
     }
}
