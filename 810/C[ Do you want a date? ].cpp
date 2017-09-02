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

ll Mod = 1000000007;
ll A[300007];
ll Pow2[300007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r,Inv2 = 500000004;

	Pow2[0] = 1;
	for(i=1;i<300007;i++)
		Pow2[i] = (2*Pow2[i-1])%Mod;

	for(i=1;i<300007;i++)
		Pow2[i] = (Pow2[i-1]+Pow2[i])%Mod;

	slld(n);

	for(i=0;i<n;i++)
		slld(A[i]);

	sort(A,A+n);

	l = -1;	r = n-2;
	a = 0;

	for(i=0;i<n;i++,l++,r--)
	{
		if(r>=0)
			a = (a - (Pow2[r]*A[i])%Mod + Mod)%Mod;
		if(l>=0)
			a = (a + (Pow2[l]*A[i])%Mod + Mod)%Mod;
	}

	printf("%lld\n", a );
	
	return 0;
}