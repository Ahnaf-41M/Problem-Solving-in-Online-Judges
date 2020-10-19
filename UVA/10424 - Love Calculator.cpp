#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    double num1=0,num2=0,ptg=0;
    int i;

    while(getline(cin,s1),getline(cin,s2))
    {
        int p1=0,p2=0,f3=0,f4=0;
        for(i = 0; i < s1.size(); i++)
        {
            if(s1[i]>='a' && s1[i]<='z')
            {
                p1+=(s1[i]-96);
            }
            else if(s1[i]>='A' && s1[i]<= 'Z')
            {
                p1+=(s1[i]-64);
            }
        }
        while(1)
        {
            f3+=(p1%10);
            p1/=10;
            if(p1==0 && f3/10==0)
                break;
            else if(p1==0)
            {
                p1=f3;
                f3=0;
            }
        }
        for(i = 0; i < s2.size(); i++)
        {
            if(s2[i]>='a' && s2[i]<='z')
            {
                p2+=(s2[i]-96);
            }
            else if(s2[i]>='A' && s2[i]<= 'Z')
            {
                p2+=(s2[i]-64);
            }
        }
        while(1)
        {
            f4+=(p2%10);
            p2/=10;
            if(p2==0 && f4/10==0)
                break;
            else if(p2==0)
            {
                p2=f4;
                f4=0;
            }
        }
        p1 = max(f3,f4);
        p2 = min(f3,f4);
        ptg = ((1.0*p2)/(1.0*p1))*100.0;
        printf("%.2lf %%\n",ptg);
    }
}
