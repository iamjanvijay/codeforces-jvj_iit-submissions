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

int main()
{
	unsigned ll l,r;
	int i;
	unsigned ll a,b;

	slld(l);	slld(r);

	// printf("%lld %lld\n", l , r );

	a = 0;

	for(i=63;i>=0;i--)
	{
		if( (r-l+1) > (1LL<<i) || r/(1LL<<i) != l/(1LL<<i) )
			a |= (1LL<<i);
	}	

	printf("%lld\n", a );

	return 0;
}
