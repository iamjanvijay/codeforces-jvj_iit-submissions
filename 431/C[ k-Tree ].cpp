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

ll Mod = 1000000007;
ll DP[107][107][7];
bool isCalc[107][107][7];
ll k,d;

ll ans(int level,int sum,bool dCapt)
{
	if((sum<0) || (sum==0 && !dCapt))
		return 0;
	if(sum==0 && dCapt)
		return 1;
	if( !isCalc[level][sum][(int)dCapt] )
	{	
		int i;
		for(i=1;i<=k;i++)
		{
			DP[level][sum][(int)dCapt] = ( DP[level][sum][(int)dCapt] + ans(level+1,sum-i,(dCapt) | (i>=d) ) )%Mod;
		}
		isCalc[level][sum][(int)dCapt] = true;	
	}
	return DP[level][sum][(int)dCapt];
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,l,n;

	slld(n);	slld(k);	slld(d);

	printf("%lld\n", ans(0,n,false) );
	
	return 0;
}