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

char S[4007];
int A[36777];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,a;
	ll ans=0;

	sd(a);
	ss(S);	n = strlen(S);

	for(i=0;i<n;i++)
	{
		k = 0;
		for(j=i;j<n;j++)
		{
			k += (S[j]-&#39;0&#39;);
			A[k]++;
			// printf("%d\n", k );
		}
	}

	if(a==0)
	{
		printf("%lld\n", (ll)A[0]*(n*(n+1)) - (ll)A[0]*A[0] );
		return 0;
	}

	for(i=1;i<36777;i++)
	{
		// if((ll)A[i]*A[i] == a)
		// 	ans--
		if( A[i]!=0 && a%i==0 )
		{
			if(a/i<36777)
				ans += (ll)A[i]*A[a/i];
		}
	}

	printf("%lld\n", ans );
	
	return 0;
}