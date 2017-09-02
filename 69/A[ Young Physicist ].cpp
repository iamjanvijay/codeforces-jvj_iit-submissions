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
	int N,x,y,z,X=0,Y=0,Z=0;
	sd(N);

	while(N--)
	{
		sd(x);	sd(y);	sd(z);
		X+=x;	Y+=y;	Z+=z;
	}

	if(X==0 && Y==0 && Z==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}