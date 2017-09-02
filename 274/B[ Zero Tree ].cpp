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
int V[100007];

pair<ll,ll> DFS(int par,int src)
{
	int i;	
	ll k,first=0,second=0;
	pair<ll,ll> Z; 
	bool flag = false;
	for(i=0;i<G[src].size();i++)
	{
		if(par!=G[src][i])
		{
			flag = true;
			Z = DFS(src,G[src][i]);
			first = max(first,Z.first);
			second = max(second,Z.second);
		}
	}

	if(!flag)
	{
		if(V[src]>0)
		{
			return make_pair(0LL,(ll)V[src]);
		}
		else if(V[src]<0)
		{
			return make_pair((ll)-V[src],0LL);
		}
		else
		{
			return make_pair(0LL,0LL);
		} 
	}
	else
	{
		k = V[src]+first-second;
		if(k>0)
		{
			return make_pair(first,second+k);
		}
		else if(k<0)
		{
			return make_pair(first-k,second);
		}
		else
		{
			return make_pair(first,second);
		} 
	}

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(n);	
	for(i=0;i<n-1;i++)
	{
		sd(k);	sd(l);
		G[k].push_back(l);	G[l].push_back(k);
	}

	for(i=1;i<=n;i++)
		sd(V[i]);

	pair<ll,ll> ANS = DFS(0,1);

	printf("%lld\n", ANS.first + ANS.second );
	
	return 0;
}