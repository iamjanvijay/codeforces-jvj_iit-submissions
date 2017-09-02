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

vector< pii > A;
vector< pii > first;
vector< pii > second;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b=0,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=1;i<=n;i++)
	{
		sd(k);
		A.pb( mp(k,i) );
	}

	if(n%2!=0)
	{
		A.pb( mp(0,0) );
		n++;
	}

	sort(A.begin(), A.end());

	for(i=0;i<n;i+=2)
	{
		if( a > b )
		{
			b+=A[i+1].F;	a+=A[i].F;
			second.pb( A[i+1] );	first.pb( A[i] );
		}
		else
		{
			b+=A[i].F;	a+=A[i+1].F;
			second.pb( A[i] );	first.pb( A[i+1] );			
		}
	}

	if(first[0].F==0)
	{
		printf("%d\n", sz(first)-1 );
		for(i=1;i<sz(first);i++)
			printf("%d ", first[i].S );
		printf("\n");
	}
	else
	{
		printf("%d\n", sz(first) );
		for(i=0;i<sz(first);i++)
			printf("%d ", first[i].S );
		printf("\n");		
	}
	
	if(second[0].F==0)
	{
		printf("%d\n", sz(second)-1 );
		for(i=1;i<sz(second);i++)
			printf("%d ", second[i].S );
		printf("\n");
	}
	else
	{
		printf("%d\n", sz(second) );
		for(i=0;i<sz(second);i++)
			printf("%d ", second[i].S );
		printf("\n");		
	}

	return 0;
}