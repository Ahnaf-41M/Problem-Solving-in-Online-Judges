#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000000
char prime[mx+1];
ll r1,r2,r3,r4;
vector<ll> v;
void sieve()
{
    int i,j;

    prime[2]=1;
    for(i = 3; i <= mx; i+=2)
        prime[i] = 1;
    for(i = 3; i <= sqrt(mx); i+=2)
    {
        if(prime[i]==1)
        {
            for(j = i*i; j <= mx; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    /*Storing the primes in vector v*/
    v.push_back(2);
    for(int i = 3; i <= mx; i+=2)
    {
         if(prime[i]==1)
          v.push_back(i);
    }

}
/*Check primality of a big  number greater than Max  */
ll is_prime(ll n)
{
    ll i,x;
    bool flag=true;
    x = sqrt(n);
    for(i = 0; v[i] <= x; i++)
    {
        if(n%v[i]==0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    sieve();
    //cout<<v.size()<<endl;
    ll a,b,i;

    while(scanf("%lld %lld",&a,&b)==2)
    {
        ll cnt=0,Max=INT_MIN,Min = INT_MAX;
        if(a<=mx && b<=mx)
        {
            vector<ll> vec;
            for(i = a; i <= b; i++)
            {
                if(prime[i]==1)
                {
                    vec.push_back(i);
                    cnt++;
                }
            }
            for(i = 0; i< vec.size()-1; i++)
            {
                  /*Finding the largest distance*/
                if(Max<(vec[i+1]-vec[i]))
                {
                    Max = vec[i+1]-vec[i];
                    r3 = vec[i];
                    r4 = vec[i+1];
                }
                /*Finding the minimum distance*/
                if(Min>(vec[i+1]-vec[i]))
                {
                    Min = vec[i+1]-vec[i];
                    r1 = vec[i];
                    r2 = vec[i+1];
                }
            }
            if(cnt>=2)
                printf("%lld,%lld are closest, %lld,%lld are most distant.\n",r1,r2,r3,r4);
            else
                printf("There are no adjacent primes.\n");
        }
        else
        {
            vector<ll> vec;
            for(i = a; i <= b; i++)
            {
                if(is_prime(i))
                {
                    vec.push_back(i);
                    cnt++;
                }
            }
            for(i = 0; i < vec.size()-1; i++)
            {
                 /*Finding the largest distance*/
                if(Max<(vec[i+1]-vec[i]))
                {
                    Max = vec[i+1]-vec[i];
                    r3 = vec[i];
                    r4 = vec[i+1];
                }
                /*Finding the minimum distance*/
                if(Min>(vec[i+1]-vec[i]))
                {
                    Min = vec[i+1]-vec[i];
                    r1 = vec[i];
                    r2 = vec[i+1];
                }
            }
            if(cnt>=2)
                printf("%lld,%lld are closest, %lld,%lld are most distant.\n",r1,r2,r3,r4);
            else
                printf("There are no adjacent primes.\n");

        }

    }
}


