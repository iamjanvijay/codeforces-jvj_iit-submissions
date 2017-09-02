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

char S[100007];

int main()
{
	ss(S);

	int i,j,k,l,m,n;

	n = strlen(S);

	for(i=0;i<n;i++)
	{
		if(S[i]==&#39;0&#39;)
			break;
	}

	if(i<n)
		for(i;i<n;i++)
			S[i]=S[i+1];
	else
		S[n-1] = &#39;\0&#39;;

	printf("%s\n", S );			

	return 0;
}
