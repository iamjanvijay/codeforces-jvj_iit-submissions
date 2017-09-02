#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Edge
{
	int u;
	int v;
	int t;
};

Edge E[5007];

int DP[5007][5007];
int Path[5007][5007];
int Ans[5007];
int i,j;

void dp_init(int N)
{
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			DP[i][j] = INT_MAX;
			Path[i][j] = -1;
		}	
	}

	DP[1][1] = 0;

}

void calc(int N,int M,int T)
{
	for(i=2;i<=N;i++)
	{
		for(j=0;j<M;j++)
		{
			if( DP[E[j].u][i-1]!=INT_MAX && DP[E[j].u][i-1] + E[j].t < DP[E[j].v][i] && DP[E[j].u][i-1] + E[j].t <= T)
			{
				DP[E[j].v][i] = DP[E[j].u][i-1] + E[j].t ;
				Path[E[j].v][i] = E[j].u;
			}	
		}	
	}	
}

int main()
{
	int N,M,T;
	scanf("%d%d%d",&N,&M,&T);

	for(i=0;i<M;i++)
	{
		scanf("%d%d%d",&(E[i].u),&(E[i].v),&(E[i].t));
	}	

	dp_init(N);

	calc(N,M,T);

	int K=0;

	for(i=1;i<=N;i++)
	{
		if(DP[N][i]<=T)
		{
			K = max(K,i);
		}	
	}

	printf("%d\n",K);

	int curr = N;
	int Z = K;

	while(curr!=-1)
	{
		Ans[K] = curr;
		//cout << Ans[K] << "*" <<endl;
		curr = Path[curr][K];
		K--;
	}

	for(i=1;i<=Z;i++)
	{
		printf("%d ",Ans[i]);
	}
	printf("\n");
	return 0;
}