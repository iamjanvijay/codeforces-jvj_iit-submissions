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

char S[1007][1007];
int Black[1007];
int DP[1007][2];

int n,m,x,y;

int Cost(int length,int col)
{
	if(length == 0)
	{
		// printf("%d %d : return %d\n", length, col, 0 );
		return 0;	
	}
	if(length < x)
	{
		// printf("*%d %d : return %d\n", length, col, INT_MAX );
		return INT_MAX;
	}


	int ans = INT_MAX ,k=0,l,z;

	if(DP[length][col]==0)
	{	
		for(l=1;l<=x;l++)
		{
			if(col==0)
			{
				k += Black[length-l]; 
			}
			else
			{
				k += (n - Black[length-l]);
			}	
		}
		// printf("K = %d\n", k);
		z = Cost(length-x,1-col);

		if( z != INT_MAX )
			ans = min( ans, k + z );

		for(l;l<=y;l++)
		{
			if(length-l>=0)
			{
				if(col==0)
				{
					k += Black[length-l]; 
				}
				else
				{
					k += (n - Black[length-l]);
				}
				z = Cost(length-l,1-col);

				if(z != INT_MAX)
					ans = min( ans, k + z );
			}
		}

		DP[length][col] = ans;
	}

	// printf("%d %d : return %d\n", length, col, DP[length][col] );

	return DP[length][col];

}

int main()
{
	int i,j,k,l;

	sd(n);	sd(m);	sd(x);	sd(y);

	for(i=0;i<n;i++)
		ss(S[i]);

	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			if(S[i][j] == &#39;#&#39;)
				Black[j]++;
		}	
	}

	printf("%d\n", min( Cost(m,0) , Cost(m,1) ) );

	return 0;
}
