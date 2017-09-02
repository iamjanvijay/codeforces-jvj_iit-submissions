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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int n,m,i,j,k,l;

	sd(n);	sd(m);

	if(m<n-1 || m>2*(n+1))
	{
		printf("-1\n");
		return 0;
	}

	if(m==n-1)
	{
		for(i=0;i<m+n;i++)
		{
			if(i%2==0)
				printf("0");
			else
				printf("1");
		}
		return 0;
	}
	else
	{
		while(n>0 && m>0)
		{
			if(m-2>=n-1)
			{
				printf("110");	n-=1;	m-=2;
			}
			else
			{
				printf("10");	n-=1;	m-=1;
			}
		}
		if(m==1)
			printf("1\n");
		else if(m==2)
			printf("11\n");
		
	}

	return 0;
}