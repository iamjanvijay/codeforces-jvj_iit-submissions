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

int A[507];
bool DP[507][507][507] = {false};

int main()
{
	int i,Sum,SubsetSum,N,K;
	vector<int> v;

	sd(N);	sd(K);

	for(i=1;i<=N;i++)
		sd(A[i]);

	for(i=0;i<=N;i++)
		DP[i][0][0] = true;

	for(i=1;i<=N;i++)
	{
		for(Sum = 0; Sum<=K; Sum++)
		{
			for(SubsetSum = 0;SubsetSum<=Sum;SubsetSum++)
			{
				DP[i][Sum][SubsetSum] |= DP[i-1][Sum][SubsetSum];
				if( Sum-A[i] >= 0 )
				{
					DP[i][Sum][SubsetSum] |= DP[i-1][Sum-A[i]][SubsetSum];
				}
				if( Sum-A[i] >= 0 && SubsetSum-A[i] >= 0 )
				{
					DP[i][Sum][SubsetSum] |= DP[i-1][Sum-A[i]][SubsetSum-A[i]];	
				}
			}
		}	
	}	

	for(SubsetSum=0;SubsetSum<=K;SubsetSum++)
	{
		if(DP[N][K][SubsetSum])
		{
			v.push_back(SubsetSum);
		}
	}

	printf("%lu\n", v.size() );

	for(i=0;i<v.size();i++)
		printf("%d ",v[i] );
	printf("\n");

	return 0;
}
