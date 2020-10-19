#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    IOS
    int c1,c2,n,i,j,tc=1;

    while(cin>>n && n!=0)
    {
        int a[n];
        c1=0,c2=0;
        for(j = 0; j < n; j++)
        {
            cin>>a[j];
            if(a[j]==0)
                c2++;
            else
                c1++;
        }
        printf("Case %d: %d\n",tc,c1-c2);
        tc++;
    }


}
