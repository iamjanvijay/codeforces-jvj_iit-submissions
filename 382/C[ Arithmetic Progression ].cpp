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

int A[100007];
map<int,int> isThere;

int main()
{
	int i,j,k,l,m,d1,d2,n;

	sd(n);

	for(i=0;i<n;i++)
		sd(A[i]);

	if(n==1)
	{
		printf("-1\n");
	}
	else if(n==2)
	{
		if(A[1]-A[0]==0)
		{
			printf("1\n");
			printf("%d\n", A[0] );
			return 0;
		}
		else
		{
			if(A[0]>A[1])
			{
				A[2] = A[0];
				A[0] = A[1];
				A[1] = A[2];
			}	

			d1 = A[1]-A[0];

			if( d1%2 == 0 )
			{
				printf("3\n");
				printf("%d %d %d\n",A[0]-d1,(A[0]+A[1])/2,A[1]+d1);
				return 0;
			}
			else
			{
				printf("2\n" );
				printf("%d %d\n",A[0]-d1,A[1]+d1);
				return 0;				
			}	
		}	
	}	
	else
	{
		sort(A,A+n);

		m = 0;
		for(i=1;i<n;i++)
		{
			if(!isThere[A[i]-A[i-1]])
			{
				m++;
				if(m==1)
					d1 = A[i]-A[i-1];
				else if(m==2)
					d2 = A[i]-A[i-1];
				else
				{
					printf("0\n" );
					return 0;
				}
			}
			isThere[A[i]-A[i-1]]++;	
		}

		if(m==1)
		{
			if(d1!=0)
			{
				printf("2\n");
				printf("%d %d\n", A[0] - d1 ,A[n-1] + d1 );
				return 0;
			}
			else
			{
				printf("1\n");
				printf("%d\n", A[0]);
				return 0;
			}	
		}
		else
		{
			if(d1<d2 && isThere[d2]==1 && d2%2==0 && d2/2 == d1)
			{
				printf("1\n");
				for(i=1;i<n;i++)
				{
					if( (A[i]-A[i-1]) == d2 )
					{
						printf("%d\n", (A[i]+A[i-1])/2 );
						return 0;
					}	
				}	
			}
			else if(d2<d1 && isThere[d1]==1 && d1%2==0 && d1/2 == d2)
			{
				printf("1\n");	
				for(i=1;i<n;i++)
				{
					if( (A[i]-A[i-1]) == d1 )
					{
						printf("%d\n", (A[i]+A[i-1])/2 );
						return 0;
					}	
				}							
			}
			else
			{
				printf("0\n");
				return 0;
			}				
		}	

	}	

	return 0;
}
