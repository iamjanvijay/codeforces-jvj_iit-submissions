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

int V[1007];
int remEnerCur[1007];
bool isrem[1007]={false};
vector<int> G[1007];
vector< pair<int,int> > Ord;


int main()
{
	int n,m,i,j,k,l,ans=0;

	sd(n);	sd(m);

	for(i=1;i<=n;i++)
		sd(V[i]);

	for(i=0;i<m;i++)
	{
		sd(j);	sd(k);

		G[j].push_back(k);
		G[k].push_back(j);
	}

	for(i=1;i<=n;i++)
	{
		Ord.push_back( make_pair( V[i],i ) );
		k = 0;
		for(j=0;j < G[i].size();j++)
		{
			k += V[ G[i][j] ];
		}
		remEnerCur[i] = k;
	}

	sort(Ord.begin(),Ord.end());

	for(i=n-1;i>=0;i--)
	{
		// printf("%d(%d)",Ord[i].first,Ord[i].second );
		// printf(":%d   ", remEnerCur[ Ord[i].second ]);
		ans += remEnerCur[ Ord[i].second ] ;
		isrem[ Ord[i].second ] = true ;
		for(j=0 ; j < G[ Ord[i].second ].size() ; j++ )
		{
			if( !isrem[ G[ Ord[i].second ][j] ] )
				remEnerCur[ G[ Ord[i].second ][j] ] -= Ord[ i ].first;
		}
	}	

	printf("%d\n", ans );	

	return 0;
}
