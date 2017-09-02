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

ll A[200007];
ll B[200007];
int ind[200007];

int main()
{
	int i,j,k,l,m,n,ans1,ans2;
	ll t,cur;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
		slld(B[i]);

	for(t=0,i=0;i<k;i++)
		t += B[i];

	A[0] = t;

	for(i,j=0;i<n;i++,j++)
	{
		t += B[i];
		t -= B[j];
		A[j+1] = t; 
	}

	// for(i=0;i<=n-k;i++)
	// 	printf("%lld %lld %d\n", A[i],B[i],ind[i] );	


	cur = A[n-k];

	for(i=n-k;i>=0;i--)
	{
		if( cur <= A[i] )
		{
			ind[i] = i;
			B[i] = A[i];
			cur = A[i];
		}
		else
		{
			ind[i] = ind[i+1];
			B[i] = B[i+1];
		}	
	}

	// for(i=0;i<=n-k;i++)
	// 	printf("%lld %lld %d\n", A[i],B[i],ind[i] );	

	cur = 0;

	for(i=0,j=k;j<=n-k;i++,j++)
	{
		if( cur < A[i] + B[j] )
		{
			ans1 = i;	ans2 = ind[j];
			cur = A[i] + B[j];
		}	
	}

	printf("%d %d\n", ans1+1,ans2+1 );	

	return 0;
}
