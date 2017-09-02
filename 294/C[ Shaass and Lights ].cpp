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
ll Fact[1007];
ll Ways[1007];
ll InvFact[1007];
ll Space[1007];
ll In[1007];

ll Power(ll a,ll b)
{
	if(b==0)
		return 1;

	ll temp = Power(a,b/2);
	if(b%2==0)
		return (temp*temp)%Mod;
	else
		return (((temp*temp)%Mod)*a)%Mod;
}

void init()
{
	ll i;

	InvFact[0] = Fact[0] = 1;
	for(i=1;i<1007;i++)
		Fact[i] = (i*Fact[i-1])%Mod;

	for(i=1;i<1007;i++)
		InvFact[i] = (Power(i,Mod-2)*InvFact[i-1])%Mod;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l=0,m,n,x,y,z,a,b,r=0,ans=1;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	init();

	slld(n);	slld(m);

	for(i=1;i<=m;i++)
	{
		slld(In[i]);
	}

	sort(In+1,In+1+m);

	y = 1;
	for(i=1;i<=m;i++)
	{
		x = In[i];
		Space[l++] = x-y;
		y = x+1;
	}

	Space[l++] = n-y+1;

	// for(i=0;i<l;i++)
	// {
	// 	printf("** %lld\n", Space[i] );
	// }

	Ways[0] = Ways[1] = 1;
	for(i=2;i<1007;i++)
	{
		for(x=0;x<=i-1;x++)
		{
			y = i-1-x;
			Ways[i] = (Ways[i] + ((Fact[i-1] * InvFact[x])%Mod) * InvFact[y])%Mod;
		}
	}



	for(i=0;i<l;i++)
	{
		if(i==0 || i==l-1)
		{
			ans*=1;
		}
		else
		{
			ans = (ans * Ways[ Space[i] ])%Mod;
		}
	}



	for(i=0;i<l;i++)
	{
		r+=Space[i];
		ans = (ans * InvFact[Space[i]])%Mod;
		// printf("-> %lld\n", ans );
	}


	ans = (ans * Fact[r])%Mod;

	// printf("Hello\n");		

	printf("%lld\n", ans );
	
	return 0;
}