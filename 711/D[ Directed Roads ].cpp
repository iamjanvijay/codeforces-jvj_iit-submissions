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

ll Mod=1000000007;
vector<int> G[200007];
bool visited[200007];
int sta[200007];
ll Pow2[200007];
vector<int> edgeLen;

void cycleDetect(int cur, int curlen, int &l)
{
	if(sta[cur]!=0)	// cycle detected
	{
		l = curlen - sta[cur];
		return;
	}

	if(visited[cur])
		return;
	visited[cur] = true;	sta[cur] = curlen;

	for(int i=0;i<sz(G[cur]);i++)
	{
		cycleDetect(G[cur][i], curlen+1, l);
	}
	sta[cur] = 0;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	Pow2[0] = 1;
	for(i=1;i<200007;i++)
	{
		Pow2[i] = (2*Pow2[i-1])%Mod;
	}

	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(a);
		G[i].push_back(a);
	}

	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			l = 0;
			cycleDetect(i, 1, l);
			edgeLen.push_back(l);
		}
	}

	ll ans = 1;
	a = 0;

	for(i=0;i<sz(edgeLen);i++)
	{
		a += edgeLen[i];
		// printf("* %d ", edgeLen[i] );
		if(Pow2[edgeLen[i]]-2>0)
			ans = (ans * (Pow2[edgeLen[i]]-2))%Mod;
	}
	// printf("\n");

	ans = (ans * (Pow2[n-a]))%Mod;
	
	printf("%lld\n", ans );

	return 0;
}