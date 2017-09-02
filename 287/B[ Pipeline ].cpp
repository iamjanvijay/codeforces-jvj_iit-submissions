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

bool chk(ll k,ll c,ll n)
{
	if( n <= 1 + k*(k-1)/2 - (k-c-1)*(k-c)/2 )
		return true;
	return false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,n,k,first,last,mid;

	slld(n);	slld(k);

	first = 1; last = k-1;

	if(n==1)
	{
		printf("0\n");
		return 0;
	}

	if( !chk(k,last,n) )
	{
		printf("-1\n");
		return 0;
	}

	while(first+1<last)
	{
		mid = (first+last)/2;

		if( chk(k,mid,n) )
			last = mid;
		else
			first = mid;
	}

	if( chk(k,first,n) )
		printf("%d\n", first );
	else
		printf("%d\n", last );
	return 0;
}