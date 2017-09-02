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

pii A[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r,h;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	bool flag = false;
	sd(n);	sd(h);

	for(i=0;i<n;i++)
	{
		sd(A[i].F);
		A[i].S = i;
	}

	sort(A, A+n);

	a = (A[n-1].F+A[n-2].F) - (A[1].F+A[0].F);

	b = min( A[0].F+A[1].F+h, (2<n)?(A[1].F+A[2].F):(INT_MAX) );

	c = max( (n>2)?(A[n-1].F+A[n-2].F):(INT_MIN), A[0].F+A[n-1].F+h );

	if( a > c-b )
		flag = true;
	a = min(a, c-b);

	printf("%d\n", a );

	for(i=0;i<n;i++)
	{
		if(i==A[0].S && flag)
			printf("1 ");
		else
			printf("2 ");
	}
	printf("\n");

	return 0;
}