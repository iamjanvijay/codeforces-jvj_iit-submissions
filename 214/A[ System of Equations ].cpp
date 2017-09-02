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
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int a,b,n,m,ans=0;

	sd(n);	sd(m);

	for(a=0;a<=min(n,m);a++)
	{
		for(b=0;b<=min(n,m);b++)
		{
			if(a*a+b==n && a+b*b==m)
				ans++;
		}
	}

	printf("%d\n", ans );

	return 0;
}