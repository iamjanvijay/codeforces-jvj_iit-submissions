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

char Mat[41][41];
int Count[41][41][41][41];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,n,m,q,a,b,c,d,z,y,ans;

	sd(n);	sd(m); sd(q);

	for(i=0;i<n;i++)
		ss(Mat[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			y = INT_MAX;
			
			if(Mat[i][j]==&#39;0&#39;)
			{
				for(k=i;k<n;k++)
				{
					if(Mat[k][j]==&#39;1&#39;)
						break;
					z = 0;
					for(l=j;l<m && z<y;l++)
					{
						if(Mat[k][l]==&#39;0&#39;)
						{
							Count[i+1][j+1][k+1][l+1] = 1;
							z++;
						}
						else
						{
							break;
						}

					}
					y = min(y,z);	
				}
			}
		}
	}

	// for(i=1;i<=n;i++)
	// {
	// 	for(j=1;j<=m;j++)
	// 	{
	// 		printf("\n%d %d : \n", i,j );
	// 		for(k=1;k<=n;k++)
	// 		{
	// 			for(l=1;l<=m;l++)
	// 				printf("%d ", Count[i][j][k][l] );
	// 			printf("\n");
	// 		}
	// 	}
	// }

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(k=1;k<=n;k++)
			{
				for(l=1;l<=m;l++)
				{
					Count[i][j][k][l] = Count[i][j][k-1][l]+Count[i][j][k][l-1]-Count[i][j][k-1][l-1]+Count[i][j][k][l]; 
				}
			}
		}
	}

	// for(i=1;i<=n;i++)
	// {
	// 	for(j=1;j<=m;j++)
	// 	{
	// 		printf("\n%d %d : \n", i,j );
	// 		for(k=1;k<=n;k++)
	// 		{
	// 			for(l=1;l<=m;l++)
	// 				printf("%d ", Count[i][j][k][l] );
	// 			printf("\n");
	// 		}
	// 	}
	// }

	while(q--)
	{
		sd(a);	sd(b);	sd(c);	sd(d);

		ans = 0;

		for(i=a;i<=c;i++)
		{
			for(j=b;j<=d;j++)
			{
				ans += Count[i][j][c][d];
			}
		}

		printf("%d\n", ans );

	}
	
	return 0;
}