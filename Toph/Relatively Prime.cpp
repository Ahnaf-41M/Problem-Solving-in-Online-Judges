#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int phi[MAX];
void find_phi()
{
    int i,j;
    for(i=2; i<=MAX; i++)
        phi[i]=i;
    for(i=2; i<=MAX; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<=MAX; j+=i)
                phi[j]-=phi[j]/i;//Inclusion_Exclusion Law use
        }
    }
}
int main()
{
    find_phi();
    int n;


    cin>>n;
    cout<<phi[n]<<endl;

}

