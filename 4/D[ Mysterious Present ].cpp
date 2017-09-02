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

vector< pair< pair<int,int> , int > > V;
int DP[5007];
int DP2[5007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,w,h,ans;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(w);	sd(h);

	for(i=0;i<n;i++)
	{
		sd(x);	sd(y);
		V.pb( mp( mp(x,y) , i ) );
	}

	sort(V.begin(), V.end());

	for(i=sz(V)-1;i>=0;i--)
	{
		DP[i] = 1;	DP2[i] = -1;
		for(j=i+1;j<sz(V);j++)
		{
			if( V[j].F.F > V[i].F.F && V[j].F.S > V[i].F.S )
			{
				// DP[i] = max(DP[i],DP[j]+1);
				if( DP[j]+1 > DP[i] )
				{
					DP[i] = DP[j]+1;
					DP2[i] = j;
				}
			}
		}
	}

	ans = 0;	k = -1;

	for(i=0;i<sz(V);i++)
	{
		if( w < V[i].F.F && h < V[i].F.S )
		{
			if(ans<DP[i])
			{
				ans = DP[i];
				k = i;
			}
		}
	}

	printf("%d\n", ans );

	while(k!=-1)
	{
		printf("%d ", V[k].S + 1 );
		k = DP2[k];
	}
	
	return 0;
}