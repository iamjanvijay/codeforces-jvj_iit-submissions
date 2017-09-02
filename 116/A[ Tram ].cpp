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
	int i,n,a,b,cap=0,maxi=0;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(a);	sd(b);

		cap-=a;
		cap+=b;

		maxi = max(cap,maxi);

	}

	printf("%d\n",maxi);	

	return 0;
}
