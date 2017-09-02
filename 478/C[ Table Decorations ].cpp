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

ll A[3];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	slld(A[0]);	slld(A[1]);	slld(A[2]);

	sort(A,A+3);

	if( 2*(A[0]+A[1]) <= A[2] )
		printf("%lld\n", (A[0]+A[1]) );
	else
		printf("%lld\n", (A[0]+A[1]+A[2])/3 );

	return 0;
}