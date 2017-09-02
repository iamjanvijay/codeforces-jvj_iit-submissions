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

	int i,j,k,l,maxi=1,n;
	ll sum=0;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(k);
		sum+=k;
		maxi = max(maxi,k);
	}

	printf("%lld\n", max( (ll)maxi , (sum%(n-1)) ? ( sum/(n-1) + 1 ) : (sum/(n-1))  ) );

	return 0;
}