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
	ll i,k,j,n,z=0;
	slld(n);

	k = n;

	while( k!=0 )
	{
		if( k%10 == 4 || k%10 == 7 )
			z++;
		k/=10;
	}

	if( z==4 || z==7 )
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}

