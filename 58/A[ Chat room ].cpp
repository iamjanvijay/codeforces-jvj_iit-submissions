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
char P[] = "hello";

int main()
{
	int i,j,k,l,n;
	ss(S);

	for(j=0,i=0;S[i]!=&#39;\0&#39; && j<5;i++)
	{
		if(S[i] == P[j])
		{
			j++;
		}	
	}

	if(j==5)
		printf("YES\n");
	else
		printf("NO\n");		

	return 0;
}

