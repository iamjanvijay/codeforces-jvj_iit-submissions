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

vector<int> G[100007];
int C[100007];
set<int> S[100007];

int main()
{
	int i,j,k,l,m,n,u,v,ans,ans2;

	sd(n);	sd(m);

	for(i=1;i<=n;i++)
		sd(C[i]);

	for(i=1;i<=m;i++)
	{
		sd(u);	sd(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(i=1;i<=n;i++)
	{
		S[ C[i] ].insert( C[i] );
		for(j=0;j<G[i].size();j++)
		{
			S[ C[i] ].insert( C[ G[i][j] ] );
		}	
	}	

	ans = S[ C[1] ].size();
	ans2 = C[1];
	for(i=1;i<=n;i++)
		if( S[ C[i] ].size() > ans )
		{
			ans2 =  C[i];
			ans = S[ C[i] ].size();
		}
		else if(  S[ C[i] ].size() == ans && C[i] < ans2  )
		{
			ans2 = C[i];
		}	

	printf("%d\n", ans2 );	


	return 0;
}
