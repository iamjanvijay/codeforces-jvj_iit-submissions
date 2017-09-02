#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL A[100007], B[100007];

LL Cost(LL M, LL N, LL K)
{
	LL i,cost = 0;

	for(i=0;i<M;i++)
	{
		if(A[i] < K)
			cost += (K-A[i]);
		else
			break;
	}

	for(i=N-1;i>=0;i--)
	{
		if(B[i] > K)
			cost += (B[i]-K);
		else
			break;
	}

	return cost;

}

LL minCost(LL mini, LL maxi,LL M,LL N) // min = A[0] | max = B[N-1]
{

	LL i,mid1,mid2,costm1,costm2;

	while( maxi-mini+1 > 5 )
	{
		mid1 = mini + (maxi-mini)/3; mid2 = mini + 2*(maxi-mini)/3;
		costm1 = Cost(M,N,mid1); costm2 = Cost(M,N,mid2);

		if( costm1 < costm2 )
			maxi = mid2;
		else
			mini = mid1;
	}

	costm1 = LLONG_MAX;

	for(i=mini;i<=maxi;i++)
	{
		costm2 = Cost(M,N,i);
		if(costm2 < costm1)
			costm1 = costm2;
	}
	return costm1;
}

int main()
{
	LL i,M,N;
	scanf("%lld%lld",&M,&N);

	for(i=0;i<M;i++)
	{
		scanf("%lld",&(A[i]));
	}

	for(i=0;i<N;i++)
	{
		scanf("%lld",&(B[i]));
	}

	sort(A, A+M);
	sort(B, B+N);

	if( A[0] >= B[N-1] )
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n", minCost(A[0],B[N-1],M,N));
	}


	return 0;
}
