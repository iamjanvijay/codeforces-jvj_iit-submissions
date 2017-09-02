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

char S[1000007];
bool existInMid[1000007] = {false};
int LPS[1000007];

int main()
{
	int i,j,k,n;
	ss(S);

	j=0;	LPS[0] = 0;		n=strlen(S);	i=1;

	while(i<n)
	{
		if(S[i]==S[j])
		{
			LPS[i] = ++j;
			i++;
		}
		else
		{
			if(j==0)
			{
				LPS[i] = 0;
				i++;
			}
			else
			{
				j=LPS[j-1];
			}
		}
	}

	for(i=1;i<n-1;i++)
	{
		existInMid[ LPS[i] ] = true;
	}

	j = LPS[n-1];
	while(true)
	{
		if(j==0)
		{
			printf("Just a legend\n" );
			break;
		}

		if(existInMid[j])
		{
		    S[j] = &#39;\0&#39;;
			printf("%s\n",S);
			break;
		}
		else
		{
			j = LPS[j-1];
		}

	}

	return 0;
}
