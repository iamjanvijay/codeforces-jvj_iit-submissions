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

set<int> S;

int main()
{
	int t,n,i,j,k;

	sd(t);

	for(i=3;i<=360;i++)
	{
		if(360%i == 0)
		{
			S.insert( 180 - 360/i );
		}	
	}

	while(t--)
	{
		sd(k);
		if( S.count(k) != 0 )
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}	

	return 0;
}
