#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int  t,i,n,c1,c2,j;
    string s;

    scanf("%ld",&t);

    for(i = 1; i <= t; i++)
    {

        long int sum=0;
        cin>>s;
        scanf("%ld",&n);

        if(s[0]=='-')j=1;
        else j=0;
        for(;j < s.size();j++)
        {
             sum = sum*10+s[j]-'0';
             sum = sum%n;
        }
        if(sum==0)
            printf("Case %ld: divisible\n",i);
        else
            printf("Case %ld: not divisible\n",i);


    }
}
