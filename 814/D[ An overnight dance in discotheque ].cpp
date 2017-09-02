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

vector< pair< ll , pair<ll,ll> > > P;
int level[1007];
double ans = 0;

bool contains( pair< ll , pair<ll,ll> > A, pair< ll , pair<ll,ll> > B)
{
	return (A.S.F - B.S.F)*(A.S.F - B.S.F) + (A.S.S - B.S.S)*(A.S.S - B.S.S) < (A.F)*(A.F);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	slld(n);

	for(i=0;i<n;i++)
	{
		slld(x);	slld(y);	slld(r);
		P.pb( mp( r , mp(x,y) ) );
	}

	sort(P.begin(), P.end());

	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>i;j--)
		{
			if( contains( P[j] , P[i] ) )
			{
				level[i] = max(level[i],level[j]+1);
			}
		}
		if(level[i]==0)
			level[i] = 1;

		// printf("%lld %lld %lld : %d\n", P[i].F , P[i].S.F , P[i].S.S , level[i] );
	}

	for(i=0;i<n;i++)
	{
		if(level[i]<=2)
			ans += (P[i].F * P[i].F);
		else
		{
			if(level[i]%2==1)
				ans -= (P[i].F * P[i].F);
			else
				ans += (P[i].F * P[i].F);
		}
	}

	printf("%.10lf\n", ans * 3.14159265358979 );

	return 0;
}