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
	int i,j,k,l,r,g,b;

	sd(r);	sd(g);	sd(b);

	l = min(min(r,g),b);

	k = r/3 + g/3 + b/3;

	if(l>=1)
	{
		k = max( 1 + (r-1)/3 + (g-1)/3 + (b-1)/3 , k );
	}

	if(l>=2)
	{
		k = max( 2 + (r-2)/3 + (g-2)/3 + (b-2)/3 , k );
	}	

	printf("%d\n", k );

	return 0;
}
