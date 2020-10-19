#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,c,sum;

    while(cin>>n>>m)
    {
        int a[n][m];
        c=0,sum=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    c=0;
                    break;
                }
                else
                    c=1;
            }
            sum=sum+c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
