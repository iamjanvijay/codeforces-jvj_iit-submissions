#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n 

ll Fact[1000007];
ll InvFact[1000007];
bool isGood[10000007];
queue<int> Q;

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll x = power(a,b/2);
	if(b%2==0)
		return (x*x)%1000000007;
	else
		return (((x*x)%1000000007)*a)%1000000007;
}

int main()
{
	int a,b,i,j,k,l,m,n;
	ll ans=0;

	Fact[0] = 1;
	for(i=1;i<1000007;i++)
		Fact[i] = (Fact[i-1] * i)%1000000007;

	InvFact[0] = 1;
	for(i=1;i<1000007;i++)
		InvFact[i] = (InvFact[i-1] * power(i,1000000007-2))%1000000007;

	sd(a);	sd(b);	sd(n);

	Q.push(a);	Q.push(b);

	while(!Q.empty())
	{
		k = Q.front();	Q.pop();

		isGood[k] = true;

		if(k*10+a<10000007)
			Q.push(k*10+a);
		if(k*10+b<10000007)
			Q.push(k*10+b);
	}

	for(i=0;i<=n;i++)
	{
		if( isGood[a*i + b*(n-i)] )
			ans = ( ans + (((Fact[n]*InvFact[i])%1000000007)*InvFact[n-i])%1000000007 )%1000000007 ;
	}	

	printf("%lld\n", ans );

	return 0;
}
