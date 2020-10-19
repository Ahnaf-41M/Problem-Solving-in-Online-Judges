#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[13];
    a[1]=1;
    for(int i=2; i <= 10;i++)
     a[i] = i*a[i-1];
    cout<<a[10]/(a[3]*3);


}
