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
int A[200007];
char T[200007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ss(S);
	int i,j,k,l,n,m;
	n = strlen(S);
	
	m=0;
	i=1;k=1;
	while(i<n)
	{
		if(S[i]!=S[i-1])
		{
			T[m] = S[i-1];
			A[m++] = k;
			k = 1;
		}
		else
		{
			k++;
		}
		i++;
	}
	T[m] = S[i-1];
	A[m++] = k;
	T[m] = &#39;\0&#39;;
	// printf("%s\n", T );

	for(i=0;i<m;i++)
	{
		if(A[i]>2)
		{
			A[i] = 2;
		}
	}

	l=0;
	i=0;
	j=0;

	while(i<m)
	{
		j=i;
		if(A[j]==2)
		{
			l=0;
			while(A[j]==2)
			{
				if(l%2==1)
					A[j] = 1;
				l++;	j++;
			}
			i=j;
		}
		else
			i++;		
	}

	for(i=0;i<m;i++)
	{
		while(A[i]--)
			printf("%c", T[i] );
	}
	printf("\n");
	return 0;
}