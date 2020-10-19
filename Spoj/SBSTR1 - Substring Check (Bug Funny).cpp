#include<bits/stdc++.h>
using namespace std;

int main()
{
    string txt,pat;
    int i,n,m,j,c=0;
    int t = 24;
    while(t--){
    cin>>txt>>pat;

    n = txt.size();
    m = pat.size();

    j=0,i=0;
    while(i<=n)
    {
        if(j==m)
        {
            cout<<"1\n";
            j--;
            i++;
            c=1;
            break;
        }
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(txt[i]!=pat[j] && j>0)
        {
            j--;
        }
        else if(j==0)
        {
            i++;
        }
    }
    if(c!=1)
    {
        cout<<"0\n";
    }
    }

    return 0;

}
