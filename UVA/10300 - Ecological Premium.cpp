#include<bits/stdc++.h>
using namespace std;

int main()
{
   unsigned long long int   s,n,fe,sum = 0,i,j,t,x;
    unsigned long long int a[20][20];


    cin>>t;

    while(t--)
    {
        cin>>n;
        sum = 0;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < 3; j++)
            {
                cin>>a[i][j];
            }
            sum +=a[i][0]*a[i][2];
        }
        cout<<sum<<endl;
    }
    return 0;
}
