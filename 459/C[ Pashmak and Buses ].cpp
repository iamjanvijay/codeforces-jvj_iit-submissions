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

int ceil(int n,int k)
{
	if(n%k==0)
		return n/k;
	return n/k+1;
}

int A[1007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int n,d,k,i,j,l,m,x,y,z;
	sd(n);	sd(k);	sd(d);

	x = ceil(n,k);
	for(y=0,z=1;y<31;y++,z*=k)
		if(z>=x)
			break;		
	if(n==1)
	{
		for(i=0;i<d;i++)
			printf("1\n" );
	}	
	else if(k==1 && n>1)
	{
		printf("-1\n");
	}
	else if( d < 1+y )
	{
		printf("-1\n");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			A[i] = i/x;
		}

		for(i=z;i>=1;i/=k)
		{
			// printf("*%d\n",i);
			for(j=0;j<x;j++)
			{
				m=(j/i)%k;
				for(l=j;l<n;l+=x)
				{
					A[l] = (A[l]+m)%k;
				}
	
			}

			for(l=0;l<n;l++)
				printf("%d ", A[l]+1 );
			printf("\n");

		}

		for(i=y+1;i<d;i++)
		{
			for(l=0;l<n;l++)
				printf("%d ", A[l]+1 );
			printf("\n");			
		}	

	}
	
	return 0;
}