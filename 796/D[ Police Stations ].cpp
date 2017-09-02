#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

bool isPol[300007];
vi G[300007];
vector< pii > E; 
vi ans;
int CP[300007];
int dst[300007];
queue< int > Q;
int d;

void mBFS(int n)
{

	int temp,i;
	while(!Q.empty())
	{
		temp = Q.front();	Q.pop();

		for(i=0;i<sz(G[temp]);i++)
		{
			if(  dst[ G[temp][i] ] == INT_MAX )
			{
				CP[ G[temp][i] ] = CP[ temp ];
				dst[ G[temp][i] ] = dst[ temp ]+1;
				if( dst[ G[temp][i] ] < d )
				{
					Q.push( G[temp][i] );
				}
			}
		}

	}

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);	sd(d);

	for(i=1;i<=n;i++)
		dst[i] = INT_MAX;

	for(i=0;i<k;i++)
	{
		sd(m);	isPol[m] = true;	
		Q.push( m );
		dst[ m ] = 0;	
		CP[ m ] = m;	
	}

	for(i=1;i<=n-1;i++)
	{
		sd(a);	sd(b);
		E.pb(mp(a,b));
		G[a].pb(b);	G[b].pb(a);
	}

	mBFS(n);

	// printf("**");
	// for(i=1;i<=n;i++)
	// 	printf("%d ",CP[i] );
	// printf("\n");

	for(i=0;i<sz(E);i++)
	{
		if( CP[ E[i].F ] != CP[ E[i].S ] )
		{
			ans.pb(i+1);
		}
	}

	printf("%d\n", sz(ans) );
	for(i=0;i<sz(ans);i++)
		printf("%d ", ans[i] );
	printf("\n");
	
	return 0;
}