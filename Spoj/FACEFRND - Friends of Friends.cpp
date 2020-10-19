#include<bits/stdc++.h>
using namespace std;

int main()
{
     int t,n,x,cnt=0,id;

     cin>>t;
     map<int,int> mp;
     vector<int> v;

     while(t--)
     {
          cin>>id>>n;
          mp[id]++;
          for(int i = 0; i < n; i++)
          {
               cin>>x;
               v.push_back(x);
          }
     }
     for(int i = 0; i < v.size(); i++)
     {
          if(mp[v[i]]==0)
          {
               cnt++;
               mp[v[i]]++;
          }
     }
     cout<<cnt<<endl;
}
