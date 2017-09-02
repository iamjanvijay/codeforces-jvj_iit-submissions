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

int C[26];

int main()
{
	int i;

	ss(S1);		
	ss(S2);		
	ss(S3);

	for(i=0;S1[i]!=&#39;\0&#39;;i++)
		C[ S1[i] - &#39;A&#39; ]++;

	for(i=0;S2[i]!=&#39;\0&#39;;i++)
		C[ S2[i] - &#39;A&#39; ]++;	

	for(i=0;S3[i]!=&#39;\0&#39;;i++)
		C[ S3[i] - &#39;A&#39; ]--;

	for(i=0;i<26;i++)
		if(C[i]!=0)
		{
			printf("NO\n");
			break;
		}

	if(!(i<26))
		printf("YES\n");			

	return 0;
}
