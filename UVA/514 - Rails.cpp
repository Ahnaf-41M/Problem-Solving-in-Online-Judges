#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[1000];

    while(scanf("%d",&n)&& n!=0)
    {
        int ind,cnt;
        while(true)
        {
            scanf("%d",&a[0]);
            if(a[0]==0)
            {
                cout<<'\n';
                break;
            }
            for(int i = 1; i < n; i++)
                scanf("%d",&a[i]);

            ind = 0,cnt=1;
            stack<int> station;

            while(cnt<=n)
            {
                station.push(cnt);

                while(!station.empty() && station.top()==a[ind])
                {
                    station.pop();
                    ind++;
                    if(ind>=n)
                        break;
                }
                cnt++;
            }
            if(station.empty())
                printf("Yes\n");
            else
                printf("No\n");

        }

    }
}
