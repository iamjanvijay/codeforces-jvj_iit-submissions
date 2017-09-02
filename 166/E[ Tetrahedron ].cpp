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

ll A[10000007];
ll Mod = 1000000007LL;

int main()
{
	ll i,x,n;

	A[1] = 3;	A[2] = 6;	x=4*3*3;

	for(i=3;i<=10000000;i++)
	{
		A[i] = ((x%Mod) - ((2*A[i-1] + A[i-2])%Mod) + Mod)%Mod;
		x = (3*x)%Mod;
	}	

	slld(n);

	if(n==1)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n", A[n-1] );
	}	

	return 0;
}