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

int A[100007];
int B[100007];

int main()
{
	int i,j,k,l,m,n;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(A[i]);
		B[i] = A[i];
	}

	sort(B,B+n);

	k = 0;
	for(i=0;i<n;i++)
		if(B[i]!=A[i])
			k++;

	if(k==2 || k==0)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
