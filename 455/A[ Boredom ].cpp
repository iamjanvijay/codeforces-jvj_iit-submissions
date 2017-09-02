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

ll DP[100007];
ll A[100007];
ll B[100007];

ll ans(int cur,int n)
{
	if(cur > n-1)
		return 0;


	if(DP[cur]==0)
	{
		if(B[cur]+1 != B[cur+1])
			DP[cur] = (ll)A[ B[cur] ] * B[cur] + ans(cur+1,n);
		else
			DP[cur] = max( (ll)A[ B[cur] ] * B[cur] + ans(cur+2,n) , ans(cur+1,n) );
	}

	return DP[cur];	

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n;

	slld(n);

	for(i=0;i<n;i++)
	{
		slld(k);
		A[k]++;
	}

	n=0;
	for(i=1;i<=100000;i++)
	{
		if(A[i]!=0)
			B[n++] = i;
	}


	printf("%lld\n", ans(0,n) );
	
	return 0;
}