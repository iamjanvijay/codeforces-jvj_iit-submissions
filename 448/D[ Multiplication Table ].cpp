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

ll i,j,n,m,k;

ll LessthanOREq(ll num)
{
	j = 0;
	for(i=1;i<=m;i++)
	{
		j += min(num/i,n);
	}
	return j;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	slld(n);	slld(m);	slld(k);

	ll first = 1, last = n*m, mid;

	while(first+1 < last)
	{
		mid = (first+last)/2 ;

		if( LessthanOREq(mid) >= k )
			last = mid;
		else
			first = mid;
	}

	if( LessthanOREq(first) >= k )
		printf("%lld\n", first );
	else
		printf("%lld\n", last );
	
	return 0;
}