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

char S1[107],S2[107],S3[107];

int main()
{
	int i;
	ss(S1);	ss(S2);

	for(i=0;S1[i]!=&#39;\0&#39;;i++)
		if(S1[i]!=S2[i])
			S3[i] = &#39;1&#39;;
		else
			S3[i] = &#39;0&#39;;

	S3[i] = &#39;\0&#39;;

	printf("%s\n",S3);	

	return 0;
}
