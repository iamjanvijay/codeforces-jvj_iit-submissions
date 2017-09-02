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

int A[5000007] = {0};

void init()
{
	int i,j,k,l;
	for(i=2;i*i<5000007;i++)
	{
		if(A[i] == 0)
		{
			for(j=i*i;j<5000007;j+=i)
			{
				A[j] = i;
			}
		}
	}

	A[1] = 0;

	for(i=2;i<5000007;i++)
	{
		if(A[i]==0)
			A[i] = 1;
		else
			A[i] = 1 + A[i/A[i]];
	}

	for(i=2;i<5000007;i++)
		A[i] += A[i-1];

}

int main()
{
	init();

	int i,j,k,l,a,b,T;
	sd(T);

	while(T--)
	{
		sd(a);	sd(b);
		printf("%d\n", A[a] - A[b] );
	}

	return 0;
}