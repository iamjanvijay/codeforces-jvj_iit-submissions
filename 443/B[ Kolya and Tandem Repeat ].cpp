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

char S[407];

int main()
{
	int i,j,k,l,m,n,ans=0;

	ss(S);
	sd(k);

	for(i=0;S[i]!=&#39;\0&#39;;i++);

	for(i,j=0;j<k;j++,i++)
		S[i] = &#39;X&#39;;
	S[i] = &#39;\0&#39;;
	
	n = i;

	for(i=0;i<n;i++)
	{
		for(l=1; i+2*l-1 < n;l++)
		{
			bool flag = true;
			for(j=0;j<l;j++)
			{
				if(S[i+j]==&#39;X&#39; || S[i+l+j]==&#39;X&#39;)
					continue;
				if(S[i+j]!=S[i+l+j])
				{
					flag = false;
					break;
				}
			}
			if(flag)
				ans = max(ans,2*l);
		}	
	}

	printf("%d\n", ans );		

	return 0;
}
