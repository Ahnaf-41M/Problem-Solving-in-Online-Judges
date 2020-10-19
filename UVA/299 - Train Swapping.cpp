#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,k,cnt,t;

    cin>>t;

    while(t--)
    {
        cin>>n;
        int a[n];

        for(i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        cnt = 0;

        for(i = 0; i < n; i++)
        {
            for(j = i; j < n; j++)
            {
                if(a[i] > a[j])
                {
                    k = a[j];
                    a[j] = a[i];
                    a[i] = k;
                    cnt++;
                }

            }
        }
        cout<<"Optimal train swapping takes "<<cnt<<" swaps.\n";
    }
    return 0;
}
