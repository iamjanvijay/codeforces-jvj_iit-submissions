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
ll Count[200007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n,q;
	ll temp = 0;
	sd(n);	sd(q);

	for(i=1;i<=n;i++)
		slld(A[i]);

	while( q-- )
	{
		sd(l);	sd(r);
		Count[l] += 1;
		Count[r+1] -= 1;
	}	
	
	for(i=1;i<=n;i++)
	{
		Count[i] += Count[i-1];
	}

	sort(Count+1,Count+n+1);
	sort(A+1,A+n+1);

	for(i=1;i<=n;i++)
	{
		temp += (A[i] * Count[i]);
	}	

	printf("%lld\n",temp );
	return 0;
}