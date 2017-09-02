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

map<int,int> M;
map<int,int> revM;
vector<int> G[100007];
bool Vis[100007];

void DFS(int src)
{
	if(Vis[src])
		return;
	Vis[src] = true;
	printf("%d ",revM[src]);

	int i;
	for(i=0;i<sz(G[src]);i++)
		DFS(G[src][i]);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,x,y,xc,yc,z,a,b,r,n,cur;
	// ll i,j,k,l,m,n,x,y,z,a,b,r,cur;

	sd(n);

	cur = 1;
	for(i=0;i<n;i++)
	{
		sd(x);	sd(y);

		if(M[x]==0)
		{
			M[x] = cur;	revM[cur] = x;	cur++;
		}

		if(M[y]==0)
		{
			M[y] = cur;	revM[cur] = y;	cur++;
		}

		G[M[x]].pb(M[y]);	G[M[y]].pb(M[x]);
	}

	for(i=1;i<cur;i++)
	{
		if(sz(G[i])==1)
		{
			DFS(i);
			printf("\n");
			break;
		}
	}

	return 0;
}