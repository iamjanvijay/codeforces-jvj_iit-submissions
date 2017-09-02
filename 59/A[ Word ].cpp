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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,small=0,caps=0;
	ss(S);	
	n = strlen(S);

	for(i=0;i<n;i++)
	{
		if(&#39;A&#39;<=S[i] && S[i]<=&#39;Z&#39;)
			caps++;
		else
			small++;
	}

	if(caps>small)
	{	
		for(i=0;i<n;i++)
		{
			if(&#39;a&#39;<=S[i] && S[i]<=&#39;z&#39;)
				S[i] = (int)S[i]-&#39;a&#39;+&#39;A&#39;;
		}
	}
	else 
	{
		for(i=0;i<n;i++)
		{
			if(&#39;A&#39;<=S[i] && S[i]<=&#39;Z&#39;)
				S[i] = (int)S[i]-&#39;A&#39;+&#39;a&#39;;
		}
	}

	printf("%s\n", S );

	return 0;
}