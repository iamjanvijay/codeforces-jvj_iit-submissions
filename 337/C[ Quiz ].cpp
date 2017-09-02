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
ll Mod = 1000000009;

ll power(ll n)
{
	if(n==0)
		return 1;

	ll temp = power(n/2);
	if(n%2==0)
		return (temp*temp)%Mod;
	else
		return (2LL*temp*temp)%Mod;
}

bool chk(ll i,ll n,ll m,ll k)
{
	if( (i*k) + (m - i*(k-1)) <= n )
		return true;
	return false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);	slld(m);	slld(k);

	ll first = 0,last = m/(k-1),mid;

	while(first+1<last)
	{
		mid = (first+last)/2;

		if( chk(mid,n,m,k) )
			first = mid;
		else
			last = mid;		
	}

	if( chk(last,n,m,k) )
	{
		// printf("**%lld\n", last );
		l = (power( ((m - last*(k-1))/k + 1) ) - 2)*k + (m - last*(k-1))%k + (last*(k-1));
	}
	else	
	{
		// printf("*%lld\n", first );
		l = (power( ((m - first*(k-1))/k + 1) ) - 2)*k + (m - first*(k-1))%k + (first*(k-1));
	}

	printf("%lld\n", (l+Mod)%Mod );
	return 0;
}