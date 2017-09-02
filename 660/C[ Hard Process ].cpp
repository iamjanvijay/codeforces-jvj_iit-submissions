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

int A[300007];

int main()
{
	int i,j,cnt,tempcnt,l,r,N,K;

	sd(N);	sd(K);

	for(i=0;i<N;i++)
		sd(A[i]);

	i=0;j=0;cnt=0;l=0;r=0;

	while(i<N)
	{
		if(j<i)
			j = i;
		while(j<N)
		{
			tempcnt = cnt + !A[j];
			if(tempcnt > K)
				break;
			cnt = cnt + !A[j];
			j++;
		}

		if(j-i > r-l)
		{	l = i; r = j; }

		if(i!=j)
            cnt -= !A[i];
		i++;
	}

	printf("%d\n",r-l);

	for(i=0;i<N;i++)
	{
		if(i<r && l<=i)
			printf("1 ");
		else
			printf("%d ",A[i]);
	}
	printf("\n");

	return 0;
}
