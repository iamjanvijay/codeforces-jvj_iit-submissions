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

map<ll,ll> Count;
ll A[500007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,sum=0,ans=0;

	slld(n);

	for(i=1;i<=n;i++)
	{
		slld(A[i]);
		sum+=A[i];
		A[i] += A[i-1];

		if(i>=2 && i<=n-1)
			Count[A[i]]++;
	}

	if(sum%3 != 0)
	{
		printf("0\n" );
		return 0;
	}

	sum/=3;
	for(i=2;i<=n-1;i++)
	{
		if(A[i-1]==sum)
		{
			ans += Count[ sum + A[i-1] ];
		}
		Count[A[i]]--;
	}	

	printf("%lld\n",ans);
	return 0;
}