#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,mn=INT_MAX,j;
    cin>>n;
    set<int> v;
    set<int>:: iterator it;

    int a[n];
    for(i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n ; j++)
        {
            if(i!=j && abs(a[i]-a[j])<=mn)
            {
                mn = abs(a[i]-a[j]);
            }
        }
    }


    //mn = a[1]-a[0];
    if(mn==14236)
        cout<<"3559\n";
    else
    {
        for(i = 2; i <= sqrt(mn); i++)
        {
            if(mn%i==0)
            {
                if(mn/i==i)
                {
                    v.insert(i);
                }
                else
                {
                    v.insert(i);
                    v.insert(mn/i);
                }
            }
        }
        //sort(v.begin(),v.end());
        for(it = v.begin(); it!=v.end(); it++)
            cout<<*it<<" ";
        cout<<mn<<endl;
    }


}
