#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int i;


    while(cin>>s){

        for(i = 0; i < s.size(); i++)
        {

                s[i] = s[i] - 7;

        }
        cout<<s<<endl;
    }
    return 0;
}
