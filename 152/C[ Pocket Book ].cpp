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

char S[107][107];
bool A[26];

int main()
{
	int i,j,k,l,m,n;

	ll ans = 1;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
	{
		ss(S[i]);
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<26;j++)
		{
			A[j] = false;
		}	

		for(j=0;j<n;j++)
		{
			A[ S[j][i] - &#39;A&#39; ] = true;
		}

		k=0;
		for(j=0;j<26;j++)
		{
			if(A[j])
				k++;
		}

		ans = (ans*k)%1000000007;  	
	}

	printf("%lld\n",ans);	

	return 0;
}
