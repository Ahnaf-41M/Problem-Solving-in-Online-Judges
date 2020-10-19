#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,hj,lj,i,j;

    cin>>t;

    for(i = 1; i <= t; i++)
    {
        cin>>n;
        int a[n];
        lj = 0;
        hj = 0;

        for(j = 0; j < n; j++)
        {
            cin>>a[j];

            if(j==0)
            {
                hj = 0;
                lj = 0;
            }
            else if(a[j] > a[j-1])
            {
                hj++;
            }
            else if(a[j] < a[j-1])
            {
                lj++;
            }
            else
            {
                lj = lj;
                hj = hj;
            }
        }

        cout<<"Case "<<i<<": "<<hj<<" "<<lj<<endl;
    }

    return 0;
}
