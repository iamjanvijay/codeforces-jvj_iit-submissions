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

int C[100007];
vector<int> G[100007];
vector<int> Grev[100007];
vector<int> Comp[100007];
int NoComp;
bool visited[100007];
stack<int> S;

void DFS1(int src)
{
	if(visited[src])
		return;
	
	visited[src] = true;

	int i;
	for(i=0;i<G[src].size();i++)
	{
		DFS1( G[src][i] );
	}
	S.push(src);	
}

void DFS2(int src)
{
	if(visited[src])
		return;
	Comp[NoComp].push_back(src);
	visited[src] = true;

	int i;
	for(i=0;i<Grev[src].size();i++)
	{
		DFS2( Grev[src][i] );
	}
}

int main()
{
	int i,j,k,l,m,n;
	ll ans1=0,ans2=1;
	sd(n);

	for(i=0;i<n;i++)
		sd(C[i]);

	sd(m);

	for(i=0;i<m;i++)
	{
		sd(j);	sd(k);
		j--;	k--;
		G[j].push_back(k);
		Grev[k].push_back(j);
	}

	for(i=0;i<n;i++)
		if(!visited[i])
			DFS1(i);

	for(i=0;i<n;i++)
		visited[i] = false;	

	while(!S.empty())
	{
		i = S.top();	S.pop();
		// printf("*** %d\n", i );
		if(!visited[i])
		{
			DFS2(i);
			NoComp++;
		}	

	}

	for(i=0;i<NoComp;i++)
	{
		// for(j=0;j<Comp[i].size();j++)
		// {
		// 	printf("%d ", Comp[i][j] );
		// }	
		// printf("\n");
		k = C[ Comp[i][0] ];
		l=0;
		for(j=0;j<Comp[i].size();j++)
		{
			if(k==C[ Comp[i][j] ])
			{
				l++;
			}
			else if(C[ Comp[i][j] ]<k)
			{
				l=1;
				k = C[ Comp[i][j] ];
			}	
		}
		ans1+=k;
		ans2=(ans2*l)%1000000007;	
	}	

	printf("%lld %lld\n", ans1, ans2  );

	return 0;
}
