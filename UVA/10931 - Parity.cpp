#include<bits/stdc++.h>
using namespace std;


int main()
{
    unsigned int n,s,cnt = 0,i;
   int a[10000];
    string st;

    while(cin>>n,n>0)
    {
        cnt = 0;
        int p = n,sum=0;
        i = 0;

        while(n>0)
        {

            s = n%2;
            a[i] = s;

            if(s==1)
                cnt++;

            n = n/2;
            i++;

        }
        cout<<"The parity of ";
        for(int k = i-1; k >= 0; k--)
           {
               if(k==i && a[k]==0)
                cout<<"";

               else
                cout<<a[k];
           }
        cout<<" is "<<cnt<<" (mod 2).\n";

    }
    return 0;
}
