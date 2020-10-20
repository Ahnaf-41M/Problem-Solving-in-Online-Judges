#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,sum=0,t;

    cin>>t;

    while(t--)
    {
        cin>>n;
        if(n==1)
            cout<<"0\n";
        else
        {
            for(i = 2; i <=sqrt(n); i++)
            {
                if(n%i==0)
                {
                    if(n/i==i)
                        sum+=i;
                    else
                    {
                        sum+=i;
                        sum+=n/i;
                    }
                }

            }
        }
        if(n!=1)
            cout<<sum+1<<endl;
        sum=0;
    }
}
