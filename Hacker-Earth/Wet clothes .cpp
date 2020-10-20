#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt=0,n,m,g,i,j;
    cin>>n>>m>>g;
    int a[n],b[m];
    for(i = 0; i < n; i++)
        cin>>a[i];
    for(i = 0; i < m; i++)
        cin>>b[i];
    sort(b,b+m);
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if((a[i]-a[i-1])>=b[j] && b[j]!=-1)
            {
                cnt++;
                b[j]=-1;
                //break;
            }
        }

    }
    cout<<cnt<<endl;
}
