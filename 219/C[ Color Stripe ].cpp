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

char S[500007];
int DP[500007][30][2]; // DP[][][1] -> path to previous j
stack<char> Stk;

int main()
{
	int i,j,k,l,N,K,minCost1,minCost2;
	char minChar1,minChar2;

	sd(N);	sd(K);

	ss(S);

	for(i=0;i<N;i++)
	{
		if(i==0)
		{
			for(j=0;j<K;j++)
			{
				DP[i][j][0] = 1;
				DP[i][j][1] = -1;
			}

			DP[i][S[i]-&#39;A&#39;][0] = 0;

			minChar1 = S[i];
			minCost1 = 0;

			minChar2 = &#39;A&#39; + (S[i]-&#39;A&#39;+1)%K;
			minCost2 = 1;

		}
		else
		{
			for(j=0;j<K;j++)
			{
				if(j == S[i]-&#39;A&#39;)
				{
					if(minChar1-&#39;A&#39; != j)
					{
						DP[i][j][0] = minCost1;
						DP[i][j][1] = minChar1-&#39;A&#39;;
					}
					else if(minChar2-&#39;A&#39; != j)
					{
						DP[i][j][0] = minCost2;
						DP[i][j][1] = minChar2-&#39;A&#39;;
					}
				}
				else
				{
					if(minChar1-&#39;A&#39; != j)
					{
						DP[i][j][0] = minCost1+1;
						DP[i][j][1] = minChar1-&#39;A&#39;;
					}
					else if(minChar2-&#39;A&#39; != j)
					{
						DP[i][j][0] = minCost2+1;
						DP[i][j][1] = minChar2-&#39;A&#39;;
					}
				}
			}

			minChar1 = minChar2 = &#39;\0&#39;;
			minCost1 = minCost2 = INT_MAX;

			for(j=0;j<K;j++)
			{
				if(DP[i][j][0]<minCost1)
				{
					minCost2 = minCost1;
					minChar2 = minChar1;
					minCost1 = DP[i][j][0];
					minChar1 = &#39;A&#39;+j;
				}
				else if(DP[i][j][0]<minCost2)
				{
					minCost2 = DP[i][j][0];
					minChar2 = &#39;A&#39;+j;
				}
			}

		}
	}

	j = minChar1 - &#39;A&#39;;
	i = N-1;

	while(j!=-1)
	{
		Stk.push(&#39;A&#39;+j);
		j = DP[i][j][1];
		i--;
	}

	printf("%d\n",minCost1);
	while(! Stk.empty())
	{
		printf("%c",Stk.top());
		Stk.pop();
	}
	printf("\n");

	return 0;
}
