#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m,n,cnt=0,rem=0;

    while(cin>>m>>n,m>0,n>0)
    {
        cnt =  0;
        rem = 0;
        while(m||n)
        {

            rem = (m%10+n%10+rem)/10;

            m = m/10;
            n = n/10;
            cnt+=rem;
        }
        if(cnt==0)
            cout<<"No carry operation.\n";
        else
        {
            cout<<cnt<<" carry operations.\n";
        }
    }
    return 0;
}
