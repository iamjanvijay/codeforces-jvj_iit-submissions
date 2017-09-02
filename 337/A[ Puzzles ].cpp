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

int A[57];

int main()
{
	int i,j,k,l,n,m;

	sd(n);	sd(m);

	for(i=0;i<m;i++)
		sd(A[i]);

	sort(A,A+m);

	k = INT_MAX;

	for(i=0,j=n-1;j<m;j++,i++)
	{
		k = min(k, A[j]-A[i]);
	}

	printf("%d\n",k);	

	return 0;
}
