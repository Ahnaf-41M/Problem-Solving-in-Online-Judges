#include<bits/stdc++.h>
using namespace std;

int main()
{
    int e,f,c,i,rem,n,t;

    cin>>t;

    for(i = 1; i <= t; i++)
    {
        cin>>e>>f>>c;

        n = e+f;
        rem = 0;
        while(n>0)
        {
            rem = rem+n/c;
            n = n/c+n%c;

            if(n<c)
            {
                break;
            }
        }
        cout<<rem<<endl;

    }

    return 0;
}
