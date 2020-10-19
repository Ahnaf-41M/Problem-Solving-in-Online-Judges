#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    int a[100000],i;

    while(cin>>n,n>=0)
    {
        i=0;;
        if(n==0)
            cout<<"0\n";

        else
        {
            while(n>0)
            {
                a[i++] = n%3;
                n = n/3;
            }

            for(int j = i-1; j>=0; j--)
            {
                cout<<a[j];
            }
            cout<<endl;
        }
    }

    return 0;
}
