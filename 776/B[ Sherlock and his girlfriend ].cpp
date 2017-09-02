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

int A[100007]={0};

int main()
{
	int i,j,k,l,t,n;

	sd(n);

	for(i=2;i*i <= n+1;i++)
	{
		if(A[i]==0)
		for(j=i*i;j <= n+1;j+=i)
		{
			A[j] = 1;
		}
	}


	if(n+1<=3)
		printf("1\n");
	else
		printf("2\n");

	for(i=2;i <= n+1;i++)
		printf("%d ",A[i]+1);	
	printf("\n");
	return 0;
}
