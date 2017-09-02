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
	int i,j,N,ans=0,Sum=0,Temp;
	sd(N);

	for(i=0;i<N;i++)
	{
		sd(Temp);
		Sum += Temp;
	}



	for(j=1;j<=5;j++)
	{
		if( (Sum+j-1)%(N+1) != 0 )
			ans++;
	}

	printf("%d\n",ans);

	return 0;
}