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

ll A[100007];
ll LSum[100007];
ll RSum[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,ql,qr,n,x,y,z,a,b,r;
	ll ans = LLONG_MAX;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(l);	sd(r);	sd(ql);	sd(qr);

	for(i=1;i<=n;i++)
		slld(A[i]);

	for(i=n;i>=1;i--)
	{
		RSum[n-i+1]=A[i];
	}		

	for(i=1;i<=n;i++)
	{
		LSum[i] = A[i];	LSum[i]+=LSum[i-1];	RSum[i]+=RSum[i-1];
	}

	for(i=0;i<=n;i++)
	{
		a = i;	b = n-i;

		if(abs(a-b)<=1)
		{
			ans = min(ans,LSum[a]*l+RSum[b]*r);
		}
		else if(a<b)
		{
			ans = min(ans,LSum[a]*l+RSum[b]*r+(qr*(b-(a+1))));
		}
		else
		{
			ans = min(ans,LSum[a]*l+(ql*(a-(b+1)))+RSum[b]*r);
		}	
	}

	printf("%lld\n", ans );
	
	return 0;
}