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

ll A[2000007];
ll C[2000007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m=0,n;

	slld(n);
	for(i=1;i<=n;i++)
		slld(A[i]);

	sort(A+1,A+n+1);
	
	for(i=1;i<=n/2;i++)
	{
		k = A[i];	A[i] = A[n+1-i];	A[n+1-i] = k;
	}

	for(l=1;l<=n;l*=4)
	{
		C[l+1] += -1;	C[1] += 1;
	}
	
	for(i=1;i<=n;i++)
	{
		C[i] += C[i-1];
		m += (A[i]*C[i]);
	}

	printf("%lld\n", m );

	return 0;
}