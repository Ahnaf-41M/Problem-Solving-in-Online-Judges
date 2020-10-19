#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n;
    bool flag=false;
    char song[][16]= {"Happy","birthday","to","you",
                      "Happy","birthday","to","you",
                      "Happy","birthday","to","Rujia",
                      "Happy","birthday","to","you"
                     };
    char name[101][101];

    scanf("%d",&n);

    for(i = 0; i < n; i++)
        scanf("%s",&name[i]);

    i=0,j=0;
    while(true)
    {
        printf("%s: %s\n",name[i],song[j]);
        if(i==n-1)
            flag = true;

        if(j==15 && flag)
            break;

        i++,j++;
        if(i>=n)
            i=0;
        if(j>=16)
            j=0;

    }

}
