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
int R[107];

int main()
{
	int i,j,k,l,m,n,ans=0;

	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(A[i]);
		R[i] = 1 - A[i];
	}

	for(i=1;i<=n;i++)
	{
		R[i] += R[i-1];
		A[i] += A[i-1];
	}

	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			k = R[j] - R[i-1] + A[i-1] + A[n] - A[j];
			ans = max(ans,k);
		}	
	}

	printf("%d\n", ans );	

	return 0;
}
