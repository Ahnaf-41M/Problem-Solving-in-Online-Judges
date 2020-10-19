#include<bits/stdc++.h>
using namespace std;

#define Max 90000000
#define ll long long
bool a[Max];

vector<int> v;
void seive()
{
    ll i,j;
    a[0]=0,a[1]=0,a[2]=1;

    for(i = 3; i <= Max; i+=2)
        a[i]=1;
    for(i = 3; i < sqrt(Max); i++)
    {
        if(a[i]==1)
        {
            for(j = i*i; j <= Max; j+=i)
            {
                a[j]=0;
            }
        }
    }
    v.push_back(2);
    for(i = 3; i <= Max; i+=2)
        if(a[i])
            v.push_back(i);
}
int main()
{
     //seive();
     int n=2;
     int ans =  n *log(n) + log (log (n - 1) )+ (log (log (n) - 2))/log(n) - ((log (log (n))*2 - 6 *log (log (n) ))+ 11)/(2 *log2 (n));
     //cout<<v.size();
     cout<<ans;
}
