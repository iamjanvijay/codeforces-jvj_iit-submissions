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

int A[200007];
vector<int> G[200007];
vector<int> Check;
int ans[200007];
set<int>::iterator it;


void dfs(int cur, int par, int x, set<int> S)
{
	set<int> temp;
	for(it=S.begin();it!=S.end();++it)
	{
		temp.insert( __gcd(*it, A[cur]) );
	}
	temp.insert(x);
	it = temp.end();	it--;
	ans[cur] = *it;

	int k = __gcd(x,A[cur]);
	for(int i=0;i<sz(G[cur]);i++)
	{
		if(G[cur][i]!=par)
		{
			dfs(G[cur][i], cur, k, temp);
		}
	}

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	sd(n);

	for(i=1;i<=n;i++)
		sd(A[i]);

	for(i=0;i<n-1;i++)
	{
		sd(x);	sd(y);
		G[x].pb(y);		G[y].pb(x);
	}

	set<int> temp;
	dfs(1, 1, 0, temp);

	for(i=1;i<=n;i++)
		printf("%d ", (i==1)?A[i]:ans[i] );

	return 0;
}