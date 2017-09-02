#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

ll PowK[1000007];

bool chk(ll t,ll b,ll m)
{
	ll sum;

	if(m==0)
	{
		sum = 1;
	}
	else
	{
		sum = 0;
		sum += (b*PowK[m-1]);
		sum += (PowK[m]-PowK[m-1]);
	}

	// printf("-> %lld %lld %lld\n", m, sum, t );
	// if(sum<0)
	// 	printf("Neg\n");

	if( t>=sum )
		return true;
	else
		return false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r,t,mid;

	slld(k);	slld(b);	slld(n);	slld(t);

	if(t==1)
	{
		printf("%lld\n", n );
		return 0;
	}

	PowK[0] = 1;
	for(i=1;PowK[i-1]<=1000000 && i<1000007;i++)
	{
		PowK[i] = k * PowK[i-1];
	}
	r = i-1;

	for(i=1;i<=r;i++)
		PowK[i] += PowK[i-1];

	// for(i=0;i<=r;i++)
	// 	printf("%lld ", PowK[i] );
	// printf("\n");
	// printf("%lld\n", r );

	l = 0;	

	while(l+1<r)
	{
		m = (l+r)/2;

		if( chk(t,b,m) )
			l = m;
		else
			r = m;
	}

	// printf("$ %lld %lld\n", l , r );

	if( chk(t,b,l) )
		printf("%lld\n", max(0LL,n-l) );
	else
		printf("%lld\n", max(0LL,n-r) );
	
	return 0;
}