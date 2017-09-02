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

vector<int> g[4007];
bool mat[4007][4007] = {false};
int deg[4007] = {0};

int main()
{
	int i,j,k,n,m,ssize,mini = INT_MAX;

	sd(n); sd(m);

	while(m--)
	{
		sd(i);	sd(j);
		i--;	j--;

		g[i].push_back(j);
		g[j].push_back(i);

		mat[i][j] = mat[j][i] = true;
		deg[i]++;
		deg[j]++;
	}

	for(i=0;i<n;i++)
	{
		ssize =  g[i].size();
		for( j=0 ; j < ssize ; j++ )
		{
			for( k=j+1 ; k<ssize ; k++)
			{
				if(mat[ g[i][j] ][ g[i][k] ])
				{
					if(mini > deg[ g[i][j] ] + deg[  g[i][k]  ]  + deg[ i ] - 6 )
						mini = deg[ g[i][j] ] + deg[ g[i][k] ]  + deg[ i ] - 6;
				}
			}
		}
	}

	if(mini == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n",mini);

	return 0;
}
