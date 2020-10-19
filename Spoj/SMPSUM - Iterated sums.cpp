#include<bits/stdc++.h>
using namespace std;

int main()
{
     int a,b,c,sum=0;
     cin>>a>>b;
     for(c = a; c <= b; c++)
     {
          sum += c*c;
     }
     cout<<sum<<endl;
}
