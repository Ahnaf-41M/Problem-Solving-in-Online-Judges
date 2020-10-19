#include<bits/stdc++.h>
using namespace std;
#define mx 20000010
int a[mx];
vector< pair <int,int> >v;
void sieve()
{
    int i,j;
    a[2]=2;

    for(i = 3; i <= mx; i+=2)
        a[i] = i;

    for(i = 3; i <= sqrt(mx); i++)
    {
        if(a[i]==i)
        {
            for(j = 2; i*j<=mx; j++)
            {
                a[i*j] = 0;
            }
        }
    }
    int k=1;
    v.push_back(make_pair(0,0));

    for(int i = 3; i <= mx; i+=2)
    {
        if(a[i]==i && a[i+2]==i+2 && a[i+2]-a[i]==2)
        {
            v.push_back(make_pair(i,i+2));
        }
        /*else if(a[i]==i && a[i-2]==i-2 && a[i]-a[i-2]==2)
        {
            v.push_back(make_pair(i,i+2));
        }*/
    }


}
int main()
{
    sieve();

    int n;

    while(cin>>n)
    {
        cout<<"("<<v[n].first<<", "<<v[n].second<<")"<<"\n";
    }
}
