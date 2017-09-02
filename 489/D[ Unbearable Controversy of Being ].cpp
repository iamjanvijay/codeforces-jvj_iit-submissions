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

vi Row[3007];
vi Col[3007];
ll Mat[3007][3007];
bool vis[3007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	ll ans = 0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<m;i++)
	{
		sd(x);	sd(y);
		Row[x].pb(y);
		Col[y].pb(x);
	}

	for(i=1;i<=n;i++)
	{
		memset(vis,false,3005);
		for(j=0;j<sz(Row[i]);j++)
		{
			vis[ Row[i][j] ] = true;
		}

		for(j=1;j<=n;j++)
		{
			k = 0;
			for(l=0;l<sz(Col[j]);l++)
			{
				if( vis[ Col[j][l] ] )
					k++;
			}
			Mat[i][j] = k;
		}

	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j && Mat[i][j]>1)
			{
				ans += ( Mat[i][j] * (Mat[i][j]-1) / 2 );
			}
		}
	}

	printf("%lld\n", ans );

	return 0;
}