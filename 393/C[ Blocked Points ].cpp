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


int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r;
	double temp;

	slld(n);

	if(n==0)
	{
		printf("1\n");
		return 0;
	}

	x = n;	y = 0;	a = 0;

	for(i=1;i<=n;i++)
	{
		y = (ll) sqrt( n*n - i*i ) ;
		if(i==1)
			a += 2*max(1LL, (x-y));
		else
			a += 4*max(1LL, (x-y));
		x = y;
	}
	
	printf("%lld\n", a+2 );

	return 0;
}