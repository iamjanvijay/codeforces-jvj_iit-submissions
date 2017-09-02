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
	int i,j,X,Y,Z;

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			sd(Z);
			if(Z != 0)
			{
				X = i; Y = j;
			}
		}
	}

	printf("%d\n", abs(2-X)+abs(2-Y) );

	return 0;
}