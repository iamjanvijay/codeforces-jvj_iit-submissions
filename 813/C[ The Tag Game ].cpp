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

int ans = 0;
int A[200007];
vector<int> T[200007];

void DFS1(int cur,int par,int lvl)
{
	A[cur] = lvl;
	int i;
	for(i=0;i<sz(T[cur]);i++)
	{
		if(T[cur][i]!=par)
			DFS1(T[cur][i],cur,lvl+1);
	}
}

void DFS2(int cur,int par,int lvl)
{
	if(lvl<A[cur])
		ans = max(ans,A[cur]);
	int i;
	for(i=0;i<sz(T[cur]);i++)
	{
		if(T[cur][i]!=par)
			DFS2(T[cur][i],cur,lvl+1);
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(x);

	for(i=1;i<=n-1;i++)
	{
		sd(a);	sd(b);
		T[a].pb(b);
		T[b].pb(a);
	}

	DFS1(1,1,0);

	DFS2(x,x,0);

	printf("%d\n", 2*ans );
	
	return 0;
}