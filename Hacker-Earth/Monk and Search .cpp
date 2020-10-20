#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll n,q,i,x,p;
    vector<ll> v;
    vector<ll>::iterator it1,it2,it;

    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    cin>>q;
    ll j=0,up1=0;
    while(q--)
    {
        cin>>j;
        if(j&1)
        {
            cin>>x;

            it1 = upper_bound(v.begin(),v.end(),x);

            cout<<n-(it1-v.begin())<<endl;

        }
        else
        {
            cin>>x;
            it2 = upper_bound(v.begin(),v.end(),x);
            it = find(v.begin(),v.end(),x);
            if(it!=v.end())
                cout<<n-(it2-v.begin())+1<<endl;
            else
                cout<<n-(it2-v.begin())<<endl;

        }
    }
    v.clear();
    return 0;
}
