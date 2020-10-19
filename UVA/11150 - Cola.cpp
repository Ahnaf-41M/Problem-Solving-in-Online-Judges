#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,rem = 0,p;

    while(cin>>n)
    {
        p = n;

        while(n>0)
        {
            rem = rem+n/3;
            n = n/3+n%3;

            if(n<3)
            {
                rem+=1;
                break;
            }
        }
        if(p & 1)
        cout<<rem+p-1<<endl;
        else
        cout<<rem+p<<endl;

        rem = 0;
    }

    return 0;
}
