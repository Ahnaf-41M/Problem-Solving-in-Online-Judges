#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
     if(n <= 100)
          return f(f(n+11));
     else
          return n-10;
}
int main()
{
     int n;

     while(cin>>n && n)
     {
          cout<<"f91("<<n<<") = "<<f(n)<<endl;
     }
}
