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

char S[100007];
int A[100007];

int main()
{
	ss(S+1);

	int i,j,k,l,m,n;

	for(i=1;S[i+1]!=&#39;\0&#39;;i++)
	{
		if(S[i]==S[i+1])
			A[i] = 1;
		A[i] += A[i-1];
	}

	sd(m);

	while(m--)
	{
		sd(j);	sd(k);

		printf("%d\n",A[k-1]-A[j-1]);

	}	


	return 0;
}
