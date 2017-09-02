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

int X[60007];
int V[60007];

int main()
{
	int i,j,k,l,m,n;

	double first=DBL_MAX,last=0,mid1,mid2,t1,t2;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(X[i]);
		first = min(first,(double)X[i]);
		last = max(last,(double)X[i]);
	}	

	for(i=0;i<n;i++)
		sd(V[i]);

	t1 = t2 = 0;

	while( last-first > 0.00000001 )
	{
		mid1 = first + (last-first)/3;
		mid2 = first + 2*(last-first)/3;

		t1 = t2 = 0;

		for(i=0;i<n;i++)
			t1 = max(t1,fabs(mid1-X[i])/V[i]);

		for(i=0;i<n;i++)
			t2 = max(t2,fabs(mid2-X[i])/V[i]);

		if(t1>t2)
			first = mid1;
		else
			last = mid2;
	}

	printf("%0.10lf\n", (t1+t2)/2 );	

	return 0;
}
