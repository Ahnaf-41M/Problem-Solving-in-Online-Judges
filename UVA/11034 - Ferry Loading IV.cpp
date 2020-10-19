#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,l,capacity,t,sum=0,flag=0,cnt;


    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&capacity,&n);
        capacity*=100;
        sum=0;
        cnt=0;
        queue<int> Right,Left;
        string position;

        for(i = 0; i < n; i++)
        {
            cin>>l>>position;
            if(position[0]=='r')
               Right.push(l);
            else
               Left.push(l);

        }
        flag=1;
        while(!Right.empty() || !Left.empty())
        {
             cnt++;
             sum=0;

             if(flag)
             {
                  while(!Left.empty() && sum+Left.front() <= capacity)
                  {
                       sum+=Left.front();
                       Left.pop();
                  }
             }
             else
             {
                  while(!Right.empty() && sum+Right.front() <= capacity)
                  {
                       sum+=Right.front();
                       Right.pop();
                  }
             }
             flag = 1-flag;
        }

        printf("%d\n",cnt);
    }

}
