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

int main()
{
	int i,j,k;
	bool flag = true;
	char S1[107],S2[107];

	ss(S1);
	ss(S2);

	for(i=0;S1[i]!=&#39;\0&#39;;i++)
		if(S1[i]>&#39;Z&#39;)
			S1[i] = (char)( (int)S1[i] - (int)&#39;a&#39; + (int)&#39;A&#39; );

	for(i=0;S2[i]!=&#39;\0&#39;;i++)
		if(S2[i]>&#39;Z&#39;)
			S2[i] = (char)( (int)S2[i] - (int)&#39;a&#39; + (int)&#39;A&#39; );

	for(i=0;S1[i]!=&#39;\0&#39;;i++)
	{
		if(S1[i]!=S2[i])
		{
			if(S1[i]<S2[i])
			{
				printf("-1\n");
				flag = false;
				break;
			}
			else
			{
				printf("1\n");
				flag = false;
				break;
			}	
		}	
	}

	if(flag)
		printf("0\n");				

	return 0;
}
