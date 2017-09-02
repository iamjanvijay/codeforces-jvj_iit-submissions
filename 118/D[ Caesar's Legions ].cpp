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

ll DP[107][107][2];
int Mod = 100000000;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n1,n2,k1,k2,col;

	sd(n1);	sd(n2);	sd(k1);	sd(k2);

	for(i=0;i<=n1;i++)
	{
		for(j=0;j<=n2;j++)
		{
			for(k=0;k<2;k++)
			{
				if( i+j == 0 )
					DP[i][j][k] = 1;
				else if( (i==0 && k==0) || (j==0 && k==1) )
					DP[i][j][k] = 0;
				else
				{
					DP[i][j][k] = 0;
					if(k==0)
					{
						for(l=1;l<=min(k1,i);l++)
						{
							DP[i][j][k] = ( DP[i][j][k] + DP[i-l][j][1-k] )%Mod;
						}	
					}
					else
					{
						for(l=1;l<=min(k2,j);l++)
						{
							DP[i][j][k] = ( DP[i][j][k] + DP[i][j-l][1-k] )%Mod;
						}
					}	
				}		 
			}	
		}	
	}	
	
	printf("%lld\n", (DP[n1][n2][0]+DP[n1][n2][1])%Mod );

	return 0;
}