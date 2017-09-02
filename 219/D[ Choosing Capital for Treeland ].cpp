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

vector< pair<int,bool> > G[200007];
bool visited[200007];
pair<int,int> vertInfo[200007];

int totflsedge=0;

void DFS(int src,int flsedge,int totedge)
{

	visited[src]=true;
	vertInfo[src].first=flsedge;
	vertInfo[src].second=totedge; 
	int i;
	for(i=0; i < G[src].size() ;i++)
	{
		if(!visited[ G[src][i].first ])
			if(G[src][i].second)
				DFS(G[src][i].first,flsedge,totedge+1);
			else
			{
				DFS(G[src][i].first,flsedge+1,totedge+1);
				totflsedge++;
			}
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);
	int i,j,k,l,m,n,mini=INT_MAX;

	sd(n);
	for(i=0;i<n-1;i++)
	{
		sd(j);	sd(k);
		G[j].push_back( make_pair(k,true) );
		G[k].push_back( make_pair(j,false) );
	}	
			
	DFS(1,0,0);

	for(i=1;i<=n;i++)
	{
		mini = min(mini,totflsedge - vertInfo[i].first + (vertInfo[i].second - vertInfo[i].first) );
	}
	printf("%d\n", mini );
	for(i=1;i<=n;i++)
	{
		if(mini==(totflsedge - vertInfo[i].first + (vertInfo[i].second - vertInfo[i].first)))
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}