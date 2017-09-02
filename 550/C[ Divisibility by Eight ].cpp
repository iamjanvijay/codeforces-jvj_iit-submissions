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

char N[107];
bool C[107];
char S[124][4];

int main()
{
	int i,j,k,l,m,n;
	ss(N);

	n = strlen(N);

	for(i=0;i<n;i++)
	{
		if(N[i]==&#39;0&#39;)
		{
			printf("YES\n0\n");
			return 0;
		}
	}


	for(i=1;i<=124;i++)
	{
		j = 8*i;

		k = j; l = 0;

		while(k!=0)
		{
			k/=10;
			l++;
		}

		S[i-1][l] =	&#39;\0&#39;;

		for(k=l-1;k>=0;k--)
		{
			S[i-1][k] = &#39;0&#39;+j%10;
			j/=10;
		}	
	}

	// for(i=0;i<124;i++)
	// 	printf("%s\n", S[i] );	

	for(i=0;i<124;i++)
	{
		for(j=0;j<n;j++)
			C[j] = false;

		for(j=0,k=0;j<n && S[i][k]!=&#39;\0&#39;;j++)
		{
			if(S[i][k] == N[j])
			{
				k++;
				C[j] = true;
			}
		}

		if(S[i][k]==&#39;\0&#39;)
		{
			printf("YES\n");

			for(j=0;j<n;j++)
			{
				if(C[j])
					printf("%c", N[j] );
			}
			printf("\n");
			return 0 ;	
		}	

	}	

	printf("NO\n");

	return 0;
}
