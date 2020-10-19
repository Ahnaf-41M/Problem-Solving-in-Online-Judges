#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 1000003
bool a[Max];
vector<int> v(78498); /*Declared the size for not getting Runtime Error*/

void sieve()
{
    int i,j;
    a[0]=0,a[1]=0,a[2]=1;

    for(i = 3; i <= Max; i+=2)
        a[i]=1;
    for(i = 3; i < sqrt(Max); i++)
    {
        if(a[i]==1)
        {
            for(j = 2; j*i <= Max; j++)
            {
                a[i*j]=0;
            }
        }
    }
    /*Storing the primes upto Max*/
    int k=0;
    v[k]=2;
    k++;
    for(i = 3; i <= Max; i+=2)
        if(a[i])
        {
            v[k]=i;
            k++;
        }
}

int main()
{
    int i,j,n,cnt=0;
    sieve();

    while(scanf("%d",&n)&& n!=0)
    {
        int p = n;
        cnt=0;
        for(i = 0; v[i] <= p; i++)
        {
            if(p%v[i]==0)
            {
                cnt++;
                while(p%v[i]==0)
                {
                    p/=v[i];
                }
            }
        }
        cout<<n<<" : "<<cnt<<endl;
    }


    return 0;
}

