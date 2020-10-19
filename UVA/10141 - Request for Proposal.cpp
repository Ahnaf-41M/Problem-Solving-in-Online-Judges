#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,tc=1;

    string s1;

    while(cin>>n>>p,n||p)
    {
        double d,dd=2000000000;
        int rr=-1,r;
        string s2,s3;
        for(int i = 0; i < n; i++)
        {
            cin.ignore();
            getline(cin,s1);
        }

        while(p--)
        {
            getline(cin,s2);
            scanf("%lf %d\n",&d,&r);
            if(r>rr)
            {
                rr = r;
                dd = d;
                s3 = s2;
            }
            else if(r==rr && d<dd)
            {
                rr = r;
                dd = d;
                s3 = s2;
            }

            for(int i = 0; i < r; i++)
            {
                getline(cin,s1);
            }
        }
        if(tc>1)
            cout<<endl;
        cout<<"RFP #"<<tc<<endl;
        cout<<s3<<endl;

        tc++;
    }

}

