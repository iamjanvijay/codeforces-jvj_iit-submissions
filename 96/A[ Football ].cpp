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
	int i,k = 1,maxi=1;

	ss(S);

	for(i=1;S[i]!=&#39;\0&#39;;i++)
	{
		if(S[i]==S[i-1])
			k++;
		else
			k = 1;
		maxi = max(maxi,k);
	}	

	// printf("%d\n", maxi );

	if(maxi>=7)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
