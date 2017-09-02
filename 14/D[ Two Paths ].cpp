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

vector<int> G[207];
bool vis1[207];
bool vis2[207];

int dfs4(int cur, int par, int &src2len, int curlen)
{
	vis2[cur] = true;
	if(src2len<curlen)
	{
		src2len = curlen;
	}
	int i;
	for(i=0;i<sz(G[cur]);i++)
	{
		if(vis1[G[cur][i]]==false && G[cur][i]!=par)
		{
			dfs4(G[cur][i], cur, src2len, curlen+1);
		}
	}
}

void dfs3(int cur, int par, int &src2, int &src2len, int curlen)
{
	vis2[cur] = true;
	if(src2len<curlen)
	{
		src2len = curlen;
		src2 = cur;
	}
	int i;
	for(i=0;i<sz(G[cur]);i++)
	{
		if(vis1[G[cur][i]]==false && G[cur][i]!=par)
		{
			dfs3(G[cur][i], cur, src2, src2len, curlen+1);
		}
	}
}

int diameter(int src)
{
	int l=-1,src2len=-1,src2;
	dfs3(src, src, src2, src2len, 0);
	dfs4(src2, src2, l, 0);
	return l;
}

int dfs2(int n)
{
	int i,k=0;
	for(i=1;i<=n;i++)
	{
		if(vis1[i]==false && vis2[i]==false)
			k = max(k, diameter(i));
	}
	for(i=0;i<207;i++)
		vis2[i] = false;	
	return k;
}

void dfs1(int cur, int par, int &maxProd, int len, int &n)
{
	vis1[cur] = true;
	maxProd = max(maxProd, len*dfs2(n));
	int i;
	for(i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i]!=par)
		{
			dfs1(G[cur][i], cur, maxProd, len+1, n);
		}
	}
	vis1[cur] = false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n-1;i++)
	{
		sd(x);			sd(y);
		G[x].pb(y);		G[y].pb(x);
	}

	a = 0;
	for(i=1;i<=n;i++)
	{
		dfs1(i, i, a, 0, n);
	}
	
	printf("%d\n", a);

	return 0;
}