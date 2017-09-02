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

bool function(ll &cnt1,ll &cnt2,ll &x,ll &y,ll &mid)
{
	ll only1 = mid/y - mid/(x*y);
	ll only2 = mid/x - mid/(x*y);
	ll either = mid - mid/x - mid/y + mid/(x*y);
	if( (only1 >= cnt1) && (only2 >= cnt2) )
	{

		return true;
	}	
	else if( (only1 >= cnt1) && (!(only2 >= cnt2)) )
	{

		if( (only2+either) >= cnt2 )
			return true;
		else
			return false;
	}
	else if( (!(only1 >= cnt1)) && (only2 >= cnt2) )
	{

		if(only1 + either >= cnt1 )
		{
			// printf("%lld %lld %lld %lld\n",mid/x,cnt2, mid/(x*y) + mid - mid/x , cnt1 );
			// printf("YES\n");
			return true;
		}
		else
			return false;
	}
	else
	{
		if( ((cnt1 - only1) + (cnt2 - only2)) <= (either) )
			return true;
		else
			return false;
	}	
}

int main()
{
	ll i,j,k,l,cnt1,cnt2,x,y;

	slld(cnt1);		slld(cnt2);
	slld(x);		slld(y);

	ll first = 1, last = 100000000000000000LL, mid;

	// cnt1 = 916200; cnt2 = 69682; x = 2; y= 3; mid = 1374300;
	// function(cnt1,cnt2,x,y,mid);

	while( first + 1 < last )
	{
		mid = (first+last)/2;

		if( function(cnt1,cnt2,x,y,mid) )
			last = mid;
		else
			first = mid;
	}

	if( function(cnt1,cnt2,x,y,first) )
		printf("%lld\n", first );
	else
		printf("%lld\n", last );

	return 0;
}
