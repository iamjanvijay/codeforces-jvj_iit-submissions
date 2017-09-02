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

int A[300007];
int B[300007];
map<int,bool> M;

int main()
{
	int i,j,k,l,m,n;
	ll ans=0;
	sd(n);

	for(i=0;i<n;i++)
	{
		sd(A[i]);
	}

	j=n;

	for(i=0;i<j;i++)
	{
		if(1<=A[i] && A[i]<=n && !M[k])
		{
			k = A[i];
			A[i] = A[j-1];
			A[j-1] = k;
			M[k] = true;
			j--;
		}
	}

	l=j;

	for(i=1,j=0;i<=n;i++)
	{
		if(!M[i])
		{
			B[j++] = i;
		}	
	}

	n=l;

	sort(A,A+n);
	sort(B,B+n);	

	// for(i=0;i<n;i++)
	// 	printf("%d ", A[i] );
	// printf("\n");

	// for(i=0;i<n;i++)
	// 	printf("%d ", B[i] );
	// printf("\n");

	for(i=0;i<n;i++)
		ans += abs(A[i]-B[i]);

	printf("%lld\n", ans );

	return 0;
}
