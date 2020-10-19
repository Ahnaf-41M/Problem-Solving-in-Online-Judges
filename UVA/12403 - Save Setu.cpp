#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i,count = 0;
    string s;

    cin>>t;

    for(i = 0; i < t; i++)
    {
        cin>>s;

        if(s[0] == 'd')
        {
            cin>>n;
            count+=n;
        }
        else
        {
            cout<<count<<endl;
        }

    }

    return 0;
}
