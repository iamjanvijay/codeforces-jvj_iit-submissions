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

ll One[100007];
ll Two[100007];
ll Three[100007];

ll Even[200007];
ll Odd[200007];
ll Max[200007];
ll n1,n2,n3,ne,no,fne,fno;

ll maxCost(ll w)
{
	if(w%2==0)
	{
		if(w<=2*ne)
		{
			return Even[w/2];
		}
		else
		{
			return Even[ne]+((n1%2==1)?(One[n1]):(0));
		}
	}
	else
	{
		if((w-1)<=2*no)
		{
			// printf("Returning : %lld\n", One[1] + Odd[(w-1)/2] );
			return One[1] + Odd[(w-1)/2];
		}
		else
		{
			return One[1]+Odd[no]+((n1%2==0)?(One[n1]):(0));
		}
	}
}

ll Query(ll w)
{
	if(w>200007)
		return Max[200006];
	return Max[w];
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,w,x=0,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);	slld(m);	ne=no=n1=n2=n3=0;

	for(i=1;i<=n;i++)
	{
		slld(w);	slld(c);

		if(w==1)
		{
			One[++n1] = c;
		}
		else if(w==2)
		{
			Two[++n2] = c;
		}
		else
		{
			Three[++n3] = c;
		}
	}

	// if(n==1000)
	// printf("***%lld %lld %lld\n", n1, n2, n3 );

	sort(One+1,One+n1+1,greater<ll>());
	sort(Two+1,Two+n2+1,greater<ll>());
	sort(Three+1,Three+n3+1,greater<ll>());

	for(i=1;i<=n2;i++)
	{
		Even[++ne] = Two[i];
	}

	for(i=1;i+1<=n1;i+=2)
	{
		Even[++ne] = One[i]+One[i+1];
	}

	sort(Even+1,Even+ne+1,greater<ll>());

	for(i=1;i<=ne;i++)
		Even[i] += Even[i-1];

	for(i=1;i<=n2;i++)
	{
		Odd[++no] = Two[i];
	}

	for(i=2;i+1<=n1;i+=2)
	{
		Odd[++no] = One[i]+One[i+1];
	}

	sort(Odd+1,Odd+no+1,greater<ll>());

	for(i=1;i<=no;i++)
		Odd[i] += Odd[i-1];

	for(i=1;i<=n3;i++)
		Three[i] += Three[i-1];	

	// printf("***%lld\n", Max[1] );

	for(i=1;i<200007;i++)
	{
		Max[i] = max(maxCost(i),Max[i-1]);
	}

	// for(i=0;i<=4;i++)
	// 	printf("%lld ", Max[i] );
	// printf("\n");

	for(i=0;i<=n3;i++)
	{
		if(m-3*i<0)
			break;
		k = Three[i]+Query(m-3*i);
		x = max(x,k);
	}

	printf("%lld\n", x );

	return 0;
}