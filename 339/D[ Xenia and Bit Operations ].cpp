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

int DP[(1<<18)][20];

int main()
{
	int i,j,k,l,m,n;

	sd(n);	sd(m);

	k = n;
	n = (1<<n);

	for(i=0;i<n;i++)
		sd(DP[i][0]);

	for(i=1;i<=k;i++)
	{
		l = (1<<(k-i));
		if(i%2 == 1) // OR
		{
			for(j=0;j<l;j++)
			{
				DP[j][i] = DP[2*j][i-1] | DP[2*j+1][i-1];
			}	
		}
		else
		{
			for(j=0;j<l;j++)
			{
				DP[j][i] = DP[2*j][i-1] ^ DP[2*j+1][i-1];
			}
		}	
	}

	while(m--)
	{
		sd(i);	sd(j);	i--;	

		DP[i][0] = j;	l = 1;

		while(l<=k)
		{
			if(l%2 == 1) // OR
			{
				DP[i/2][l] = DP[2*(i/2)][l-1] | DP[2*(i/2)+1][l-1];
			}
			else
			{
				DP[i/2][l] = DP[2*(i/2)][l-1] ^ DP[2*(i/2)+1][l-1];
			}
			i/=2;
			l++;
		}

		printf("%d\n", DP[0][k] );		
	}



	return 0;
}
