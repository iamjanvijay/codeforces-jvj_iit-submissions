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

bool exists[507];
ll G[507][507];
int A[507];
ll Ans[507];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;
	ll ans;
	sd(n);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			slld(G[i][j]);
		}
	}

	for(i=n-1;i>=0;i--)
		sd(A[i]);

	for(l=n-1,i=0;i<n;i++,l--)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if( G[j][A[i]]+G[A[i]][k] <= G[j][k] )
					G[j][k] = G[j][A[i]]+G[A[i]][k];
			}
		}

		exists[ A[i] ] = true;
		ans = 0;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if( exists[j] && exists[k] )
					ans += G[j][k];
			}
		}

		Ans[l] = ans;		

	}

	for(i=0;i<n;i++)
		printf("%lld ", Ans[i] );
	printf("\n");
	
	return 0;
}