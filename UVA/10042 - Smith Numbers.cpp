/* In number theory, a Smith number is a composite number for which,
in a given number base, the sum of its digits is equal to the sum
of the digits in its prime factorization in the given number base. */
#include<bits/stdc++.h>
#define sc scanf
#define pf printf
#define ll long long
using namespace std;

bool is_smith(ll n)
{
    int i,j;
    vector<int> tmp;/*For storing prime factors*/
    int p = n;
    for(i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                tmp.push_back(i);
                n/=i;
            }
        }
    }
    if(n>1 && n!=p) /*prime numbers are not included*/
        tmp.push_back(n);

    int sum1=0,sum2=0;
    /*Sum of digits of the number*/
    while(p)
    {
        sum1+=p%10;
        p/=10;
    }
     /*Sum of digits of the prime factors of the number*/
    for(i = 0; i < tmp.size(); i++)
    {
        p = tmp[i];
        while(p)
        {
            sum2+=p%10;
            p/=10;
        }
    }
    if(sum1==sum2)
        return true;
    return false;

}
int main()
{
    int n,i,t;

    sc("%d",&t);

    while(t--)
    {
        sc("%d",&n);

        for(i = n+1; ; i++)
            if(is_smith(i))
            {
                pf("%d\n",i);
                break;
            }
    }
}
