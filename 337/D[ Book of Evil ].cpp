#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

vector<int> G[100007];
bool isInfec[100007];
int dpDown[100007];
int dpUp[100007];

void dfsDown(int cur, int par)
{
	int i;

	if(isInfec[cur])
		dpDown[cur] = 0;
	else
		dpDown[cur] = INT_MIN;

	for(i=0;i<sz(G[cur]);i++)
	{
		if( par!=G[cur][i] )
		{
			dfsDown(G[cur][i], cur);
			if( dpDown[G[cur][i]] != INT_MIN )
			{
				dpDown[cur] = max( dpDown[cur] , 1 + dpDown[G[cur][i]] );
			}
		}
	}
}

void dfsUp(int cur, int par, int now)
{
	int i, max1, max2, ind1, ind2, newnow;

	dpUp[cur] = now;

	ind1 = ind2 = 0;
	max2 = max1 = 0;
	for(i=0;i<sz(G[cur]);i++)
	{
		if( par!=G[cur][i] )
		{
			if( dpDown[ G[cur][i] ] >= max1 )
			{
				max2 = max1;
				ind2 = ind1;
				max1 = dpDown[ G[cur][i] ];
				ind1 = G[cur][i];
			}
			else
			{
				if(dpDown[ G[cur][i] ] >= max2 )
				{
					max2 = dpDown[ G[cur][i] ];
					ind2 = G[cur][i];
				}
			}
		}
	}

	for(i=0;i<sz(G[cur]);i++)
	{
		if( par!=G[cur][i] )
		{
			newnow = INT_MIN;

			if(isInfec[cur])
				newnow = max(newnow, 1);

			if(now!=INT_MIN)
			{
				newnow = max(newnow, now+((now!=INT_MIN)?1:0) );
			}

			if( ind1!=0 && G[cur][i] != ind1 )
			{
				newnow = max(newnow, max1+((max1!=INT_MIN)?2:0) );
			}

			if( ind2!=0 && G[cur][i] != ind2 )
			{
				newnow = max(newnow, max2+((max1!=INT_MIN)?2:0) );
			}

			dfsUp(G[cur][i], cur, newnow);
		}
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,d,r;
	// bool flag;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	sd(n);	sd(m);	sd(d);

	for(i=0;i<m;i++)
	{
		sd(x);
		isInfec[x] = true;
	}

	for(i=0;i<n-1;i++)
	{
		sd(x);	sd(y);
		G[x].pb(y);	G[y].pb(x);
	}

	dfsDown(1, 1);
	dfsUp(1, 1, INT_MIN);

	// printf("-----------\n");
	// for(i=1;i<=n;i++)
	// {
	// 	printf("%d ", dpUp[i] );
	// }
	// printf("\n");

	// for(i=1;i<=n;i++)
	// {
	// 	printf("%d ", dpDown[i] );
	// }
	// printf("\n");	

	for(c=0,i=1;i<=n;i++)
	{
		if(  max(dpUp[i], dpDown[i]) != INT_MIN && max(dpUp[i], dpDown[i]) <= d )
			c++;		
	}

	printf("%d\n", c );

	return 0;
}