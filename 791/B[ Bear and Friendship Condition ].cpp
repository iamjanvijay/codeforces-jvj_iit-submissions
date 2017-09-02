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

map< pair<int,int> , bool > M;
vector<int> G[150007];
vector<int> V;
bool chkd[150007];

void DFS(int src)
{
	if(chkd[src])
		return;
	V.push_back(src);
	chkd[src] = true;
	int i;
	for(i=0;i<G[src].size();i++)
		DFS(G[src][i]);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int n,m,i,j,k,l;

	sd(n);	sd(m);

	for(i=1;i<=m;i++)
	{
		sd(j);	sd(k);
		G[j].push_back(k);
		G[k].push_back(j);
		M[ make_pair(j,k) ] = true;
		M[ make_pair(k,j) ] = true;
	}

	for(i=1;i<=n;i++)
	{
		if(!chkd[i])
			DFS(i);
		for(j=0;j<V.size();j++)
		{
			for(k=j+1;k<V.size();k++)
			{
				if(!M[ make_pair(V[j],V[k]) ])
				{
					printf("NO\n");
					return 0;
				}
			}
		}
		V.clear();
	}

	printf("YES\n");
	
	return 0;
}