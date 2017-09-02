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

vector<ll> A[2];
vector<ll> T;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k=0,l,m,n,x,y,z,a,b,r;

	A[0].pb(4);	A[0].pb(7);	k=0;

	for(i=1;i<=10;i++)
	{
		for(j=0;j<sz(A[k]);j++)
		{
			T.pb(A[k][j]);
		}

		for(j=0;j<sz(A[k]);j++)
		{
			A[1-k].pb( A[k][j]*10LL+4 );	A[1-k].pb( A[k][j]*10LL+7 );
		}

		A[k].clear();
		k = 1-k;	
	}

	slld(l);	slld(r);

	for(i=0;i<2046;i++)
	{
		if(T[i]>=l)
			break;
	}

	if(T[i]>=r)
	{
		printf("%lld\n", (r-l+1)*T[i] );
		return 0;
	}
	else
	{
		for(j=0;j<2046;j++)
		{
			if(T[j]>=r)
				break;
		}

		a = (T[i]-l+1)*T[i];

		for(k=i+1;k<j;k++)
			a += (T[k]-T[k-1])*T[k];

		a += (r-T[j-1])*T[j];

		printf("%lld\n", a );
		return 0;
	}
	
	return 0;
}