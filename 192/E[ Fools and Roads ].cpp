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

vector< pair<int, int> > G[100007];
int Parent[100007][20];
int DP[100007]; 
int Level[100007];  
int EdgeDP[100007];         
bool isProcessed = false;

void dfs(int cur, int par, int lvl)
{
	Level[cur] = lvl;
	Parent[cur][0] = par;
	for(int i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i].F!=par)
		{
			dfs(G[cur][i].F, cur, lvl+1);
		}
	}
}

void buildParent(int n)
{
	for(int i=0;i+1<20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			Parent[j][i+1] = Parent[Parent[j][i]][i];
		}
	}
}

int LCA(int x, int y, int n)
{
	if(!isProcessed)
	{
		dfs(1, 1, 0);			// 1 is the root
		buildParent(n);
		isProcessed = true;
	}

	int i,j,k;
	k = Level[x] - Level[y];

	if(k>0)
	{
		for(i=0;i<31;i++)
		{
			if( ((1<<i) & k) != 0 )
			{
				x = Parent[x][i];
			}
		}
	}

	if(k<0)
	{
		k = -k;
		for(i=0;i<31;i++)
		{
			if( ((1<<i) & k) != 0 )
			{
				y = Parent[y][i];
			}
		}		
	}

	while(x!=y)
	{
		i = 0;
		while( Parent[x][i] != Parent[y][i] )
			i++;
		if(i==0)
		{
			x = Parent[x][i];	y = Parent[y][i];
		}
		else
		{
			x = Parent[x][i-1];	y = Parent[y][i-1];
		}
	}

	return x;
}

int dfs2(int cur, int par)
{
	int ret = 0;

	for(int i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i].F!=par)
		{
			ret += dfs2(G[cur][i].F, cur);
		}
	}

	ret += DP[cur];

	for(int i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i].F==par && cur!=par)
		{
			EdgeDP[G[cur][i].S] += ret;
		}
	}	

	return ret;	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	
	for(i=1;i<=n-1;i++)
	{
		sd(x);			sd(y);
		G[x].pb(mp(y,i));		G[y].pb(mp(x,i));
	}



	sd(k);
	for(i=0;i<k;i++)
	{
		sd(x);			sd(y);

		if(x==y)
			continue;

		a = LCA(x,y,n);

		DP[a] += -2;
		DP[x] += 1;
		DP[y] += 1;
	}

	dfs2(1, 1);

	for(i=1;i<=n-1;i++)
		printf("%d ",EdgeDP[i] );
	printf("\n");
	
	return 0;
}