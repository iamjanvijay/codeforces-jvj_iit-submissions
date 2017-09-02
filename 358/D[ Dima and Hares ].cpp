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

int A[3007];
int B[3007];
int C[3007];

int DP[3007][2];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);
	for(i=0;i<n;i++)
		sd(B[i]);
	for(i=0;i<n;i++)
		sd(C[i]);

	for(i=n-1;i>=0;i--)
	{
		if(i==n-1)
		{
			DP[i][0] = A[i];
			DP[i][1] = B[i];
		}
		else
		{
			DP[i][0] = max( A[i] + DP[i+1][1] , B[i] + DP[i+1][0] );
			DP[i][1] = max( B[i] + DP[i+1][1] , C[i] + DP[i+1][0] );
		}
	}

	printf("%d\n", DP[0][0] );

	return 0;
}