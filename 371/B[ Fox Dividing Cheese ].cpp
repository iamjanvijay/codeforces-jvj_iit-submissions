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

int fun(int X,int fact)
{
	int i = 0;
	while( X%fact == 0 )
	{
		i++;
		X /= fact;
	}
	return i;
}

int main()
{
	int a,b,i,j,k;

	sd(a);	sd(b);

	int a2,a3,a5,b2,b3,b5;

	a2 = fun(a,2);	a3 = fun(a,3);	a5 = fun(a,5);
	b2 = fun(b,2);	b3 = fun(b,3);	b5 = fun(b,5);

	while( a%2 == 0 )
		a /= 2;
	while( a%3 == 0 )
		a /= 3;
	while( a%5 == 0 )
		a /= 5;

	while( b%2 == 0 )
		b /= 2;
	while( b%3 == 0 )
		b /= 3;
	while( b%5 == 0 )
		b /= 5;


	if(a!=b)
	{
		printf("-1\n");
		return 0;
	}

	printf("%d\n", abs(a2-b2) + abs(a3-b3) + abs(a5-b5) );

	return 0;
}
