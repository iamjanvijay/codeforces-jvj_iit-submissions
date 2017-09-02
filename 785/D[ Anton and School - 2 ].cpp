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

char S[200007];
ll Open[200007];
ll Close[200007];
ll Fact[200007];
ll InvFact[200007];
ll Mod = 1000000007;
map< pair<int,int> , ll > M;

ll Power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll x = Power(a,b/2);
	if(b%2==0)
		return (x*x)%Mod;
	else
		return (((x*x)%Mod)*a)%Mod;
}

ll NCR(ll n,ll r)
{
	if(r>n)
		return 0;
	return ( ((Fact[n] * InvFact[r] )%Mod) * InvFact[n-r] )%Mod;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,n,ans=0;

	ss(S);
	n = strlen(S);

	Fact[0] = InvFact[0] = 1;
	for(i=1;i<=n;i++)
	{
		Fact[i] = (i*Fact[i-1])%Mod;
		InvFact[i] = (Power(i,Mod-2) * InvFact[i-1])%Mod;
	}	

	for(i=0;i<n;i++)
	{
		if(S[i]==&#39;(&#39;)
		{
			Open[i] = 1;
		}
		if(i!=0)
			Open[i] += Open[i-1];	
	}	
	
	for(i=n-1;i>=0;i--)
	{
		if(S[i]==&#39;)&#39;)
		{
			Close[i] = 1;
		}
		if(i!=n-1)
			Close[i] += Close[i+1];	
	}

	for(i=0;i<n-1;i++)
	{
		ll p = 0;
		if(S[i]==&#39;(&#39;)
		{

			p = ( p + NCR(Close[i+1]+Open[i]-1,Open[i]) )%Mod;
		}
		ans = (ans + p) %Mod;	
	}	

	printf("%lld\n", ans );

	return 0;
}