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

char A[1000007];
char B[1000007];

bool isZero(char S[])
{
	int i;
	for(i=0;S[i]!=&#39;\0&#39;;i++)
		if(S[i]!=&#39;0&#39;)
			return false;	
	return true;	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,n,m;

	ss(A);	ss(B);

	n = strlen(A);	m = strlen(B);

	if(n!=m || (isZero(A)^isZero(B)))
	{
		printf("NO\n");
		return 0;
	} 

	printf("YES\n");	
	
	return 0;
}