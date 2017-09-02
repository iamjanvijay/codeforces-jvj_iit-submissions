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

vector<int> factors[2007];
ll DP[2007][2007];

void init()
{
	int i,j;

	factors[1].push_back(1);

	for(i=2;i<=2000;i++)
	{
		for(j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				if(j*j==i)
					factors[i].push_back(j);
				else
				{
					factors[i].push_back(j);
					factors[i].push_back(i/j);
				}
			}	
		}	
	}

}

int main()
{
	init();

	ll i,j,n,k,l,ans=0;
	slld(n);	slld(k);

	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==1)
				DP[i][j] = 1;
			else
			{
				for(l=0;l < factors[j].size();l++)
				{
					DP[i][j] = (DP[i][j] + DP[i-1][factors[j][l]])%(1000000007);
				}	
			}
		}
	}

	for(i=1;i<=n;i++)
	{
		ans = (ans + DP[k][i])%(1000000007);
	}

	printf("%lld\n", ans );	

	return 0;
}
