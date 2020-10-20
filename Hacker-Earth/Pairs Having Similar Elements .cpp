#include<bits/stdc++.h>
using namespace std;
#define ll long

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    long N;
    cin >> N;
    ll arr[N];

    for(long i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    ll n=1,k=1,s=0;
    sort(arr,arr+N);
    for(ll i=0; i<N; i++)
    {
        if((arr[i]-arr[i+1])==1||(arr[i]-arr[i+1])==-1)
            n++;
        else if(arr[i]==arr[i+1])
        {
            n++;
            k++;
        }
        else
        {

            if(k!=n)
                s=s+(n*(n-1)/2);
            n=1;
            k=1;
        }

    }
    cout<<s;

}
