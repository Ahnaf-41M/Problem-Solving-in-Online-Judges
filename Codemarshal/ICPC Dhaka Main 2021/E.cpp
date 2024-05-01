
#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

vector<int> tot_days[212];

void Solve(int tc)
{
    int NC;
    cin >> NC;
    for(int i = 1; i <= NC; i++){
        int p;
        tot_days[i].pb(0);
        cin >> p;
        for(int j = 1; j <= p; j++){
            int days; cin >> days;
            tot_days[i].pb(tot_days[i].back() + days);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int cal1,cal2,day,month,year;

        cin >> cal1 >> cal2 >> day >> month >> year;

        int ansD = tot_days[cal1].back() * (year-1) + tot_days[cal1][month-1] + day;
        int ansM=1,ansY=0;
        while(ansD > tot_days[cal2].back()) {
            ansD -= tot_days[cal2].back();
            ansY++;
        }

        int i = 1, len = tot_days[cal2].size()-1;
        while(ansM <= len && tot_days[cal2][ansM] < ansD) ansM++;
        ansD -= tot_days[cal2][ansM-1];

        cout << ansD << " " << ansM << " " << ansY + 1 << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
//    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        Solve(tc);
    }

    return 0;
}
