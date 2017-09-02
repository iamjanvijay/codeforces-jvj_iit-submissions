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

ll A[1000000];

ll ind(ll x)
{
	return x + 500000;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);	slld(x);	slld(m);	slld(y);

	if(x==y)
	{
		printf("%lld\n", 1 + max(n, m) );
	}
	else
	{
		a = 0;
		for(i=1;i<=n;i++)
		{
			A[ ind(x-i) ]++;
			A[ ind(x+i) ]--;
			if( !(y-m<=x-i && x+i<=y+m) )
			{
				a++;
				// printf("-> %d %d\n", x-i, x+i);
			}
		}
		for(i=1;i<1000000;i++)
			A[i] += A[i-1];
		for(i=1;i<=m;i++)
		{
			k = A[ ind(y+i) - 1 ] - A[ ind(y-i) ];
			if(abs(k)>0)
				a+=2*abs(k);
			else
				a++;
		}
		printf("%lld\n", a + 1 );
	}
	
	return 0;
}