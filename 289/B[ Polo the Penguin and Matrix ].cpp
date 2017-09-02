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

int A[107][107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int n,m,d,i,j,k,l=0,p,ans=INT_MAX;

	sd(n);	sd(m);	sd(d);

	bool flag = false;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			sd(A[i][j]);
		}	
	}

	k = A[0][0] % d;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(A[i][j] % d != k)
			{
				flag = true;
				break;
			}
		}	
	}

	if(flag)
	{
		printf("-1\n");
		return 0;
	}

	k = A[0][0];
	p = A[0][0];

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			k = min(k,A[i][j]);
			p = max(p,A[i][j]);
		}	
	}


	for(k;k<=p;k+=d)
	{
		l = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				l += abs(A[i][j] - k);
			}	
		}
		ans = min(ans,l);
	}

	printf("%d\n", ans/d );	
	
	return 0;
}