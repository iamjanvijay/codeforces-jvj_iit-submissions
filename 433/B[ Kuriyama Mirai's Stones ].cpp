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
ll B[100007];

int main()
{
	int i,j,k,l,m,n;

	sd(n);
	for(i=1;i<=n;i++)
	{
		slld(A[i]);
		B[i] = A[i];
	}

	sort(B+1,B+1+n);

	for(i=1;i<=n;i++)
	{
		A[i] += A[i-1];
		B[i] += B[i-1];
	}

	sd(m);

	while(m--)
	{
		sd(j);	sd(k);	sd(l);
		
		if(j==1)
		{
			printf("%lld\n", A[l]-A[k-1] );
		}
		else
		{
			printf("%lld\n", B[l]-B[k-1] );
		}	
	}	

	return 0;
}
