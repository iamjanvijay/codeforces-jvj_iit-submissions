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

vector<int> G[300007];
int A[300007];
multiset<int> S;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n,x;
	int ans=INT_MAX,maxi;

	sd(n);
	for(i=1;i<=n;i++)
	{
		sd(A[i]);
		S.insert(A[i]);
	}


	for(i=0;i<n-1;i++)
	{
		sd(l);	sd(r);
		G[l].push_back(A[r]);
		G[r].push_back(A[l]);
	}

	multiset< int >::iterator itr;
	for(i=1;i<=n;i++)
	{
		maxi = A[i];

		itr = S.find(A[i]);
		if(itr!=S.end())
		{
		    S.erase(itr);
		}

		for(j=0;j<G[i].size();j++)
		{
			maxi=(maxi>G[i][j]+1)?(maxi):(G[i][j]+1);

			itr = S.find(G[i][j]);
			if(itr!=S.end())
			{
			    S.erase(itr);
			}
		}

		if(!S.empty())
		{	
			maxi=(maxi>(*S.rbegin())+2)?(maxi):((*S.rbegin())+2);
		}

		S.insert(A[i]);

		for(j=0;j<G[i].size();j++)
		{
			S.insert(G[i][j]);
		}

		ans = (ans>maxi)?(maxi):(ans);//min(ans,maxi);		
	}

	printf("%d\n",ans );
	
	return 0;
}