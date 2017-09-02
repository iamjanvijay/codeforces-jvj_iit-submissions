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

int A[200007];
map<int,int> M;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=0,n,mini=INT_MAX;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	sort(A,A+n);

	for(i=1;i<n;i++)
	{
		if( A[i]-A[i-1] < mini )
		{
			m=1;
			mini = A[i]-A[i-1];
		}
		else if( A[i]-A[i-1] == mini )
		{
			m++;
		}
	}

	printf("%d %d\n", mini, m );
			
	return 0;
}