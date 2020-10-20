#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n;

    cin>>t;

    while(t--)
    {
        cin>>n;
        if(n & 1 || n==2)
            cout<<"Arjit\n";
        else
            cout<<"Deepa\n";
    }

}
