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

int A[107];

int main()
{
	int i,t,n;

	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(t);
		A[t] = i;
	}

	for(i=1;i<=n;i++)
		printf("%d ", A[i] );
	printf("\n");

	return 0;
}

