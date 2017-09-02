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

int A[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,r,mini=INT_MAX;
	// ll i,j,k,l,m,n,x,y,z,r;

	sd(n);	sd(m);	sd(k);

	for(i=1;i<=n;i++)
		sd(A[i]);

	for(i=1;i<=n;i++)
	{
		if(A[i]>0 && A[i]<=k)
		{
			mini=min(mini,10*abs(i-m));
		}
	}

	printf("%d\n", mini );
	
	return 0;
}