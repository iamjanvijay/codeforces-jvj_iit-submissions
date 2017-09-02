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

char S[1007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ss(S);

	if(&#39;a&#39;<=S[0] && S[0]<=&#39;z&#39;)
		S[0] = (char)( (int)S[0] - (int)&#39;a&#39; + (int)&#39;A&#39; );	
	
	printf("%s\n", S );

	return 0;
}