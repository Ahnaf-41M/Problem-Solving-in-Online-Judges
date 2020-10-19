#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c1=0,c,n,i=1,count = 0;

    while(scanf("%d",&n) && n>0)
    {
        c = 1;
        count = 0;
        while(c < n)
        {
            c*=2;
            count++;
        }
        printf("Case %d: %d\n",i,count);
        i++;

    }
    return
     0;
}
