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

	int i,j,k,l,m,n;

	sd(n);

	for(i=0;i<=n/4;i++)
	{
		if((n-4*i)%7==0)
			break;
	}

	if(i>n/4)
	{
		printf("-1\n");
		return 0;
	}

	for(j=0;j<i;j++)
		printf("4");
	for(j=0;j<(n-4*i)/7;j++)
		printf("7");
	printf("\n");
	return 0;
}