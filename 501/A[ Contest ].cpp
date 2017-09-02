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
	int a,b,c,d,i,j,k,l,n;

	sd(a); sd(c); sd(b); sd(d);

	i = max( 3*a/10, a - a/250*b );
	j = max( 3*c/10, c - c/250*d );

	if(i>j)
		printf("Misha\n");
	else if(j>i)
		printf("Vasya\n");
	else
		printf("Tie\n");

	return 0;
}
