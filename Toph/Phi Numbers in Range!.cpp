#include<bits/stdc++.h>
using namespace std;
#define MAX 500005
#define ll long long
int phi[MAX];
vector<int> v;

void find_phi(int n)
{
    int i,j;
    for(i=2;i<=n;i++)
        phi[i]=i;
    for(i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=n;j+=i)
                phi[j]-=phi[j]/i;//Inclusion_Exclusion Law use
        }
    }
}
void push_phi(int n)
{
    find_phi(n);
    int i;
    //v.push_back(0);
    for(i = 2; i <= n; i++)
        v.push_back(phi[i]);
}
int main()
{

    int n,t,x,y,l,r,k,i,j;
    scanf("%d",&t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d%d",&x,&y);
        push_phi(x);
        printf("Case %d:\n",i);
        while(y--)
        {

            scanf("%d%d%d",&l,&r,&k);
            set<int> v2;
            set<int>::iterator it=v2.begin();

            copy((v.begin()+l,v.begin()+r, inserter(v2, it)));

            vector<int> v3;
            for(it = v2.begin();it!=v2.end();it++)
                v3.push_back(*it);

            if(k>v3.size())
                printf("No Distinct Phi Number\n");
            else
            {
                //sort(v2.begin(),v2.end());
                printf("%d\n",v3[k+1]);
                //v2.clear();
            }
        }
    }
    return 0;

}
