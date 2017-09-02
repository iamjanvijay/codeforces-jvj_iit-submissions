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

// ll gcd_util(ll a, ll b)
// {
// 	if(b==0)
// 		return a;
// 	return gcd_util(b,a%b);
// }

// ll gcd(ll a, ll b)
// {
// 	if(a>=b)
// 		return gcd_util(a,b);
// 	return gcd_util(b,a);
// }

bool isPerCube(ll n)
{
	ll fs,ls,md;

	fs = 1;	ls = 1000001;
	while(fs+1<ls)
	{
		md = (fs+ls)/2;
		if(md*md*md<=n)
			fs = md;
		else
			ls = md;
	}

	if(fs*fs*fs == n || ls*ls*ls == n)
		return true;
	return false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	slld(n);

	while(n--)
	{
		slld(a);	slld(b);

		// k = gcd(a,b);

		// x = a/k;	y = b/k;

		if( ((a*a)%b==0 && isPerCube(a*a/b)) && ((b*b)%a==0 && isPerCube(b*b/a)) )
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}