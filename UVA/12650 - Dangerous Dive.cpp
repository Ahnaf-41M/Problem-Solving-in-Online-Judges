#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,r,i,x,c,j;
    vector<int> v,v1;

    while(cin>>n>>r)
    {
        for(i=1,j=0;j<n,i<=n;j++,i++)v.push_back(i);
        for(i = 0; i < r; i++)
        {
            cin>>x;
            v1.push_back(x);
        }

        if(n==r)
        {
            cout<<"*";
        }
        else
        {
            sort(v1.begin(),v1.end());

            for(i=0;i<n;i++)
            {
                for(j=0;j<r;j++)
                {
                    if(v[i]==v1[j])
                    {
                        c=0;
                        break;
                    }
                    else
                        c=1;
                }
                if(c==1)
                    cout<<v[i]<<" ";
            }
        }
        cout<<"\n";
        v.clear();
        v1.clear();
    }

    return 0;
}
