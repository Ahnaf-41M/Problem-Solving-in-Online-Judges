#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,i,t,r,r1,r2,c=0,c1=0,f;
    char ch;
    cin>>t;

    while(t--)
    {
        c=0,c1=0;
        cin>>a>>ch>>b;
        cout<<" "<<a<<"\n";
        r2 = b;
        r1 = a;
        while(r2)
        {
            c++;
            r2/=10;
        }
        while(r1)
        {
            c1++;
            r1/=10;
        }
        if(c1>c)
        {
            for(i = 1; i <= c1-c; i++)
                cout<<" ";
        }
        cout<<ch<<b<<endl<<"-";
        if(ch=='+')
            r=a+b;
        else if(ch=='-')
            r=a-b;
        else if(ch=='*')
            r=a*b;
        f = r;
        while(f)
        {
            cout<<"-";
            f/=10;
        }

        cout<<"\n "<<r<<endl;


    }
}
