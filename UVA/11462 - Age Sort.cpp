#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;

    while(cin>>n,n>0)
    {
        vector<int> v;
        int x;

        for(i = 0; i < n; i++)
        {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(i = 0; i < n; i++)
        {

            if(i==n-1)
                cout<<v[i]<<endl;
            else
                cout<<v[i]<<" ";
        }

        v.clear();

    }
    return 0;
}
