#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[100];
int main()
{
    IOS

    string s1,s2,s3;
    int n,t,tc,money,people,i,j;
    vector<string> v;
    cin>>t;
    while(1)
    {
        map<string,int> vm;

        for(i = 0; i < t; i++)
        {
            cin>>s1;
            v.push_back(s1);
            vm[s1]=0;
        }

        for(j = 0; j < t; j++)
        {
            cin>>s2>>money>>people;
            if(people!=0)
            {
                vm[s2]+=(money%people);
                vm[s2]-=money;
            }
            for(i = 0; i < people; i++)
            {
                cin>>s3;
                vm[s3]+=(money/people);
            }
        }
        for(j = 0; j < t; j++)
        {
            cout<<v[j]<<" "<<vm[v[j]]<<endl;
        }
        //cout<<endl;
        v.clear();
        if(cin>>t)cout<<endl;
        else break;
    }
}
