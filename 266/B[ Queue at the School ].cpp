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

char S[57];
char Temp[57];

int main()
{
	int i,j,N,T;
	sd(N);	sd(T);
	ss(S);

	for(i=0;i<T;i++)
	{
		Temp[0] = S[0];
		for(j=1;j<N;j++)
		{
			if(S[j]==&#39;G&#39; && S[j-1]==&#39;B&#39;)
			{	
				Temp[j-1] = &#39;G&#39;;
				Temp[j] = &#39;B&#39;;
			}
			else
			{
				Temp[j] = S[j];
			}
		}
		for(j=0;j<N;j++)
			S[j] = Temp[j];
	}

	printf("%s\n",S );

	return 0;
}