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

ll P[5007];
ll DP[5007][5007];
bool isCalc[5007][5007];

int m;

ll Sum(int l,int r)
{
	return P[r] - P[l-1];
}

ll ans(int n, int k)
{
	if(n<=0 && k!=0)
		return LLONG_MIN;

	if(!isCalc[n][k])
	{
		ll call1,call2;
		if(k==0)
			DP[n][k] = 0;	
		else if(n < m*k)
			DP[n][k] = LLONG_MIN;
		else
		{
			call1 = ans(n-m,k-1);
			call2 = ans(n-1,k );
			if(call1==LLONG_MIN && call2==LLONG_MIN)
				DP[n][k] = LLONG_MIN;//max( call2, Sum(n-m+1,n) + call1 );
			else if(call2!=LLONG_MIN && call1!=LLONG_MIN)
				DP[n][k] = max( call2, Sum(n-m+1,n) + call1 );
			else if(call2==LLONG_MIN && call1!=LLONG_MIN)
				DP[n][k] = Sum(n-m+1,n) + call1;
			else
				DP[n][k] = call2;
		}
	}	
	isCalc[n][k] = true;
	return DP[n][k];
// 	if(k==0)
// 		return 0;

// 	int i,j;	ll t,p=LLONG_MIN;

// 	if(DP[n][k]==0)
// 	{
// 		for(i=n;i>=0;i--)
// 		{
// 			if(i >= m*k)
// 			{
// 				t = ans(i-m,k-1);
// 				if(t!=LLONG_MIN)
// 					if( p < Sum(i-m+1,i) + t )
// 					{
// 						p = Sum(i-m+1,i) + t;
// 					}
// 			}
// 		}
// 		DP[n][k] = p;
// 	}

// 	return 	DP[n][k];
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,n;
	
	sd(n);	sd(m);	sd(k);

	for(i=1;i<=n;i++)
		slld(P[i]);

	for(i=1;i<=n;i++)
		P[i] += P[i-1];
		
	ans(n,k);
	
	printf("%lld\n",DP[n][k]);

	return 0;
}