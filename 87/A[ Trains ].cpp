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

ll gcd(ll a, ll b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,jp,k,l,m,n,x,y,z,a,b,r,sca,scb;
	bool flag = false;

	slld(a);	slld(b);

	if(b<a)
	{
		flag = true;
		k = a;	a = b;	b = k;
	}

	k = gcd(a,b);
	k = a*b/k;

	sca = scb = 0;
	i = a;	j = b;	jp = 0;
	while(jp!=k)
	{
		r = (j-1)/i*i;
		sca += r - jp;
		// printf("%lld %lld\n", r, jp );
		scb += j - r;
		// printf("%lld %lld\n", j, r );
		j+=b;	jp+=b;
	}

	// printf("%lld %lld\n", sca, scb );

	if(!flag)
	{
		if( sca > scb )
			printf("Dasha\n");
		else if( scb > sca )
			printf("Masha\n");
		else
			printf("Equal\n");
	}
	else
	{
		if( sca > scb )
			printf("Masha\n");
		else if( scb > sca )
			printf("Dasha\n");
		else
			printf("Equal\n");
	}
	
	return 0;
}