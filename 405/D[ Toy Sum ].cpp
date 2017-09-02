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

long long A[500007];
bool isInc[1000007];
vector<long long> ans;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r,tot;

	slld(n);

	for(i=0;i<n;i++)
	{
		slld(A[i]);
		isInc[ A[i] ] = true;
	}
	
	for(i=0;i<n;i++)
	{
		if( !isInc[ 1000000-A[i]+1 ] )
		{
			ans.push_back( 1000000-A[i]+1 );
			isInc[ 1000000-A[i]+1 ] = true;
			A[i] = 0;
		}
	}

	for(j=1,i=0;i<n;i++)
	{
		if(A[i] != 0 && A[i] < 1000000-A[i]+1)
		{
			while( isInc[1000000-j+1] || isInc[j] )
				j++;
			isInc[1000000-j+1] = isInc[j] = true;
			ans.push_back( 1000000-j+1 );
			ans.push_back( j );
		}
	}

	printf("%lld\n", (long long)sz(ans) );
	for(i=0;i<sz(ans);i++)
		printf("%lld ", ans[i] );
	printf("\n");

	return 0;
}