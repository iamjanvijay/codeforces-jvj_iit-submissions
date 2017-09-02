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

vector<int> V[200007];
int Color[200007];

void dfs(int cur,int PCol)
{
	int i,j=1;

	for(i=0;i<V[cur].size();i++)
	{
		if(Color[V[cur][i]]==0)
		{
			while(j==PCol || j==Color[cur])
				j++;
			Color[V[cur][i]] = j++;
			dfs(V[cur][i],Color[cur]);
		}	
	}	

}

int main()
{
	int i,j,k,l,m,n;

	sd(n);

	for(i=0;i<n-1;i++)
	{
		sd(j);	sd(k);
		V[j].push_back(k);
		V[k].push_back(j);
	}

	k = V[1].size();
	l = 1;
	for(i=1;i<=n;i++)
	{
		if(k < V[i].size())
		{
			k = V[i].size();
			l = i;
		}	
	}

	k++;
	Color[l] = 1;

	dfs(l,0);

	printf("%d\n", k);

	for(i=1;i<=n;i++)
		printf("%d ", Color[i] );
	printf("\n");

	return 0;
}
