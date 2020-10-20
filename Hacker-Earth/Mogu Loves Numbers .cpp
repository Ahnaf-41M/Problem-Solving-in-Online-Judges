#include<bits/stdc++.h>
using namespace std;
#define fast ios_base:: sync_with_stdio(false),cin.tie(0),cout.tie(0);

typedef long long ll;
const ll N = 1e6 +6 ;
bool isPrime[N+1];
int ans[N+1]= {0};
int main()
{
//fast;
    for(int i=0; i <N ; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;

    for(int i=2 ; i*i <= N ; i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i ; j<=N; j+=i)
                isPrime[j] = false;
        }
    }

    ans[0] = ans[1] = 0;
    for(int i=2; i<=N ; i++)
        ans[i] = (isPrime[i]==true) + ans[i-1];

    int Q,L,R;
//cout<<ans[6]<<endl;
    cin >> Q;

    while(Q--)
    {
        cin >> L >> R;
        if(L>R)
            swap(L,R);
        cout << ans[R]- ans[L-1] << "\n";
    }
}
