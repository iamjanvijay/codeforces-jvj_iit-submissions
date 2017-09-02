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

double DP_D[10007][1007] = {0};
double DP_P[10007][1007] = {0};

int main()
{
	int i,j,w,b;
	sd(w);sd(b);

	DP_D[0][0] = 1;	DP_P[0][0] = 0;

	for(i=1;i<=w;i++)
	{
		DP_D[i][0] = DP_P[i][0] = 1;
	}

	for(j=1;j<=b;j++)
	{
		DP_D[0][j] = 1; DP_P[0][j] = 0;
	}	

	for(i=1;i<=w;i++)
	{
		for(j=1;j<=b;j++)
		{
			DP_P[i][j] = ((double)i) / ((double)(i+j));
			DP_D[i][j] = ((double)i) / ((double)(i+j));

			DP_P[i][j] += ( ((double)j) / ((double)(i+j)) * (1 - DP_D[i][j-1]) );

			if(j!=1)
			{
				DP_D[i][j] += ( ((double)j) / ((double)(i+j)) * ((double)(j-1)) / ((double)(i+j-1)) * (1 - DP_P[i][j-2]) );
				DP_D[i][j] += ( ((double)j) / ((double)(i+j)) * ((double)(i)) / ((double)(i+j-1)) * (1 - DP_P[i-1][j-1]) );
			}
		}
	}	

	printf("%.9lf\n", DP_P[w][b] );

	return 0;
}
