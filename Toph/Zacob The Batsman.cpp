#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,t,x,r1,r2;
    cin>>t;

    while(t--)
    {
        cin>>x;

        if(x%2==0 && x!=2)
            cout<<"Zacob Zacob!\n";
        else
            cout<<"Sorry Zacob!\n";
    }
}

