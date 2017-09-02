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
#define pb push_back
#define mp make_pair

int Mod = 1000000007;
int A[2007];
vector<int> G[2007];
bool M[2007];
vector< pair<int,int> > V; 

int dfs(int src,int mini,int maxi,int par)
{

	int i;
	ll ans = 1;
	for(i=0;i<G[src].size();i++)
	{
		if( (G[src][i] == par) || (mini > A[G[src][i]]) || (A[G[src][i]] > maxi) || M[G[src][i]] )
			continue;
		ans = (ans * dfs(G[src][i],mini,maxi,src))%Mod;
	}	
	return (ans+1)%Mod;
}


int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,d;
	ll ans = 0;

	sd(d);	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(A[i]);
		V.pb( mp(A[i],i) );
	}

	for(i=1;i<=n-1;i++)
	{
		sd(k);	sd(l);
		G[k].pb(l);
		G[l].pb(k);
	}

	sort(V.begin(), V.end());

	for(j=0;j<n;j++)
	{
		i = V[j].second;
		ans = ( Mod + ans + dfs(i,A[i],A[i]+d,0) - 1 )%Mod;
		M[i] = true;
		// printf("%d : %lld\n",i,ans );
	}

	printf("%lld\n", ans );	
	
	return 0;
}