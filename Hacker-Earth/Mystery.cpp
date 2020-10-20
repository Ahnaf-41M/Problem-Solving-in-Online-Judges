#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,c=0;
    cin>>t;

    while(t--)
    {
        cin>>n;
        for(i = 2; i <= sqrt(n); i++)
        {
            if(n%i==0)
            {
                if(n/i==i)
                    c++;
                else
                    c+=2;
            }
        }
        if(n!=1)
            cout<<c+2<<endl;
        else
            cout<<"1\n"<<endl;
        c=0;
    }
}
