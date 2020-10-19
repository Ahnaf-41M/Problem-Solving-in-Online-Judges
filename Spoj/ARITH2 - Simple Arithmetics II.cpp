#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n, ans;
    char ch;

    cin >> t;

    while (t--)
    {
        cin >> n;

        while (true)
        {
            cin >> ch;

            if (ch == '=')
                break;
            cin >> ans;

            if (ch == '/')
                n /= ans;
            else if (ch == '*')
                n *= ans;
            else if (ch == '+')
                n += ans;
            else
                n -= ans;
        }
        cout << n << endl;
    }
}