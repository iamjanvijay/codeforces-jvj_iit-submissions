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

ll P[57];
ll A[7];
ll ANS[7];

ll process(ll x)
{
	int i;
	for(i=4;i>=0;i--)
	{
		ANS[ i ] += (x/A[i]);
		x%=A[i];
	}
	return x;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r,curPrz;

	slld(n);
	for(i=0;i<n;i++)
		slld(P[i]);

	for(i=0;i<5;i++)
		slld(A[i]);

	curPrz=0;	i=0;
	while(i<n)
	{
		curPrz+=P[i];
		curPrz = process(curPrz);
		i++;
	}

	for(i=0;i<5;i++)
		printf("%lld ", ANS[i] );
	printf("\n");
	printf("%lld\n", curPrz );
	
	return 0;
}