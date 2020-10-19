#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string s;

    for(i = 1; ;i++)
    {
        cin>>s;
        if(s=="*")
            break;
        else
        {
            if(s == "Hajj")
                cout<<"Case "<<i<<": Hajj-e-Akbar\n";
            else
                cout<<"Case "<<i<<": Hajj-e-Asghar\n";
        }
    }

    return 0;
}
