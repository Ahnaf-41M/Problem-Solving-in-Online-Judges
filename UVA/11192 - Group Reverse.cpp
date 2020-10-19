#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n;
    string s;

    while(cin>>n>>s,n>0)
    {

        if(n==s.size())
            cout<<s;
        else{
                n = s.size()/n;
        for(i = 0; i < s.size(); i+=n)
        {
            for(j=n+i-1; j>=i; j--)
            {
                cout<<s[j];
            }
        }
        }
        cout<<endl;
    }
    return 0;
}
