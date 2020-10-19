#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,c,p,q,rem;
    vector<int> v;

    while(cin>>n>>m)
    {
        c=0;
        for(i = n; i <= m; i++)
        {
            rem=i;
            p=0;
            while(rem!=0)
            {
                v.push_back(rem%10);
                rem = rem/10;
            }
            p = v.size();
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
            q = v.size();
            if(p==q)
                c++;

                v.clear();
        }
        cout<<c<<"\n";
    }

    return 0;
}
