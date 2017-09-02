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
int C[26]={0};

int main()
{
	int i,j,k,n;
	sd(k);	
	ss(S);


	for(i=0;S[i]!=&#39;\0&#39;;i++)
	{
		C[ S[i] - &#39;a&#39; ]++;
	}

	for(i=0;i<26;i++)
	{
		if(C[i]%k != 0)
		{
			printf("-1\n");
			return 0;
		}
		C[i]/=k;
	}

	for(i=0,j=0;i<26;i++)
	{
		while(C[i]!=0)
		{
			S[j++] = &#39;a&#39; + i;
			C[i]--;
		}
	}

	S[j] = &#39;\0&#39;;

	while(k--)
	{
		printf("%s", S );
	}
	printf("\n");	

	return 0;
}
