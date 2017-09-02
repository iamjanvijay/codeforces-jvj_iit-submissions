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

ll DP[5007][5007] = {0};
ll temp[5007] = {0};

int main()
{
	ll i,j,l,n,a,b,k,left,right;
	slld(n); slld(a); slld(b); slld(k);

	for(j=1;j<=n;j++)
	{
		DP[0][j] = 1;
	}

	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
			temp[j] = mod(temp[j-1] + DP[i-1][j],1000000007LL);
		for(j=1;j<=n;j++)
		{
			if(j<b)
			{
				right = b-1;
				left = max(-b+2*j+1,1LL);
				DP[i][j] = mod(mod(temp[right] - temp[left-1],1000000007LL) - DP[i-1][j],1000000007LL);
			}
			if(j>b)
			{
				left = b+1;
				right = min(n,-b-1+2*j);
				DP[i][j] = mod(mod(temp[right] - temp[left-1],1000000007LL) - DP[i-1][j],1000000007LL);
			}
		}
	}

	printf("%lld\n",DP[k][a]);	

	return 0;
}
