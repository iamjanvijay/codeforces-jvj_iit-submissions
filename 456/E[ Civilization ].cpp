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

vector<int> G[300007];
int P[300007];
int H[300007];
int D[300007];
bool vis[300007];

void dfs(int src, int par, int d, int &ansDis, int &ans)
{
	vis[src] = true;
	if(d > ansDis)
	{
		ans = src;
		ansDis = d;
	}

	for(int i=0;i<sz(G[src]);i++)
	{
		if(G[src][i]!=par)
		{
			dfs(G[src][i], src, d+1, ansDis, ans);
		}
	}
}

int CompDiameter(int x)
{
	int src = x, disSrc = 0;
	dfs(x, x, 0, disSrc, src);
	dfs(src, src, 0, disSrc, src);
	return disSrc;
}

int Find(int x)
{
	if(x==P[x])
		return x;
	P[x] = Find(P[x]);
	return P[x];
}

int Diameter(int x)
{
	int Px = Find(x);
	return D[Px];
}

void Union(int x, int y)
{
	int Px = Find(x);
	int Py = Find(y);
	if(Px==Py)
		return;
	if(H[Px]==H[Py])
	{
		P[Px] = Py;
		D[Py] = max(D[Py], ((D[Px]%2==0)?(D[Px]/2):(D[Px]/2+1))+((D[Py]%2==0)?(D[Py]/2):(D[Py]/2+1))+1);
		D[Py] = max(D[Py], D[Px]);
		H[Py]++;
	}
	else if(H[Px]>H[Py])
	{
		P[Py] = Px;
		D[Px] = max(D[Px], ((D[Px]%2==0)?(D[Px]/2):(D[Px]/2+1))+((D[Py]%2==0)?(D[Py]/2):(D[Py]/2+1))+1);
		D[Px] = max(D[Py], D[Px]);		
	}
	else
	{
		P[Px] = Py;
		D[Py] = max(D[Py], ((D[Px]%2==0)?(D[Px]/2):(D[Px]/2+1))+((D[Py]%2==0)?(D[Py]/2):(D[Py]/2+1))+1);
		D[Py] = max(D[Py], D[Px]);		
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,q;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);	sd(q);

	for(i=1;i<=n;i++)
	{
		P[i] = i;
		D[i] = -1;
	}	

	for(i=0;i<m;i++)
	{
		sd(x);	sd(y);
		Union(x, y);
		G[x].pb(y);
		G[y].pb(x);
	}

	for(i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		D[Find(i)] = CompDiameter(i);
	}

	for(i=0;i<q;i++)
	{
		sd(x);
		if(x==2)
		{
			sd(a);	sd(b);
			Union(a, b);
		}
		else
		{
			sd(a);
			printf("%d\n", D[Find(a)] );
		}
	}

	return 0;
}