#include<bits/stdc++.h>
using namespace std;

struct data
{
    int id,penalty,solved;
};

bool cmp(data a, data b)
{
    if(a.solved == b.solved)
    {
        if(a.penalty==b.penalty)
        {
            return a.id<b.id;
        }
        else
            return a.penalty<b.penalty;
    }
    else
        return a.solved>b.solved;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    getchar();

    int probSolved[105],store[105],problemTime[105],contProb[105][11];
    bool isSolved[105][11],contestantId[105];

    while(t--)
    {
        memset(probSolved,0,sizeof(probSolved));
        memset(store,0,sizeof(store));
        memset(problemTime,0,sizeof(problemTime));
        memset(contProb,0,sizeof(contProb));
        memset(isSolved,false,sizeof(isSolved));
        memset(contestantId,false,sizeof(contestantId));

        int cid,prob,time;
        ///cid=contestant id, prob and time=problem solving time

        char verdict;
        int cnt=0;///for counting total unique contestants

        char buffer[100];

        while(gets(buffer) && strlen(buffer)>0)
        {
            sscanf(buffer,"%d %d %d %c",&cid,&prob,&time,&verdict);

            if(!contestantId[cid]) ///checking if the id is already been taken or not
            {
                contestantId[cid]=true;
                store[cnt] = cid; ///storing the id's
                cnt++; ///incrementing contestants(counting)
            }
            if(verdict=='R' || verdict=='U' || verdict=='E')
                continue;
            if(verdict=='C' && !isSolved[cid][prob])
            {
                isSolved[cid][prob] = true;
                problemTime[cid] += time + contProb[cid][prob];
                ///Here contProb[][] stores the penalty time for a distinct problem
                probSolved[cid]++; ///incrementing the solve for that contestant
            }
            else if(verdict=='I' && !isSolved[cid][prob])
            {
                contProb[cid][prob]+=20; ///adding penalty time
            }
        }
        data man[200];

        for(int i = 0; i < cnt; i++)
        {
            if(contestantId[store[i]])
            {
                man[i].id = store[i];
                man[i].penalty = problemTime[store[i]];
                man[i].solved = probSolved[store[i]];
            }
        }
        sort(man,man+cnt,cmp); ///sorting calling compare function

        for(int i = 0; i < cnt; i++)
        {
            cout<<man[i].id<<' '<<man[i].solved<<' '<<man[i].penalty<<endl;
        }
        if(t)
          printf("\n");
    }
}
