#include<bits/stdc++.h>

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define ll long long
#define pb push_back
#define PI M_PI
#define endl "\n"
#define sc scanf
#define pf printf
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool check(stack<char> &s)
{
    if(s.size()<2) /*As size of 100 is 3*/
        return false;

    char last = s.top(); /*Second last element of 100*/
    if(last=='1')
        return false;
    s.pop();

    char before_last = s.top(); /*First element of 100*/
    s.push(last);

    if(before_last=='1')
        return true; /*if the first element is 1 then return true*/
    else
        return false; /*if the first element is 0 then return false*/

}
int main()
{
    //IOS
    int i,t;
    char ch;

    sc("%d",&t);
    getchar();

    for(i = 1; i <= t; i++)
    {
        stack<char> s;

        while((ch = getchar()) !='\n' )
        {
            if(ch=='0' && check(s))
            {
                s.pop();
                s.pop();
            }
            else
                s.push(ch);
        }
        if(!s.empty())
          pf("Case %d: no\n",i);
        else
          pf("Case %d: yes\n",i);
    }



    return 0;
}

