#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int t;
   scanf("%d", &t);

   for (int i = 1; i <= t; i++)
   {
      int n, m, x;
      deque<int> dq;
      string dir;

      scanf("%d%d", &n, &m);
      printf("Case %d:\n", i);

      W(m)
      {
         cin >> dir;
         if (dir == "pushLeft") {
            cin >> x;
            if (dq.size() < n) {
               dq.push_front(x);
               cout << "Pushed in left: " << x << endl;
            }
            else {
               cout << "The queue is full\n";
            }
         }
         else if (dir == "pushRight") {
            cin >> x;
            if (dq.size() < n) {
               dq.push_back(x);
               cout << "Pushed in right: " << x << endl;
            }
            else {
               cout << "The queue is full\n";
            }
         }
         else if (dir == "popLeft") {
            if (dq.empty()) {
               cout << "The queue is empty\n";
            }
            else {
               cout << "Popped from left: " << dq.front() << endl;
               dq.pop_front();
            }
         }
         else if (dir == "popRight") {
            if (dq.empty()) {
               cout << "The queue is empty\n";
            }
            else {
               cout << "Popped from right: " << dq.back() << endl;
               dq.pop_back();
            }
         }
      }
   }

   return 0;
}