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

	int i,j,k,l,m,n,miniA=1000000000,maxiA=1,miniB=1000000000,maxiB=1,ans=0;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(k);	sd(l);
		miniA = min(l,miniA);
		maxiA = max(k,maxiA);
	}

	// printf("*  %d %d\n", miniA,maxiA );

	sd(m);	

	for(i=0;i<m;i++)
	{
		sd(k);	sd(l);
		miniB = min(l,miniB);
		maxiB = max(k,maxiB);
	}

	// printf("*  %d %d\n", miniB,maxiB );

	if(miniA<=maxiB)	
		ans = max(ans,maxiB-miniA);

	if(miniB<=maxiA)	
		ans = max(ans,maxiA-miniB);

	printf("%d\n", ans );		

	return 0;
}