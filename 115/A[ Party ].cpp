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

int A[2007];
int B[2007];
bool isNotLeaf[2007];

int main()
{
	int i,j,k,l=0,m=0,n;

	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(A[i]);

		if(A[i]	!=	-1)
			isNotLeaf[ A[i] ] = true;
	}	

	for(i=1,k=0;i<=n;i++)
	{
		if(!isNotLeaf[i])
			B[k++] = i;
	}

	for(i=0;i<k;i++)
	{
		m = 0;
		j = B[i];
		while(j!=-1)
		{
			m++;
			j = A[j];
		}
		l = max(l,m);	
	}

	printf("%d\n",l);	

	return 0;
}
