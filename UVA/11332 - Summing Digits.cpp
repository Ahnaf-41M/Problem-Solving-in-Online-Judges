#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum=0;

    while(cin>>n,n>0)
    {
        sum=0;
        while(n!=0)
        {
            sum = sum+n%10;
            n = n/10;


            if(n==0 && sum/10==0)
            {
                break;
            }
            if(n==0)
            {
               n = sum;
               sum=0;
            }

        }
        cout<<sum<<endl;
    }

}
