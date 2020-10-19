#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   int t, i;
   scanf("%d", &t);

   for (i = 1; i <= t; i++)
   {
      printf("Case %d:\n", i);

      stack<string> back, forward;
      back.push("http://www.lightoj.com/");

      while (1)
      {
         string s1, s2;
         cin >> s1;

         if (s1 == "VISIT") {
            cin >> s2;
            cout << s2 << endl;
            back.push(s2);

            while (!forward.empty()) forward.pop();
         }
         else if (s1 == "BACK") {
            if (back.size() == 1) {
               cout << "Ignored\n";
            }
            else {
               forward.push(back.top());
               back.pop();
               cout << back.top() << endl;
            }
         }
         else if (s1 == "FORWARD") {
            if (forward.empty()) cout << "Ignored\n";
            else {
               cout << forward.top() << endl;
               back.push(forward.top());
               forward.pop();
            }
         }
         else
            break;
      }
   }

   return 0;
}