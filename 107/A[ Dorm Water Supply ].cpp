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

int G[1007];
int D[1007];
int indeg[1007];
int outdeg[1007];
bool isVis[1007];
vector< pair<pair<int,int>,int> > Ans;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,d,p,q,r,u,v;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(p);

	for(i=1;i<=n;i++)
	{
		G[i] = i;	D[i] = INT_MAX;
	}

	for(i=1;i<=p;i++)
	{
		sd(u);	sd(v);	sd(d);
		G[u]=v;	D[u]=d;
		outdeg[u]++;
		indeg[v]++;
	}

	for(i=1;i<=n;i++)
	{
		if(outdeg[i]==1 && indeg[i]==0)
		{
			k = i;
			d = D[k];
			while(outdeg[k]!=0)
			{
				k = G[k];
				if(outdeg[k]!=0)
					d = min(d,D[k]);
			}
			Ans.pb( mp(mp(i,k),d) );
		}
	}

	printf("%d\n", sz(Ans) );
	for(i=0;i<sz(Ans);i++)
		printf("%d %d %d\n", Ans[i].F.F, Ans[i].F.S, Ans[i].S );
	
	return 0;
}