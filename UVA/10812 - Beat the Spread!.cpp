#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int s,d,t;
    long long a;
    cin>>t;

    while(t--)
    {
        cin>>s>>d;
        if((s+d)%2!=0 || s<d)
        {
            cout<<"impossible\n";
        }
        else
        {
            a = (s+d)/2;
            cout<<a<<" "<<a - d<<endl;
        }
    }

    return 0;
}
