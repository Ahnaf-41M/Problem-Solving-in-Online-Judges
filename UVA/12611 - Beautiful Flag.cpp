#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,r,i;

    cin>>t;

    for(i = 1; i <= t; i++)
    {
        cin>>r;

        cout<<"Case "<<i<<":"<<endl;
        cout<<-r*2.25<<" "<<r*1.5<<endl;
        cout<<r*2.75<<" "<<r*1.5<<endl;
        cout<<r*2.75<<" "<<-r*1.5<<endl;
        cout<<-r*2.25<<" "<<-r*1.5<<endl;
    }

    return 0;
}
