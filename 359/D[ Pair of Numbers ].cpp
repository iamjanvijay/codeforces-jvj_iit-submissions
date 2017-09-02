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

int SparseTable[300007][20];
int A[300007];
int LargestPow2[300007];
int Right[300007];
int Left[300007];
set<int> S;
int gcdutil(int a,int b) // a>b
{
	if(b==0)
		return a;
	return gcdutil(b,a%b);
}

int gcd(int a,int b)
{
	if(a>b)
		return gcdutil(a,b);
	return gcdutil(b,a);
}

void initST(int N)
{
	int i,j,k;

	for(i=1,j=0;i<300007;i++)
	{
		if( (1<<(j+1)) <= i )
			j++;
		LargestPow2[i] = j;
	}

	for(i=0;(1<<i)<=N;i++)
	{
		for(j=0;(j+(1<<i)-1)<N;j++)
		{
			if(i==0)
			{
				SparseTable[j][i] = A[j];
			}
			else
			{
				SparseTable[j][i] = gcd( SparseTable[j][i-1], SparseTable[j+(1<<(i-1))][i-1]);
			}

		}
	}
}

int queryST(int i,int j)
{
	int N = j-i+1;
	int K = LargestPow2[N];

	return gcd( SparseTable[i][K] , SparseTable[j-(1<<K)+1][K] );
}

void initLeft(int N)
{
	Left[0] = 0;
	int i,j,first,last,mid;
	for(i=1;i<N;i++)
	{
		first = 0; last = i;
		while(first + 1 < last)
		{
			mid = (first+last)/2;
			if(queryST(mid,i)==A[i])
			{
				last = mid;
			}
			else
			{
				first = mid+1;
			}
		}
		if( queryST(first,i)==A[i] )
			Left[i] = first;
		else
			Left[i] = last;
	}
}

void initRight(int N)
{
	Right[N-1] = N-1;
	int i,j,first,last,mid;
	for(i=0;i<N-1;i++)
	{
		first = i; last = N-1;
		while(first + 1 < last)
		{
			mid = (first+last)/2;
			if(queryST(i,mid)==A[i])
			{
				first = mid;
			}
			else
			{
				last = mid-1;
			}
		}
		if( queryST(i,last)==A[i] )
			Right[i] = last;
		else
			Right[i] = first;
	}
}

int main()
{
	int i,N,maxi = 0;
	sd(N);

	for(i=0;i<N;i++)
		sd(A[i]);

	if(N==1)
	{
		printf("1 0\n");
		printf("1\n");
		return 0;
	}

	initST(N);
	initLeft(N);
	initRight(N);

	for(i=0;i<N;i++)
	{
		if( maxi < Right[i] - Left[i])
		{
			maxi = Right[i] - Left[i];
		}
	}


	for(i=0;i<N;i++)
	{
		if( maxi == Right[i] - Left[i])
		{
			S.insert(Left[i]+1);
		}
	}
	printf("%d %d\n",S.size(),maxi );

	set<int>::iterator it;
	for(it = S.begin();it!=S.end();++it)
		printf("%d ",*it);

	printf("\n");

	return 0;
}
