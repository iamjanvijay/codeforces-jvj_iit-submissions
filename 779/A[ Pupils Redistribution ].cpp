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

int A[7];
int B[7];

int main()
{
	int i,j,k,l,n,ans=0;
	sd(n);

	for(i=0;i<n;i++)
	{
		sd(j);
		A[j]++;
	}

	for(i=0;i<n;i++)
	{
		sd(j);
		B[j]++;
	}

	for(i=1;i<=5;i++)
	{
		if( (A[i]+B[i])%2 != 0 )
		{
			printf("-1\n");
			return 0;
		}
	}

	for(i=1;i<=5;i++)
	{
		ans += abs( (A[i]+B[i])/2 - A[i] );
	}

	printf("%d\n", ans/2 );	

	return 0;
}
