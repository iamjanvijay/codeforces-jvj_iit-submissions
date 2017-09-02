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

	ll R[2],n,i,j,k,l,a,b,ans=LLONG_MAX,ans1=0,ans2=0;

	slld(n);	slld(R[0]);	slld(R[1]);
	a = R[0];	b = R[1];
	sort(R,R+2);

	if( R[0] * R[0] > (6*n) )
	{
		printf("%lld\n", R[0] * R[1] );
		printf("%lld %lld\n", a, b );
		return 0;
	}
	
	for(i=R[0]; i*i <= (6*n) ;i++)
	{
		 if( (6*n) % i == 0 )
		 	k = (6*n)/i;
		 else
		 	k = (6*n)/i + 1;
		 if( k>=R[1] && ans > i*k )
		 {
		 	ans = i*k;
		 	if( a<=i && b<=k )
		 	{
		 		ans1 = i;
		 		ans2 = k;
		 	}
		 	else
		 	{
		 		ans1 = k;
		 		ans2 = i;
		 	}		 		
		 }	
	}

	printf("%lld\n", ans );	
	printf("%lld %lld\n", ans1, ans2 );	
	return 0;
}