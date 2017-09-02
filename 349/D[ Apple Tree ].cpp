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

ll DP[100007];
ll Apples[100007];
vector<ll> G[100007];

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

ll LCM(ll a,ll b)
{
	if(a>=10000000000007LL || b>=10000000000007LL)
		return 10000000000007LL;
	ll g = gcd(max(a,b),min(a,b));
	double x = (double) a * b / g;

	if(x > 10000000000007LL)
		return 10000000000007LL;
	return a * b / g;
}

void dfs(ll cur, ll par)
{
	ll childs, l;
	DP[cur] = 1;

	for(int i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i]!=par)
			dfs(G[cur][i], cur);
	}

	childs = sz(G[cur]);
	if( cur != par )
		childs--;

	if(childs==0)
		return;

	l = 1;
	for(int i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i]!=par)
		{
			l = LCM(l, DP[G[cur][i]]);
		}
	}

	if(l>=10000000000007LL)
		DP[cur] = 10000000000007LL;
	else
		DP[cur] = childs * l;
}

bool chk(ll cur, ll par, ll val)
{

	bool flag = true;
	ll childs;

	childs = sz(G[cur]);
	if( cur != par )
		childs--;

	if(childs==0)
	{
		// printf("%lld : %lld >= %lld\n", cur, Apples[cur], val);
		if(Apples[cur] >= val)
			return true;
		return false;
	}

	// printf("Checking %lld %lld %lld\n", cur, par, val);

	for(int i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i]!=par)
		{
			flag = flag && chk(G[cur][i], cur, val/childs);
		}
	}

	return flag;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r, fs, ls, md;

	slld(n);

	a = 0;
	for(i=1;i<=n;i++)
	{
		slld(Apples[i]);
		a += Apples[i];
	}

	for(i=0;i<n-1;i++)
	{
		slld(x);		slld(y);
		G[x].pb(y);		G[y].pb(x);
	}

	dfs(1, 1);
	// chk( 1 , 1, DP[1] * 5 );
	// printf("-> %lld\n", DP[1] );

	fs = 0; ls = 10000000000000LL / DP[1];
	// printf("-> %lld\n", ls );
	while( fs+1 < ls )
	{
		md = (fs + ls)/2;
		if( chk( 1 , 1, DP[1] * md ) )
			fs = md;
		else
			ls = md;
	}

	// printf("--> %lld %lld\n", fs, ls );

	if( chk( 1 , 1, DP[1] * ls ) )
	{
		printf("%lld\n", a - DP[1] * ls );
	}
	else
	{
		printf("%lld\n", a - DP[1] * fs );
	}
	
	return 0;
}