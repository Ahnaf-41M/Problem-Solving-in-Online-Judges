#include<bits/stdc++.h>
using namespace std;
#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01

int main()
{
    string s;
    double sum,n=0.0;
    int i,j,t;


    cin>>t;

    while(t--)
    {
        cin>>s;
        sum = 0.0;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                n = n*10+(s[i]-48);
                j++;
            }
            else if(s[i-j-1]=='C' &&s[i-j]>='0' && s[i-j]<='9')
            {
                sum = sum + n*C - C;
                n = 0;
                j = 0;
            }
            else if(s[i] == 'C')
            {
                sum = sum+C;
            }
            else if(s[i-j-1]=='H' &&s[i-j]>='0' && s[i-j]<='9')
            {
                sum = sum + n*H - H;
                n = 0;
                j = 0;
            }
            else if(s[i] == 'H')
            {
                sum = sum+H;
            }
            else if(s[i-j-1]=='N' &&s[i-j]>='0' && s[i-j]<='9')
            {
                sum = sum + n*N - N;
                n = 0;
                j = 0;
            }
            else if(s[i] == 'N')
            {
                sum = sum+N;
            }
            else if(s[i-j-1]=='O' &&s[i-j]>='0' && s[i-j]<='9')
            {
                sum = sum + n*O - O;
                n = 0;
                j = 0;
            }
            else if(s[i] == 'O')
            {
                sum = sum+O;
            }
            if(s.size()-i == 1)
            {
                if(s[i]>='0' && s[i]<='9' && s[i] =='C')
                {
                    n = n*10;
                    sum = sum+n*C - C;
                }
                if(s[i]>='0' && s[i]<='9' && s[i] =='H')
                {
                    n = n*10;
                    sum = sum+n*H - H;
                }
                if(s[i]>='0' && s[i]<='9' && s[i] =='N')
                {
                    n = n*10;
                    sum = sum+n*N - N;
                }
                if(s[i]>='0' && s[i]<='9' && s[i] =='O')
                {
                    n = n*10;
                    sum = sum+n*O - O;
                }
                if(s[i] == 'C')
                {
                    sum = sum + C;
                }
                if(s[i] == 'O')
                {
                    sum = sum + O;
                }
                if(s[i] == 'H')
                {
                    sum = sum + H;
                }
                if(s[i] == 'N')
                {
                    sum = sum + N;
                }
            }
        }
        cout<<sum<<endl;


    }

    return 0;


}
