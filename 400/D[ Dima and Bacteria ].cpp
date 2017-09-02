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

vector< pair<int,int> > G[100007]; // (node no,wt)
int compNo[100007];
bool isVis[100007];
int C[507];
int Ans[507][507];


void DFS(int src)
{
	if(isVis[src])
		return;
	// printf("*** %d  ", src );
	isVis[src] = true;
	int i;
	for(i=0;i<G[src].size();i++)
	{
			DFS(G[src][i].first);
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,c,n,u,v,w;

	sd(n);	sd(m); 	sd(k);

	for(j=1,i=1;i<=k;i++)
	{
		sd(c);
		C[i] = c;
		while(c--)
		{
			compNo[j++] = i;
		}
		C[i] += C[i-1];
	}

	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(i==j)
				Ans[i][j] = 0;
			else
				Ans[i][j] = INT_MAX;
		}
	}	

	for(i=1;i<=m;i++)
	{
		sd(u);	sd(v);	sd(w);
		if(compNo[u]!=compNo[v])
		{
			Ans[ compNo[u] ][ compNo[v] ] = min(Ans[ compNo[u] ][ compNo[v] ],w);
			Ans[ compNo[v] ][ compNo[u] ] = min(Ans[ compNo[v] ][ compNo[u] ],w);
		}
		if(w==0)
		{
			G[u].push_back( make_pair(v,w) );
			G[v].push_back( make_pair(u,w) );
		}
	}

	for(i=1;i<=k;i++)
	{	
		memset(isVis,false,100007);
		DFS(C[i]);
		for(j=C[i-1]+1;j<=C[i];j++)
			if(!isVis[j])
			{
				printf("No\n");
				return 0;
			}
	}

	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
		{
			for(l=1;l<=k;l++)
			{
				if(Ans[l][i]!=INT_MAX && Ans[i][j]!=INT_MAX && Ans[l][i]+Ans[i][j] < Ans[l][j])
				{
					Ans[j][l] = Ans[l][j] = Ans[l][i]+Ans[i][j];
				}
			}
		}
	}
	printf("Yes\n");
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(Ans[i][j]==INT_MAX)
				printf("-1 ");
			else
				printf("%d ",Ans[i][j] );
		}
		printf("\n");
	}
	
	return 0;
}