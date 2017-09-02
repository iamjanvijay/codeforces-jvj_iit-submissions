#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL minm(LL X, LL Y, LL Z)
{
	return min(X,min(Y,Z));
}

struct Cuboid
{
	LL L,B,H,Ind;

	bool operator<( const Cuboid &R)
	{
		if( L != R.L )
			return (L < R.L);
		else if( B != R.B )
			return (B < R.B);
		else
			return (H < R.H);
	}

	bool operator==( const Cuboid &R )
	{
		return ( (L==R.L) && (B==R.B) );
	}

};

Cuboid A[600007] = {0};

int main()
{
	int i=1,N,L,B,H,AN=0,ANS = 1,X=1,Y=1;
	int D = 0;
	scanf("%d",&N);

	while(i<=N)
	{
		scanf("%d%d%d",&L,&B,&H);

		if( minm(L,B,H) > D )
		{
			D = minm(L,B,H);
			X = i;
		}	

		if(L==B && B==H) // all three edges are same
		{
			// printf("All edges are same.\n");
			A[AN].L = L; A[AN].B = B; A[AN].H = H; A[AN].Ind = i;
			AN++;
		}	
		else if( L!=B && L!=H && B!=H ) // all three edegs are different
		{
			// printf("All edges are different.\n");
			A[AN].L = L; A[AN].B = B; A[AN].H = H; A[AN].Ind = i;
			AN++;
			A[AN].L = L; A[AN].B = H; A[AN].H = B; A[AN].Ind = i;
			AN++;
			A[AN].L = B; A[AN].B = L; A[AN].H = H; A[AN].Ind = i;
			AN++;
			A[AN].L = B; A[AN].B = H; A[AN].H = L; A[AN].Ind = i;
			AN++;
			A[AN].L = H; A[AN].B = L; A[AN].H = B; A[AN].Ind = i;
			AN++;
			A[AN].L = H; A[AN].B = B; A[AN].H = L; A[AN].Ind = i;
			AN++;																		
		}
		else // two edges are same
		{
			// printf("Two edges same.\n");
			if(L==B)
			{
				A[AN].L = L; A[AN].B = B; A[AN].H = H; A[AN].Ind = i;
				AN++;
				A[AN].L = L; A[AN].B = H; A[AN].H = B; A[AN].Ind = i;
				AN++;
				A[AN].L = H; A[AN].B = L; A[AN].H = B; A[AN].Ind = i;
				AN++;				
			}
			else if(L==H)
			{
				A[AN].L = L; A[AN].B = B; A[AN].H = H; A[AN].Ind = i;
				AN++;
				A[AN].L = L; A[AN].B = H; A[AN].H = B; A[AN].Ind = i;
				AN++;
				A[AN].L = B; A[AN].B = H; A[AN].H = L; A[AN].Ind = i;
				AN++;				
			}	
			else
			{
				A[AN].L = L; A[AN].B = B; A[AN].H = H; A[AN].Ind = i;
				AN++;
				A[AN].L = H; A[AN].B = L; A[AN].H = B; A[AN].Ind = i;
				AN++;
				A[AN].L = B; A[AN].B = H; A[AN].H = L; A[AN].Ind = i;
				AN++;				
			}	
		}

		i++;
	}	

	sort(A,A+AN);

	i=0;	
	while( i+1<AN )
	{
		if(A[i]==A[i+1])
			i++;
		else if(i-1>=0 && A[i-1]==A[i])
		{
			if( minm( A[i].L, A[i].B, (A[i-1].H) + (A[i].H) ) > D )
			{
				ANS = 2;
				D = minm( A[i].L, A[i].B, (A[i-1].H) + (A[i].H) );
				X = A[i].Ind;
				Y = A[i-1].Ind;
			}
			i++;
		}
		else 
			i++;	
	}

	if( i-1>=0 && A[i-1]==A[i] && minm( A[i].L, A[i].B, (A[i-1].H) + (A[i].H) ) > D )
	{
		ANS = 2;
		D = minm( A[i].L, A[i].B, (A[i-1].H) + (A[i].H) );
		X = A[i].Ind;
		Y = A[i-1].Ind;
	}

	if(ANS==1)
	{
		printf("%d\n%d\n", ANS, X );
	}
	else
	{
		printf("%d\n%d %d\n", ANS, X, Y);
	}	

	return 0;
}