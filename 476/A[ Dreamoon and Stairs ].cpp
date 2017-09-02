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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,mini,maxi,n,m;

	sd(n);	sd(m);

	maxi = n;
	mini = n/2 + ((n%2)?1:0) ;
	
	if( (mini/m + ((mini%m)?1:0) )*m <= maxi )
		printf("%d\n", (mini/m + ((mini%m)?1:0) )*m );
	else
		printf("-1\n");

	return 0;
}