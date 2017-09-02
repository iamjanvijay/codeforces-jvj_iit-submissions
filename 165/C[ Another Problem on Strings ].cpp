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

vector<int> V;
char S[1000007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;
	ll ans = 0;

	sd(k);
	ss(S);



	V.push_back(-1);

	for(i=0;S[i] != &#39;\0&#39;;i++)
		if(S[i]==&#39;1&#39;)
			V.push_back(i);

	V.push_back(i);

	if(k==0)
	{
		for(i=0,j=1;j<V.size();i++,j++)
		{
			l = (V[j]-1) - (V[i]+1) + 1;
			ans += ((ll)l * (ll)(l+1) / 2);
		}
	}	
	else
	{
		for(i=0,j=k+1;j<V.size();i++,j++)
		{
			ans += (ll)(V[i+1]-V[i]) * (ll)(V[j]-V[j-1]);
		}
	}

	printf("%lld\n", ans );	
	
	return 0;
}