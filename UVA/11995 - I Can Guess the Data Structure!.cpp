#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;

    while(scanf("%d",&n)!=EOF)
    {
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;
        bool iSpq=true,iSq=true,iSs=true;
        while(n--)
        {
            scanf("%d%d",&x,&y);
            if(x==1)
            {
                if(iSpq)
                    pq.push(y);
                if(iSq)
                    q.push(y);
                if(iSs)
                    s.push(y);
            }
            else
            {
                if(iSs)
                {
                    if(s.empty()||s.top()!=y)
                         iSs = false;
                    else
                         s.pop();
                }
                if(iSpq)
                {
                    if(pq.empty() || pq.top()!=y)
                         iSpq = false;
                    else
                         pq.pop();
                }
                if(iSq)
                {
                    if(q.empty() || q.front()!=y)
                         iSq = false;
                    else
                         q.pop();
                }
            }
        }
        if((iSs&&iSpq) ||(iSs&&iSq) ||(iSq&&iSpq))
            printf("not sure\n");
        else if(iSs)
            printf("stack\n");
        else if(iSpq)
            printf("priority queue\n");
        else if(iSq)
            printf("queue\n");
        else
            printf("impossible\n");

    }
}
