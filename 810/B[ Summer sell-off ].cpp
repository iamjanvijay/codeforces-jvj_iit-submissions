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

ll K[100007];
ll L[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a,b,r,f;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	a = 0;

	slld(n);	slld(f);

	for(i=0;i<n;i++)
	{
		slld(K[i]);	slld(L[i]);
	}

	for(i=0;i<n;i++)
	{
		a += min(K[i],L[i]);
		if( L[i] > K[i] )
		{
			L[i] = L[i] - K[i];
			L[i] = min(L[i],K[i]);
		}
		else
		{
			L[i] = 0;
		}

	}

	sort(L,L+n,greater<ll>());

	for(i=0;i<f;i++)
	{
		a += L[i];
	}

	printf("%lld\n",a);
	
	return 0;
}