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

vector<int> A[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;
	sd(n);	
	
	for(i=0;i<n*n;i++)
	{
		if((i/n)%2==0)
		{
			A[(i%n)].push_back(i);
		}
		else
		{
			A[(n-1)-(i%n)].push_back(i);
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<A[i].size();j++)
		{
			printf("%d ",A[i][j]+1 );
		}
		printf("\n");
	}

	return 0;
}