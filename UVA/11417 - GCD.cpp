#include<bits/stdc++.h>
using namespace std;

#define MAX 505

// phi[i] stores euler totient function for i result[j] stores result for value j
long long phi[MAX], result[MAX];

// Precomputation of phi[] numbers
void computeTotient()
{
    phi[1] = 1;
    for (int i=2; i<MAX; i++)
    {
        if (!phi[i])
        {
            phi[i] = i-1;
            for (int j = (i<<1); j<MAX; j+=i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }
}

void sumOfGcdPairs()
{
    computeTotient();

    for (int i=1; i<MAX; ++i)
    {
          for (int j=2; i*j<MAX; ++j)
            result[i*j] += i*phi[j];
    }

    for (int i=2; i<MAX; i++)
        result[i] += result[i-1];
}
int main()
{
    sumOfGcdPairs();

    int n;
    while(cin>>n && n!=0)
    {
         cout<<result[n]<<endl;
    }

    return 0;
}
