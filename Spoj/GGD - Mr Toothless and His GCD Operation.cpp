#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> v;
int is_prime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0)
          return false;
    }
        return true;
}
int main()
{
    int t,n,x,y,gd,i,j,div,p;

    cin>>t;
    for(i = 1; i <= t; i++)
    {
        cin>>n;
        p = n/2+(n%2);
        if(is_prime(n))
        {
            cout<<"Case "<<i<<": "<<n-1<<' '<<n<<endl;
        }
        else if(sqrt(n)*sqrt(n)==n && n&1)
        {
           cout<<"Case "<<i<<": "<<n-sqrt(n)<<' '<<n<<endl;
        }
        else if(p%2==0)
        {
             cout<<p<<' '<<n<<endl;
        }
        else
        {
             for(j = 2; j <= sqrt(n); j++)
             {
                  if(n%j==0)
                  {
                       x=n/j;
                       break;
                  }
             }
             cout<<x<<' '<<n<<endl;
        }

    }

}
