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
int A[1000007];
int B[1000007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k1,k2,l,m,n;

	ss(S);	n=strlen(S);
	sd(k1);	sd(k2);

	for(m=0,i=0;i<n;i++)
	{
		m = (m*10+(S[i]-&#39;0&#39;))%k1;
		A[i] = m;
		// printf("%d ", A[i] );
	}
	// printf("\n");

	for(m=0,i=n-1,l=1;i>=0;i--,l=(l*10)%k2)
	{
		m = (l*(S[i]-&#39;0&#39;)+m)%k2;
		B[i] = m;
	}

	// for(i=0;i<n;i++)
	// 	printf("%d ", B[i] );
	// printf("\n");

	for(i=1;i<n;i++)
		if(A[i-1]==0 && B[i]==0 && S[i]!=&#39;0&#39;)
			break;

	if(i==n)
	{
		printf("NO\n");
		return 0;
	}	

	printf("YES\n");
	for(j=0;j<i;j++)
		printf("%c", S[j] );
	printf("\n");

	for(j=i;j<n;j++)
		printf("%c", S[j] );
	printf("\n");	
	
	return 0;
}