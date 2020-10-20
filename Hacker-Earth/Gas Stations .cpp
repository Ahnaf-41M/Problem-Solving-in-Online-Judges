#include <iostream>
using namespace std;

int main()
{
    long int n,x,g,cnt=0;
    cin>>n>>x;
    long int temp =x;
    while(n--)
    {
        cin>>g;
        temp=temp-g;
        if(temp>0)
        {
            cnt ++;
        }
        else
        {
            break;
        }
    }
    cout<<cnt+1;
    return 0;
}
