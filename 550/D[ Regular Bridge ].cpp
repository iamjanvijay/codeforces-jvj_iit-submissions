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

int E[100000][2];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l=0,m=0,n;

	sd(k);

	if(k%2==0)
		printf("NO\n");	
	else if(k==1)
	{
		printf("YES\n2 1\n1 2\n");
	}
	else
	{
		for(i=1;i<=k+1;i++)
		{
			for(j=i+1;j<=k+1;j++)
			{
				if(i+1==j && j%2==0 && l<k-1)
				{
					E[m][0] = i;
					E[m++][1] = k+2;
					E[m][0] = k+2;
					E[m++][1] = j;
					l+=2;
				}
				else
				{
					E[m][0] = i;	
					E[m++][1] = j;
				}	
			}
		}

		// for(i=0;i<m;i++)
		// 	printf("%d %d\n", E[i][0] , E[i][1] );
		// printf("*\n");			


		printf("YES\n");
		printf("%d %d\n",2*k+4,2*m+1 );

		for(i=0;i<m;i++)
			printf("%d %d\n", E[i][0] , E[i][1] );

		for(i=0;i<m;i++)
			printf("%d %d\n", E[i][0]+k+2 , E[i][1]+k+2 );		

		printf("%d %d\n",k+2,2*(k+2) );

	}
	
	return 0;
}