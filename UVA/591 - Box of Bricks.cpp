#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j=0,n,sum =0,p,c,x;

    while(cin>>n,n>0)
    {
        j++;
        vector<int> v;

        sum=0,c=0;
        for(i = 0; i < n; i++)
        {
            cin>>x;
            v.push_back(x);
            sum+=v[i];
        }
        p = sum/n;
        sort(v.begin(),v.end());
        for(i = 0; i < n; i++)
        {
            if(v[i]>p)
                c+=v[i]-p;
        }

        cout<<"Set #"<<j<<"\n";
        cout<<"The minimum number of moves is "<<c<<".\n\n";
    }
    return 0;
}
