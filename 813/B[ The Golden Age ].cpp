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

vector<ll> v1,v2,v3;
map<ll,bool> M;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(x);	slld(y);	slld(l);	slld(r);

	long double a;

	a = 1;
	while( a > 0 && a<=1000000000000000000LL )
	{
		v1.pb(a);
		a*=x;
	}

	a = 1;
	while( a > 0 && a<=1000000000000000000LL )
	{
		v2.pb(a);
		a*=y;
	}	

	for(i=0;i<sz(v1);i++)
		for(j=0;j<sz(v2);j++)
			if( l<=v1[i] + v2[j] && v1[i] + v2[j] <=r && !M[ v1[i] + v2[j] ])
			{
				v3.pb( v1[i] + v2[j] );
				M[ v1[i] + v2[j] ] = true;
			}


	v3.pb(l-1);	v3.pb(r+1);

	sort(v3.begin(), v3.end());
	
	b = 0;
	for(i=1;i<sz(v3);i++)
	{
		b = max(b,v3[i]-v3[i-1]-1);
	}
	// printf("\n");

	printf("%lld\n", b );	
	
	return 0;
}