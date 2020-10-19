#include<bits/stdc++.h>
using namespace std;

int revnum(long n)
{
    int rem=0;
    while(n>0)
            {
                rem = n%10 + rem*10;
                n = n/10;
            }

            return rem;
}

int main()
{
    long t,count = 0,n,rem = 0,p,sum=0,i;

    cin>>t;

    for(i = 0; i < t; i++)
    {
        cin>>n;
        p = n;
        rem = 0;
        count = 0;
        rem = revnum(n);

        while(rem!=n)
        {
            n+=rem;
            rem = revnum(n);
            count++;
        }

        cout<<count<<" "<<rem<<endl;


    }
    return 0;
}
