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

ll Mod=1000000007;
ll A[100007];
multiset<ll> S;
map<ll,ll> M;

ll power(ll x,ll y)
{
	if(y==0)
		return 1;

	ll temp = power(x,y/2);

	if(y%2==0)
		return (temp*temp)%Mod;
	else
		return (((temp*temp)%Mod)*x)%Mod;
}


int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l=0,m,n,x,y,z,a,b,r,t=0,ans = 0;

	slld(n);	slld(x);

	for(i=0;i<n;i++)
	{
		slld(A[i]);	t+=A[i];
	}

	for(i=0;i<n;i++)
	{
		S.insert( t-A[i] );
		M[ t-A[i] ]++;
	}


	set<ll>::iterator it;

	while( ! S.empty() )
	{
		it = S.begin();

		a = *it;
		m = M[ *it ];

		
		if( m%x != 0 )
		{
			ans = a;
			break;
		}

		M[ a ] = 0;
		M[ a+1 ] += m/x;

		S.erase( a );
		S.insert( a+1 ); 
	}

	printf("%lld\n", power(x, min(t,ans)));
	
	return 0;
}