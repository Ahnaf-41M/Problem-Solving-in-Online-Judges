#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,b,rem,j,i,k;
    double x;

    cin>>t;
    i=0;
    while(t--)
    {
        i++;

        cin>>n>>b;
        rem=0;
        j=0;
        rem = n%10;
        for(k=8;n>0 ; k*=b)
        {
            n = n/10;
            rem = rem+(n%10)*k;
        }
        x = ((rem*log10(rem/M_E))+(log10(2*rem*M_PI))/2.0);
        x = floor(x)+1;

        cout<<"Case "<<i<<": "<<x<<endl;


    }
    return 0;
}
