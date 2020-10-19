#include<bits/stdc++.h>
using namespace std;

int gcd(int A, int B)
{
    if(A==0)
        return B;

    return gcd(B%A,A);
}

int main()
{
    int A,B,X,Y,D;

    while(cin>>A>>B)
    {
        D = gcd(A,B);
        X = (D-B)/A;

        cout<<X<<" "<<1<<" "<<D<<endl;
    }
}
