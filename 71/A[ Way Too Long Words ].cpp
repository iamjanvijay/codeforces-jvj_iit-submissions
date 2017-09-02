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
	int i,j,k,n;

	sd(n);

	for(i=0;i<n;i++)
	{
		ss(S);
		k = strlen(S);

		if(k>10)
		{
			printf("%c%d%c\n", S[0], k-2 ,S[k-1]);
		}
		else
		{
			printf("%s\n", S );
		}	
		
	}	

	return 0;
}

