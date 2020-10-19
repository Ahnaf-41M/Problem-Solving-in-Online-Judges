#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
     int t,n,x,cnt=0,unq=0,LastRepeated=0,ans;


     scanf("%d",&t);

     while(t--)
     {
          scanf("%d",&n);
          map<int,int> LastSeen;
          LastRepeated=0,ans=0,cnt=0;

          for(int i = 1; i <= n; i++)
          {
               scanf("%d",&x);
               int chk = LastSeen[x];

               if(chk!=0)
               {
                    LastRepeated= max(LastRepeated,chk); //Last index of the value that wasn't unique
                    cnt = i-LastRepeated-1;
               }
               cnt++; //counts unique values..
               ans = max(ans,cnt);
               LastSeen[x] = i; //Last index of the value so far..
          }
          printf("%d\n",ans);
     }
}
