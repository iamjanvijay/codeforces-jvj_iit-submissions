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
	bool flag = true;
	int i,j,a,b,c,d,N;

	sd(N);

	for(i=0;i<4;i++)
	{
		sd(a); sd(b); sd(c); sd(d);
		if( flag && min(a,b) + min(c,d) <= N )
		{
			printf("%d %d %d\n",i+1,min(a,b),N-min(a,b));
			flag = false;
		}
	}

	if(flag)
		printf("-1\n");

	return 0;
}

