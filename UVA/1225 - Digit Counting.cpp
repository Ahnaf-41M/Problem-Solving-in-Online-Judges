#include<bits/stdc++.h>
using namespace std;
int a[10];

int main()
{
    int i,res,t,n;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof a);
        for(i = 1; i <= n; i++)
        {
            res = i;
            while(res)
            {
                a[res%10]++;
                res/=10;
            }
        }
        for(i = 0; i <= 9; i++)
        {
            if(i!=9)
                cout<<a[i]<<" ";
            else
                cout<<a[i]<<"\n";
        }
        //cout<<endl;
    }

}
