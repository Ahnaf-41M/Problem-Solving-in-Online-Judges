 #include<bits/stdc++.h>

using namespace std;

#define MAX 4003

#define len 1000

int fib[MAX][len];

void fivonaccy()

{

int i,j;

fib[0][0]=0;

fib [1][0]=1;

for(i=2; i<MAX; i++)

{

for(j=0; j<len; j++)

{

fib [i][j]= fib[i][j]+fib[i-1][j]+fib[i-2][j];

if(fib[i][j]>9)

{

fib[i][j+1]=fib[i][j]/10;

fib[i][j]=fib[i][j]%10;

}

}

}

}

int main()

{

fivonaccy();

int i,j,k,n;

while(cin>>n)

{

for(i=len-1; i>=0; i--)

{

if(fib[n][i]!=0)

break;

}

for(j=i; j>=0; j--)

{

printf("%d",fib[n][j]);

}

printf("\n");

}

return 0;

}
