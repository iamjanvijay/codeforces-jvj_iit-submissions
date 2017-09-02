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

void dfs(int cur, int par, double prob, double &ans, int len)
{
	if( sz(G[cur]) == 1 && cur!=1 )
	{
		ans += prob*len;
		return;
	}
	int i;
	for(i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i]!=par)
		{
			dfs(G[cur][i], cur, (cur==1)?(prob/(sz(G[cur]))):(prob/(sz(G[cur])-1)), ans, len+1);
		}
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	double ans=0;
	sd(n);
	for(i=0;i<n-1;i++)
	{
		sd(x);	sd(y);
		G[x].pb(y);	G[y].pb(x);
	}

	dfs(1,1,1,ans,0);

	printf("%0.10lf\n", ans );
	
	return 0;
}