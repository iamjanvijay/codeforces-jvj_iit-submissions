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

ll A[200007];
ll Count[200007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x=0,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);	slld(k);
	for(i=1;i<=n;i++)
		slld(A[i]);

	for(i=1;(i+k-1)<=n;i++)
	{
		Count[i] += 1;
		Count[i+k] -= 1;
	}
	
	for(i=1;i<=n;i++)
		Count[i] += Count[i-1];

	for(i=1;i<=n;i++)
	{
		x += (Count[i]*A[i]);
	}

	printf("%0.10lf\n", (double)x/(n-k+1)  );

	return 0;
}