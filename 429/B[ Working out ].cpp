#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

int A[1007][1007];

int DownLeft[1007][1007];
int UpRight[1007][1007];
int DowRight[1007][1007];
int UpLeft[1007][1007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			sd(A[i][j]);
		}
	}	

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i==0 && j==0)
				DowRight[i][j] = A[i][j];
			else if(i==0)
				DowRight[i][j] = A[i][j] + DowRight[i][j-1];
			else if(j==0)
				DowRight[i][j] = A[i][j] + DowRight[i-1][j];
			else
				DowRight[i][j] = A[i][j] + max(DowRight[i-1][j],DowRight[i][j-1]);
		}
	}

	// printf("\n");
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<m;j++)
	// 	{
	// 		printf("%d ", DowRight[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<m;j++)
		{
			if(i==n-1 && j==0)
				UpRight[i][j] = A[i][j];
			else if(i==n-1)
				UpRight[i][j] = A[i][j] + UpRight[i][j-1];
			else if(j==0)
				UpRight[i][j] = A[i][j] + UpRight[i+1][j];
			else
				UpRight[i][j] = A[i][j] + max(UpRight[i][j-1],UpRight[i+1][j]);
		}
	}

	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<m;j++)
	// 	{
	// 		printf("%d ", UpRight[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");	

	for(i=0;i<n;i++)
	{
		for(j=m-1;j>=0;j--)
		{
			if(i==0 && j==m-1)
				DownLeft[i][j] = A[i][j];
			else if(i==0)
				DownLeft[i][j] = A[i][j] + DownLeft[i][j+1];
			else if(j==m-1)
				DownLeft[i][j] = A[i][j] + DownLeft[i-1][j];
			else
				DownLeft[i][j] = A[i][j] + max(DownLeft[i][j+1],DownLeft[i-1][j]);
		}
	}	

	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<m;j++)
	// 	{
	// 		printf("%d ", DownLeft[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");		

	for(i=n-1;i>=0;i--)
	{
		for(j=m-1;j>=0;j--)
		{
			if(i==n-1 && j==m-1)
				UpLeft[i][j] = A[i][j];
			else if(i==n-1)
				UpLeft[i][j] = A[i][j] + UpLeft[i][j+1];
			else if(j==m-1)
				UpLeft[i][j] = A[i][j] + UpLeft[i+1][j];
			else
				UpLeft[i][j] = A[i][j] + max(UpLeft[i][j+1],UpLeft[i+1][j]);
		}
	}

	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<m;j++)
	// 	{
	// 		printf("%d ", UpLeft[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");	

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(j-1>=0 && j+1<m && i-1>=0 && i+1<n)
				a = max(a,DowRight[i][j-1]+UpLeft[i][j+1]+DownLeft[i-1][j]+UpRight[i+1][j]);

			if(j-1>=0 && j+1<m && i-1>=0 && i+1<n)
				a = max(a,DowRight[i-1][j]+UpLeft[i+1][j]+DownLeft[i][j+1]+UpRight[i][j-1]);
			// b = a;
			// a = max( a , DowRight[i][j]+UpLeft[i][j]-2*A[i][j] + DownLeft[i][j]+UpRight[i][j]-2*A[i][j] );
			// if(a != b)
			// {
			// 	x=i;	y=j;
			// }
		}
	}

	// printf("-> %d %d\n", x, y );

	printf("%d\n", a );

	return 0;
}