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

ll A[207];
int Pow2[207]={0};
int Pow5[207]={0};

int DP[2][207][6000];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	int i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	for(i=1;i<=n;i++)
	{
		slld(A[i]);
	}

	for(i=1;i<=n;i++)
	{
		while(A[i]%2==0)
		{
			A[i]/=2;
			Pow2[i]++;
		}
		while(A[i]%5==0)
		{
			A[i]/=5;
			Pow5[i]++;
		}		
	}
	
	// printf("Hey\n");

	for(i=0;i<=n;i++)
	{
		for(l=0;l<=min(i,k);l++)
		{
			for(j=0;j<6000;j++)
			{
				if(i==0 && l==0)
				{
					if(j==0)
						DP[i%2][l][j] = 0;
					else
						DP[i%2][l][j] = INT_MIN;
				}
				else
				{
					DP[i%2][l][j] = INT_MIN;
					if(i-1>=l && i-1>=0 && DP[(i+1)%2][l][j]!=INT_MIN)
						DP[i%2][l][j] = max( DP[i%2][l][j] , DP[(i+1)%2][l][j] );
					if(j-Pow5[i]>=0 && i-1>=0 && l-1>=0 && i-1>=l-1 && DP[(i+1)%2][l-1][j-Pow5[i]]!=INT_MIN)
						DP[i%2][l][j] = max( DP[i%2][l][j] , DP[(i+1)%2][l-1][j-Pow5[i]] + Pow2[i] );
				}
			}
		}
	}

	// printf("Hey\n");

	a = 0;
	for(j=0;j<6000;j++)
	{
		a = max(a, min(DP[n%2][k][j],j));
	}

	printf("%d\n", a );

	return 0;
}