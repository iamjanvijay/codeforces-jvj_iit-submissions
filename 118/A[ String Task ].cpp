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

char S[107];

bool isvowel(char c)
{
	return (c==&#39;a&#39;) || (c==&#39;y&#39;) || (c==&#39;e&#39;) || (c==&#39;i&#39;) || (c==&#39;o&#39;) || (c==&#39;u&#39;) || (c==&#39;A&#39;) || (c==&#39;E&#39;) || (c==&#39;I&#39;) || (c==&#39;O&#39;) || (c==&#39;Y&#39;) || (c==&#39;U&#39;);   
}

int main()
{
	int i,j,k,l,n;
	ss(S);

	for(i=0;S[i]!=&#39;\0&#39;;i++)
	{
		if(!isvowel(S[i]))
		{
			if(S[i]>=&#39;a&#39;)
				printf(".%c", S[i] );
			else
				printf(".%c", S[i]-&#39;A&#39;+&#39;a&#39; );
		}
	}	
	printf("\n");

	return 0;
}
