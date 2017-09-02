#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main()
{
	int Rows[105] = {0};
	int Cols[105] = {0};
	int isRows[105] = {0};
	int isCols[105] = {0};	
	int B[105][105] = {0};
	int A[105][105] = {0};
	int RowsN = 0, ColsN = 0;
	int ORcalc,ANDcalc,i,j,M,N;

	scanf("%d%d",&M,&N);

	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&(B[i][j]));
		}	
	}	

	for(i=1;i<=M;i++)
	{
		ORcalc = 0; ANDcalc = 1;
		for(j=1;j<=N;j++)
		{
			ORcalc |= B[i][j];
			ANDcalc &= B[i][j];
		}
		if( ORcalc == 1 && ANDcalc == 1 )	
		{
			Rows[RowsN++] = i;
			isRows[i] = 1;	
		}
	}

	for(j=1;j<=N;j++)
	{
		ORcalc = 0; ANDcalc = 1;
		for(i=1;i<=M;i++)
		{
			ORcalc |= B[i][j];
			ANDcalc &= B[i][j];	
		}
		if( ORcalc == 1 && ANDcalc == 1 )	
		{
			Cols[ColsN++] = j;
			isCols[j] = 1;
		}			
	}

	if( (ColsN!=0 && RowsN==0) || (ColsN==0 && RowsN!=0) )
	{
		printf("NO\n");
		return 0;
	}

	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			if( B[i][j] == 1 && (isRows[i]|isCols[j]) == 0 )
			{
				printf("NO\n");
				return 0;
			}	
		}	
	}	

	for(i=0;i<RowsN;i++)
	{
		for(j=0;j<ColsN;j++)
		{
			A[Rows[i]][Cols[j]] = 1;
		}	
	}

	printf("YES\n");	

	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			printf("%d ", A[i][j] );
		}
		printf("\n");	
	}	

	return 0;
}