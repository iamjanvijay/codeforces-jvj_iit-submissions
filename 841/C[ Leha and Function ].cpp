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

int A[200007];
int ans[200007];
pair<int,int> B[200007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<n;i++)
	{
		sd(B[i].F);
		B[i].S = i;
	}	

	sort(B,B+n);

	// for(i=0;i<n;i++)
	// 	printf("%d ", B[i].S );
	// printf("\n");

	sort(A,A+n);

	for(i=0;i<n;i++)
	{
		// printf("%d ", A[n-1-i] );
		ans[ B[i].S ] = A[n-1-i];
	}
	// printf("\n");

	for(i=0;i<n;i++)
		printf("%d ", ans[i] );
	printf("\n");		
	
	return 0;
}