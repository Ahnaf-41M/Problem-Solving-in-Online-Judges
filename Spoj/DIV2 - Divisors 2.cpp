#include<bits/stdc++.h>
using namespace std;

#define mx 1000000
int divisor[mx+5];
bool solve[mx+5];
vector<int> v;
set<int> s;

void find_div()
{
    int i,j;
    for(i = 1; i <= mx; i++)
        for(j = i; j <= mx; j+=i)
            divisor[j]++;
}
void func()
{
    int i,j;
    memset(solve,true,sizeof(solve));
    for(i = 1; i <= mx; i++)
    {
        for(j = i; j <= mx; j+=i)
        {
            if(divisor[j] % divisor[i] !=0 || divisor[j]<=3)
                solve[j] = false;
        }
    }
    for(i = 1; i <= mx; i++)
     if(solve[i])
     v.push_back(i);

}
int main()
{
     int i;
     find_div();
     func();

     for(i = 107; i <= v.size(); i+=108)
          cout<<v[i]<<endl;
}
