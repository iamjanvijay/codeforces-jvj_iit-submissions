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

ll maxSum(int n,int m)
{
	ll cursum=0,maxSum=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(i%2==m)
			cursum += A[i];
		else
			cursum -= A[i];
		maxSum = max(cursum,maxSum);
		if(cursum<0)
			cursum = 0;
	}
	return maxSum;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(n);
	for(i=0;i<n;i++)
		slld(A[i]);
	
	for(i=0;i<n-1;i++)
		A[i] = abs(A[i]-A[i+1]);
	n--;

	printf("%lld\n", max(maxSum(n,0),maxSum(n,1)) );

	return 0;
}