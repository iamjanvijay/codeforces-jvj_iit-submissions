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

int h[100007];

int main()
{
	int i,j,k,l,n;

	sd(n);

	for(i=0;i<n;i++)
		sd(h[i]);

	k = h[n-1];
	for(i=n-2;i>=0;i--)
	{
		k = max(k,h[i]);
	}

	printf("%d\n", k );		

	return 0;
}
