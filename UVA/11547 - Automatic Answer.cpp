#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,rem,c;

    cin>>t;

    while(t--)
    {
        cin>>n;

        n = (((((n*567)/9)+7492)*235)/47)-498;
        n = n/10;

        cout<<fabs(n%10)<<"\n";

    }

    return 0;
}
