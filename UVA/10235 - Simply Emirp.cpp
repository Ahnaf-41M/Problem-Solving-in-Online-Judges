#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,rem,i,j,c,c1,p;

    while(cin>>n)
    {
        p=n;
        rem=0;
        c=0,c1=0;
        for(i = 2; i <= sqrt(n); i++)
        {
            if(n%i==0)
                c++;
        }
        if(c>=1)
            cout<<n<<" is not prime.\n";

        else
        {
            while(n>0)
            {
                rem = n%10+rem*10;
                n=n/10;
            }

            for(i = 2; i <= sqrt(rem); i++)
            {
                if(rem%i==0)
                c1++;
            }
            if(rem==p)
                cout<<p<<" is prime.\n";
            else if(c1>=1)
                cout<<p<<" is prime.\n";
                else
                    cout<<p<<" is emirp.\n";
        }

    }
    return 0;
}
