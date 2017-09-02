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
	int n,i,j,k,l;

	sd(n);

	for(i=0;i<n;i++)
		sd(A[i]);

	sort(A,A+n);

	for(k=0,i=0;i<n;i++)
		k+= A[i];

	for(j=0,i=n-1;i>=0;i--)
	{
		j += A[i];
		if(j > k-j)
			break;
	}

	printf("%d\n", n-i );	

	return 0;
}
