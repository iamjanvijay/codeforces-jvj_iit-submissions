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


ll GCD(ll a,ll b)
{
	if(a==0)
		return b;
	return GCD(b%a,a);
}

ll LCM(ll a,ll b)
{
	return a*b/GCD(min(a,b),max(a,b));
}

ll A[19];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);

	a = 1;

	if(n<=3)
	{
		for(i=n;i>=1;i--)
			a*=i;
		printf("%lld\n", a );
		return 0;
	}

	l = 0;
	for(i=n;i>=1 && l<17;i--)
		A[l++] = i;

	// printf("%lld\n", l );

	for(i=0;i<l;i++)
	{
		for(j=i;j<l;j++)
		{
			for(k=j;k<l;k++)
			{
				// printf("*** %lld\n", LCM(A[k],LCM(A[i],A[j])) );
				a = max(a , LCM(A[k],LCM(A[i],A[j])) );
			}
		}
	}

	printf("%lld\n", a );

	return 0;
}