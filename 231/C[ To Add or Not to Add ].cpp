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

ll A[100007];
ll Psum[100007];

ll PreSum(int i,int j)
{
	return Psum[j] - Psum[i-1];
}

int Binary(int i, int n, int k)
{
	int ans = 1;
	ll Sum;
	int first = i, last = n, mid;

	while( first + 1 < last )
	{
		mid = (first+last)/2;

		if( (ll)A[i] * (mid-i+1) - PreSum(i,mid) <= k )
		{
			first = mid;
		}
		else
		{
			last = mid;
		}	

	}

	if( (ll)A[i] * (last-i+1) - PreSum(i,last) <= k )
		return (last-i+1);
	else
		return (first-i+1);

}

int main()
{
	int i,j,k,l,m,n,ans1=0,ans2=0;

	sd(n);	sd(k);

	for(i=1;i<=n;i++)
		slld(A[i]);

	sort(A+1,A+n+1,greater<int>());

	// for(i=1;i<=n;i++)
	// 	printf("%lld ",A[i]);
	// printf("\n");

	for(i=1;i<=n;i++)
		Psum[i] = Psum[i-1] + A[i];

	for(i=n;i>=1;i--)
	{
		l = Binary(i,n,k);
		// printf("%d %d\n", i , l );
		if(l > ans1)
		{
			ans1 = l;
			ans2 = A[i];
		}	
	}

	printf("%d %d\n", ans1, ans2 );

	return 0;
}
