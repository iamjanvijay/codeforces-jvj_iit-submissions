#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL A[2005][2005] = {0};
LL M1[2005][2005] = {0};
LL M2[2005][2005] = {0};

int main()
{
	int i,j,X,Y,N;
	LL sum,max1,max2;
	int X1,Y1,X2,Y2;
	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%lld",&(A[i][j]));
		}	
	}

	for(j=1;j<=N;j++)
	{
		sum = 0;
		for(Y=j,X=1;X<=N && Y<=N;X++,Y++)
		{
			sum += A[X][Y];
		}

		for(Y=j,X=1;X<=N && Y<=N;X++,Y++)
		{
			M1[X][Y] = sum;
		}	
	}

	for(i=1;i<=N;i++)
	{
		sum = 0;
		for(Y=1,X=i;X<=N && Y<=N;X++,Y++)
		{
			sum += A[X][Y];
		}

		for(Y=1,X=i;X<=N && Y<=N;X++,Y++)
		{
			M1[X][Y] = sum;
		}	
	}

	for(j=1;j<=N;j++)
	{
		sum = 0;
		for(Y=j,X=1;X<=N && Y>=1;X++,Y--)
		{
			sum += A[X][Y];
		}

		for(Y=j,X=1;X<=N && Y>=1;X++,Y--)
		{
			M2[X][Y] = sum;
		}	
	}

	for(i=1;i<=N;i++)
	{
		sum = 0;
		for(Y=N,X=i;X<=N && Y>=1;X++,Y--)
		{
			sum += A[X][Y];
		}

		for(Y=N,X=i;X<=N && Y>=1;X++,Y--)
		{
			M2[X][Y] = sum;
		}	
	}

	// for(i=1;i<=N;i++)
	// {
	// 	for(j=1;j<=N;j++)
	// 	{
	// 		printf("%lld ",(M1[i][j]));
	// 	}
	// 	printf("\n");	
	// }					

	// printf("\n");

	// for(i=1;i<=N;i++)
	// {
	// 	for(j=1;j<=N;j++)
	// 	{
	// 		printf("%lld ",(M2[i][j]));
	// 	}
	// 	printf("\n");	
	// }

	max2 = max1 = 0;
	X1 = Y1 = X2 = Y2 = 1;
	X2++;
	sum = 0;

	for(j=1;j<=N;j++)
	{

		for(Y=j,X=1;X<=N && Y<=N;X++,Y++)
		{
			if(j%2) // max1
			{
				if( max1 < M1[X][Y] + M2[X][Y] - A[X][Y] )
				{
					max1 = M1[X][Y] + M2[X][Y] - A[X][Y];
					X1 = X;
					Y1 = Y;
				}
			}
			else
			{
				if( max2 < M1[X][Y] + M2[X][Y] - A[X][Y] )
				{
					max2 = M1[X][Y] + M2[X][Y] - A[X][Y];
					X2 = X;
					Y2 = Y;
				}
			}	
		}
	}

	for(i=1;i<=N;i++)
	{

		for(Y=1,X=i;X<=N && Y<=N;X++,Y++)
		{
			if(i%2) // max1
			{
				if( max1 < M1[X][Y] + M2[X][Y] - A[X][Y] )
				{
					max1 = M1[X][Y] + M2[X][Y] - A[X][Y];
					X1 = X;
					Y1 = Y;
				}
			}
			else
			{
				if( max2 < M1[X][Y] + M2[X][Y] - A[X][Y] )
				{
					max2 = M1[X][Y] + M2[X][Y] - A[X][Y];
					X2 = X;
					Y2 = Y;
				}
			}	
		}

	}	

	printf("%lld\n%d %d % d %d\n",max1+max2,X1,Y1,X2,Y2);

	return 0;
}