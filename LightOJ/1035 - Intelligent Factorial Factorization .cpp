#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
int a[mx];
vector<int> v;

void sieve()
{
    int i,j;
    a[2]=1;
    for(i = 3; i <= mx; i+=2)
        a[i]=1;
    for(i = 2; i <= sqrt(mx); i++)
    {
        if(a[i]==1)
        {
            for(j = 2; j*i<=mx; j++)
            {
                a[i*j]=0;
            }
        }

    }
    v.push_back(2);
    for(i = 3; i <= mx; i+=2)
    {
        if(a[i]==1)
        {
            v.push_back(i);
        }
    }

}
int main()
{
    sieve();
    int n,t,i,j,k,x,l;
    set<int> s;
    set<int>::iterator it;
    scanf("%d",&t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d",&n);
        int a1[n+2];
        //x = n;
        memset(a1,0,sizeof(a1));
        for(j = 2; j <= n; j++)
        {
            x = j;
            for(k = 0; k < j; k++)
            {
                if(x<2)
                    break;
                while(x%v[k]==0)
                {
                    x/=v[k];
                    a1[v[k]]++;
                    s.insert(v[k]);
                }
            }
        }
        cout<<"Case "<<i<<": "<<n<<" = ";
        l = s.size();
        k=0;
        for(it=s.begin(); it!=s.end(); it++)
        {
            k++;
            if(k!=l)
                cout<<*it<<" ("<<a1[*it]<<") * ";
            else
                cout<<*it<<" ("<<a1[*it]<<")\n";
        }
        s.clear();

    }
}
