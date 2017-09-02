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
	int n,k,i,j;

	sd(n);	sd(k);

	j = n;

	for(i=0;i<k;i++)
	{
		printf("%d ", j );
		j--;
	}

	for(i=1;i<=j;i++)
		printf("%d ", i );	

	printf("\n");
	
	return 0;
}
