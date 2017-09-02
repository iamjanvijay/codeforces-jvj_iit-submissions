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

ll A[1000007];

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll x = power(a,b/2);
	if(b%2==0)
		return x*x;
	else
		return x*x*a;
}

int main()
{
	ll i,j=0,k,a,b,c,z,l;

	slld(a);	slld(b);	slld(c);

	for(i=1;i<=81;i++)
	{
		z = b * power(i,a) + c;
		l = z;
		k = 0;
		while(z!=0)
		{
			k += z%10;
			z /= 10;
		}
		if(k==i && 0 < l && l < 1000000000LL)
			A[ j++ ] = l;	
	}	

	printf("%lld\n",j );

	if(j==0)
	{
		return 0;
	}

	sort(A,A+j);

	for(i=0;i<j;i++)
		printf("%lld ", A[i] );
	printf("\n");
	return 0;
}
