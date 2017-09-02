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

char S[200007];
int Key[100] = {0};

int main()
{
	int i,N,ans = 0;
	sd(N);	ss(S);

	for(i=0;i<(2*(N-1));i++)
	{
		if(!(i%2))
		{
			Key[ S[i] - &#39;a&#39; ]++ ;
		}
		else
		{
			if( Key[ S[i] - &#39;A&#39; ] > 0 )
				Key[ S[i] - &#39;A&#39; ]--;
			else
				ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}