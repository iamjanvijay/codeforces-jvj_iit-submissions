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

ll delAmount(ll k, ll n)
{
	ll a=0, i;
	for(i=1;i<=n;i++)
		a += min(k, A[i]);
	return a;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r,fs,ls,md;

	slld(n);	slld(k);

	for(a=0,i=1;i<=n;i++)
	{
		slld(A[i]);
		a += A[i];
	}

	if(k==0)
	{
		for(i=1;i<=n;i++)
			if(A[i]>0)
				printf("%d ", i );
		printf("\n");	
		return 0;
	}

	if(a<k)
	{
		printf("-1\n");
		return 0;
	}

	if(a==k)
	{
		printf("\n");
		return 0;
	}	

	fs = 0;		ls = 1000000001LL;

	while(fs+1<ls)
	{
		md = (fs+ls)/2;

		b = delAmount(md, n);
		if( b < k )
			fs = md;
		else
			ls = md;

	}

	b = delAmount(fs, n);
	k -= b;

	for(i=1;i<=n;i++)
	{
		A[i] -= min(A[i], fs);
	}

	i = 1;
	while(k>0)
	{
		if(A[i]>0)
		{
			A[i]--;
			k--;
		}
		i++;
	}

	for(j=i;j<=n;j++)
		if(A[j]>0)
			printf("%d ", j );
	for(j=1;j<i;j++)
		if(A[j]>0)
			printf("%d ", j );		
	printf("\n");		
	
	return 0;
}