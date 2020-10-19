#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;

int main()
{
    int s,a,r;
    double arc,a2,chord,a3;
    char p[5];

    while(cin>>s>>a>>p)
    {
        if(p[0]=='d')
        {
            if(a>180)a=360-a;

            r = s+6440;
            arc = (2*pi*r*1.0*a)/360;
            a3=a*1.0/2;
            chord = (2*r*1.0)*sin(a3*pi*1.0/180);

            printf("%lf %lf\n",fabs(arc),fabs(chord));
        }
        else
        {
            if(a>180)a=360-a;

            a2 = a*0.01666666667*1.0;
            r = s+6440;
            arc = (2*pi*r*1.0*a2)/360;
            a2 = a2/2;
            chord = (2*r*1.0)*sin(a2*pi*1.0/180);

            printf("%lf %lf\n",fabs(arc),fabs(chord));

        }
    }
    return 0;
}

