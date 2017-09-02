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

priority_queue< ll,vector<ll>,less<ll> > PrR;
priority_queue< ll,vector<ll>,less<ll> > PrC;
ll M[1007][1007];
ll RMAX[1000007];
ll CMAX[1000007];
ll temp = 0,temp1;
ll ans = LLONG_MIN;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a,b,r,p;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);	slld(m);	slld(k);	slld(p);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			slld(M[i][j]);
		}
	}

	for(i=0;i<n;i++)
	{
		temp = 0;
		for(j=0;j<m;j++)
		{
			temp+=M[i][j];
		}
		PrR.push(temp);
		// printf("%lld  ", temp );
	}
	// printf("\n");

	for(i=0;i<m;i++)
	{
		temp = 0;
		for(j=0;j<n;j++)
		{
			temp+=M[j][i];
		}
		PrC.push(temp);
	}

	temp = 0;
	for(i=1;i<=k;i++) // row
	{
		temp1 = PrR.top();	PrR.pop();
		temp += temp1;
		RMAX[i] = temp;
		// printf("%lld ", temp );
		PrR.push(temp1 - m*p);
	}
	// printf("\n");

	temp = 0;
	for(i=1;i<=k;i++) // col
	{
		temp1 = PrC.top();	PrC.pop();
		temp += temp1;
		CMAX[i] = temp;
		// printf("%lld ", temp );		
		PrC.push(temp1 - n*p);
	}	
	// printf("\n");

	for(i=0;i<=k;i++)	// operations from rows
	{
		// printf("Hello\n");
		j = k-i;
		ans = max(ans,RMAX[i]+CMAX[j]-j*i*p);
	}	
	
	printf("%lld\n", ans );

	return 0;
}