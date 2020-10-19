#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,j;

    cin>>t;

    for(i = 1;i <= t; i++)
    {

        cin>>n;
        int a[n];

        for(j = 0; j < n; j++)
        {
            cin>>a[j];
        }

        cout<<"Case "<<i<<": "<<a[j/2]<<endl;

    }
    return 0;
}
