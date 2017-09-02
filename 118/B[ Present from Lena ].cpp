#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n 


char S[11][26];

int main()
{
	int n,i,j,k,l;

	sd(n);

	for(i=0;i<=n;i++)
	{
		for(j=0;j<(2*i+1)+(n-i);j++)
			if(j<n-i)
				S[i][j] = &#39; &#39;;
			else
			{
				if(j<n+1)
					S[i][j] =	j-n+i + &#39;0&#39;;
				else
					S[i][j] = S[i][n - (j - n)];
			}
		S[i][j] = &#39;\0&#39;;
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<(2*i+1)+(n-i);j++)
		{
			if( (2*i+1)+(n-i)-j > 1 )
				printf("%c ", S[i][j]);
			else
				printf("%c", S[i][j]);
		}
		printf("\n");
	}	

	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<(2*i+1)+(n-i);j++)
		{
			if( (2*i+1)+(n-i)-j > 1 )
				printf("%c ", S[i][j]);
			else
				printf("%c", S[i][j]);
		}
		printf("\n");
	}

	return 0;
}
