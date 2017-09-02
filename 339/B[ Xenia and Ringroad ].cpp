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

ll dists(ll cur, ll dest,ll n)
{
	if(dest>=cur)
		return dest-cur;
	else
		return n-cur+dest;
}

int main()
{
	ll n,m,i,j,k,ans=0;

	slld(n);	slld(m);

	j = 1;

	for(i=0;i<m;i++)
	{
		slld(k);
		ans += dists(j,k,n);
		j = k;
	}

	printf("%lld\n", ans );	

	return 0;
}
