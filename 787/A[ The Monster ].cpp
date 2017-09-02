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

	int a,b,c,d,i,j,k,l,ans=INT_MAX;

	sd(a);	sd(b);
	sd(c);	sd(d);

	for(i=0;i<=1000;i++)
	{
		for(j=0;j<=1000;j++)
		{
			if( b+a*j == d+c*i)
			{
				ans = min(ans,d+c*i);
				
			}
		}
	}

	if(ans==INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", ans );
	
	return 0;
}