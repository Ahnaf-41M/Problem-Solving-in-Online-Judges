#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
bool a[mx+5];
int val[mx+5];
vector<int> v,nums;
set<int> temp;
void sieve()
{
    int i,j;
    a[2] = true;
    for(i = 3; i <= mx; i+=2)
        a[i] = true;

    for(i = 2; i <= sqrt(mx); i++)
    {
        if(a[i])
        {
            for(j = i*i; j <= mx; j+=i)
                a[j] = false;
        }
    }
    v.push_back(2);
    for(i = 3; i <= mx; i+=2)
        if(a[i])
            v.push_back(i);
}
void find_div()
{
    int i,j;

    for(i = 2;  i <= mx; i++){
          val[i]++;
        for(j = i; j <= mx; j+=i){
            val[j]++;
        }
    }

    nums.push_back(0);
    nums.push_back(1);
    for(i = 2; i <= mx; i++)
     nums.push_back(val[i]);
}

void prime_fact()
{
     int i,j;
     int d;
     temp.insert(0);

     for(i = 2; i < nums.size(); i++)
     {
          for(j = 0; j < v.size() && v[j] < nums[i]; j++)
          {
               d = nums[i]/v[j];
               if(nums[i] % v[j] == 0 && d != v[j])
               {
                    if(a[d])
                         temp.insert(i);
               }
          }
     }
}
int main()
{
    sieve();
    find_div();
    prime_fact();
    vector<int> ans(temp.begin(),temp.end());
    //cout<<nums.size();
    //cout<<ans[9];
    for(int i = 9; i < ans.size(); i+=9)
        cout<<ans[i]<<endl;
}
