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

int D[300007];
int Deg[300007];
bool isEdge[300007];
bool isVis[300007];
vector<int> ans;
vector< pair<int, int> > G[300007];

void dfs(int src, int par)
{
	isVis[src] = true;

	for(int i=0;i<sz(G[src]);i++)
	{
		if( G[src][i].F == par )
			continue;
		if( !isVis[ G[src][i].F ] )
		{
			dfs( G[src][i].F , src);
		}
		else
		{
			isEdge[ G[src][i].S ] = false;
			Deg[ src ]--;
		}
	}

}

void dfs2(int src, int par)
{
	int i,d,k;
	// printf("-> %d \n", src );
	for(i=0;i<sz(G[src]);i++)
	{
		if( !isEdge[ G[src][i].S ] )
			continue;
		if( G[src][i].F != par )
		{
			dfs2(G[src][i].F, src);
		}
	}

	if(src!=par)
	{
		k = 0;

		for(i=0,d=0;i<sz(G[src]);i++)
		{
			if( !isEdge[ G[src][i].S ] )
				continue;
			if( G[src][i].F == par )
				k = G[src][i].S;
			else
			{
				d++;	// Deg[G[src][i].F]
			}
		}


		if(d%2 == D[src])
		{
			isEdge[k] = false;
			Deg[src]--;	Deg[par]--;
		}	
	}	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r,e;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(c=0,k=0,i=1;i<=n;i++)
	{
		sd(D[i]);
		if(D[i]==1)
			c++;
		if(D[i]==-1)
			k = i;
	}

	for(i=1;i<=m;i++)
	{
		sd(x);	sd(y);
		Deg[x]++;	Deg[y]++;
		G[x].pb( mp(y,i) );
		G[y].pb( mp(x,i) );
		isEdge[i] = true;
	}

	if(c%2!=0 && k==0)
	{
		printf("-1\n");
		return 0;
	}

	if(c%2!=0)
	{
		D[k] = 1;
	}

	for(i=1;i<=n;i++)
		if(D[i]==-1)
			D[i] = 0;	

	// printf("----\n");
	// for(i=1;i<=n;i++)
	// 	printf("%d ", D[i] );
	// printf("\n");

	dfs( 1 , 1);

	// printf("----\n");
	// for(i=1;i<=m;i++)
	// 	if(isEdge[i])
	// 		printf("E ");
	// 	else
	// 		printf("NE ");
	// printf("\n");

	// printf("----\n");
	// for(i=1;i<=n;i++)
	// 	printf("%d ", Deg[i] );
	// printf("\n");	
	// printf("Hello\n");
	dfs2( 1 , 1 );

	// printf("HELLO\n");

	for(i=1;i<=m;i++)
		if(isEdge[i])
			ans.pb(i);

	printf("%d\n", sz(ans) );
	
	for(i=0;i<sz(ans);i++)
		printf("%d ", ans[i] );
	if(sz(ans))
	printf("\n");		

	return 0;
}