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

// bool checked[100007];
bool isR[100007];
vector< int > G[100007];
vector<int> V;
// map<int,int> M[100007];

// void initChk()
// {
// 	for(int i=0;i<100007;i++)
// 		checked[i] = false;
// }

bool dfs1(int src,int par)
{
	int i;
	bool flag = false;
	for(i=0;i<G[src].size();i++)
	{
		if( G[src][i] != par )
			flag |= dfs1(G[src][i],src);
	
	}

	isR[src] |= flag;
	return isR[src];

}

void dfs2(int src,int par)
{
	int i;
	bool flag = true;
	for(i=0;i<G[src].size();i++)
	{
		if( G[src][i] != par && isR[G[src][i]] )
		{
			flag = false;
			dfs2(G[src][i],src);
		}
	}
	if(flag)
		V.push_back(src);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;
	bool flag = true;
	sd(n);

	for(i=0;i<n-1;i++)
	{
		sd(j);	sd(k); sd(l);

		if(l==2)
		{
			// M[j][k] = G[j].size();
			G[j].push_back( k ) ;
			// M[k][j] = G[k].size();
			G[k].push_back( j );
			isR[j] = isR[k] = true;
			flag = false;
		}
		else
		{
			// M[j][k] = G[j].size();
			G[j].push_back( k ) ;
			// M[k][j] = G[k].size();
			G[k].push_back( j );
		}

	}

	dfs1(1,0);	
	// initChk();
	dfs2(1,0);	

	if(flag)
	{
		printf("0\n");
		return 0;
	}

	printf("%d\n", V.size() );
	for(i=0;i<V.size();i++)
		printf("%d ", V[i] );
	printf("\n");

	return 0;
}