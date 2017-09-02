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

bool A[100007];

int main()
{
	int i,j,k,l,m=0,n,ans=0;

	sd(n);

	for(i=0;i<2*n;i++)
	{
		sd(k);

		if(!A[k])
		{
			A[k] = true;
			m++;
		}
		else
		{
			A[k] = false;
			m--;
		}

		ans = max(ans,m);	

	}

	printf("%d\n", ans );	

	return 0;
}
