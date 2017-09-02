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

char S[17];

int main()
{
	int i,j,k,l,m,n;

	ss(S);
	sd(k);

	n=strlen(S);


	l = 0;
	j = 0; // nonzero
	for(i=n-1;i>=0 && l<k;i--)
	{
		if(S[i]==&#39;0&#39;)
			l++;
		else
			j++;		
	} 

	if(l==k)
	{
		printf("%d\n", j );
	}
	else
	{
		if(l!=0)
			printf("%d\n", n-1 );
		else
			printf("%d\n", -1 );
	}	

	return 0;
}
