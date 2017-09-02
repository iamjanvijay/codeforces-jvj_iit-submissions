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

ll C[37][37];

void init()
{
	int n,r;

	C[0][0] = 1;
	for(n=1;n<=30;n++)
	{
		for(r=0;r<=n;r++)
		{
			if(r==0 || r==n)
				C[n][r] = 1;
			else
				C[n][r] = C[n-1][r-1] + C[n-1][r];
		}
	}
}

int main()
{
	ll b,g,N,M,T,ans=0;

	slld(N);	slld(M);	slld(T);

	init();

	for(b = 4,g = T-4;g>=1;b++,g--)
	{
		if(g<=M && b<=N)
			ans += (C[N][b] * C[M][g]);
	}

	printf("%lld\n",ans);

	return 0;
}