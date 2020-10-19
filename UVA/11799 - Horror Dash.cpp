#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,x,j,m;

    vector<int> v;

    cin>>t;
    j=0;

    while(t--)
    {
        j++;
        cin>>n;

        for(i = 0; i < n;i++)
        {
            cin>>x;
            v.push_back(x);
        }
        m =*max_element(v.begin(),v.end());

        cout<<"Case "<<j<<": "<<m<<endl;
        v.clear();
    }
}
