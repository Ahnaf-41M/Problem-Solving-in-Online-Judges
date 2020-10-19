#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i;

    scanf("%lld",&n);
    //getchar();
    getchar();
    while(n--)
    {
        long long x;
        long long cnt=0;
        string s,s2;
        cin>>s;
        s2=s;
        scanf("%lld",&x);
        while(next_permutation(s.begin(),s.end()))
        {
            if(s==s2)
                break;
            cnt++;
        }
        if(x>cnt)
            x = (x%cnt)+cnt;

        for(i = 1; i <= x; i++)
            next_permutation(s2.begin(),s2.end());

        cout<<s2<<endl;
     }
}
