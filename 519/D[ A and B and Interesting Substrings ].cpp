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

int Val[26];
char S[100007];
ll A[100007];
map< pair<char,ll> , int > M;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;
	ll ans = 0;

	for(i=0;i<26;i++)
		sd(Val[i]);

	ss(S+1);

	if(strlen(S+1)==1)
	{
		printf("0\n");
		return 0;
	}

	for(i=1;S[i]!=&#39;\0&#39;;i++)
	{
		A[ i ] = Val[ S[i]-&#39;a&#39; ];
		A[ i ] += A[ i-1 ];
		M[ make_pair( S[i], A[i-1] ) ]++;
	}

	for(i=1;S[i]!=&#39;\0&#39;;i++)
	{
		M[ make_pair( S[i], A[i-1] ) ]--;
		ans += M[ make_pair( S[i], A[i] ) ];
	}

	printf("%lld\n", ans );
	
	return 0;
}