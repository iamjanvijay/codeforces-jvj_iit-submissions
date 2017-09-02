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

char S[5007][5007];
int A[5007][5007];
int Count[5007];
stack<int> St;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,area=0;

	sd(n);	sd(m);

	for(i=1;i<=n;i++)
	{
		ss(S[i]+1);
	}	

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(S[i][j]==&#39;0&#39;)
				A[i][j] = 0;
			else
				A[i][j] = A[i][j-1]+1;
		}
	}

	// for(i=1;i<=n;i++)
	// {
	// 	for(j=1;j<=m;j++)
	// 	{
	// 		printf("%d ",A[i][j] );
	// 	}
	// 	printf("\n");
	// }	

	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
			Count[A[i][j]]++;
		for(i=1,l=0;l<=5000;l++)
			if(Count[l]!=0)
			{
				while(Count[l]--)
				{
					A[i++][j]=l;
				}
				Count[l]=0;
			}
	}

	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
		{
			area = max(area,(n-i+1)*A[i][j]);
		}
	}
	
	printf("%d\n",area );

	return 0;
}