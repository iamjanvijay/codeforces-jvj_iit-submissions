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

char S[100007];
int i;

ll left(ll x,ll n)
{
	if(x%2 == 1)
		return x;
	for(i=0;i<63;i++)
	{
		if( ( (x>>i) & 1LL ) != 0 )
			break;
	}
	x -= (1LL<<i);
	x += (1LL<<(i-1));
	return x;
}

ll right(ll x,ll n)
{
	if(x%2 == 1)
		return x;
	for(i=0;i<63;i++)
	{
		if( ( (x>>i) & 1LL ) != 0 )
			break;
	}
	x += (1LL<<(i-1));
	return x;
}

ll parent(ll x,ll n)
{
	if(x == (n+1)/2)
		return x;
	for(i=0;i<63;i++)
	{
		if( ( (x>>i) & 1LL ) != 0 )
			break;
	}
	if( ( (x>>(i+1)) & 1LL ) != 0 && x-(1LL<<i) > 0 )
		return x-(1LL<<i);
	x -= (1LL<<i);
	x += (1LL<<(i+1));
	return x;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,n,k,z;
	slld(n);	slld(k);

	while(k--)
	{
		slld(z);
		ss(S);

		for(i=0;S[i]!=&#39;\0&#39;;i++)
		{
			if(S[i]==&#39;U&#39;)
				z = parent(z,n);
			else if(S[i]==&#39;R&#39;)
				z = right(z,n);
			else
				z = left(z,n);
			// printf("%d \n", z );
		}

		printf("%lld\n", z );	

	}

	return 0;
}