#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll i,n,mx,mn,sum=0;

     cin>>n;
     ll a[n];
     for(i = 0; i < n; i++){
          cin>>a[i];
          sum+=a[i];
     }

     mn = *min_element(a,a+n);
     mx = *max_element(a,a+n);

     cout<<sum-mx<<" "<<sum-mn<<endl;

}
