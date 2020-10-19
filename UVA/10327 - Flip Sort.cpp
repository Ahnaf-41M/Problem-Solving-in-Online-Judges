#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,k,cnt,t;


    while(cin>>n)
    {

        int a[n];

        for(i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        cnt = 0;

        for(i = 1; i < n; ++i)
        {
            for(j = 0; j < i; ++j)
            {
                if(a[j] > a[i])
                {
                    cnt++;
                }

            }
        }
        cout<<"Minimum exchange operations : "<<cnt<<endl;
    }
    return 0;
}
