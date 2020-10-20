#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=0;
        //bool no=false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'
                    ||s[i]=='O')
            {
                n++;

            }

        }
        if(n<6)
        {
            if(n==1)
                cout<<1<<" BALL\n";
            else
                cout<<n<<" BALLS\n";
        }
        else
        {
            if(n/6==1)
            {
                cout<<1<<" OVER";
                if(n%6==1)
                    cout<<' '<<1<<" BALL\n";
                else if(n%6>1)
                    cout<<' '<<n%6<<" BALLS\n";
                else
                    cout<<'\n';
            }
            else
            {
                cout<<n/6<<" OVERS";
                if(n%6==1)
                    cout<<' '<<1<<" BALL\n";
                else if(n%6>1)
                    cout<<' '<<n%6<<" BALLS\n";
                else
                    cout<<'\n';
            }
        }
    }

}
