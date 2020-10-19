#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,h,o;

    while(cin>>p>>h>>o)
    {
        if(h-(o-p)>0)
            cout<<"Hunters win!\n";
        else
            cout<<"Props win!\n";
    }

    return 0;
}
