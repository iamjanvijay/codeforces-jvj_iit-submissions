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

vector<ll> X;
vector<ll>::iterator it;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a,b,d,r;
	ll ans = 0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);	slld(d);
	for(i=0;i<n;i++)
	{
		slld(k);

		it = lower_bound(X.begin(),X.end(),k-d);
		l = X.end() - it;
		ans += (l*(l-1)/2);

		X.push_back(k);
	}

	printf("%lld\n", ans );

	return 0;
}