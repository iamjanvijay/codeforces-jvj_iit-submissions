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

ll A[100007];
ll Incr[100007];
ll Op[100007][4];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n;

	sd(n);	sd(m);	sd(k);

	for(i=1;i<=n;i++)
		slld(A[i]);

	for(i=1;i<=m;i++)
	{
		slld(Op[i][0]);	slld(Op[i][1]);	slld(Op[i][2]);
	}

	for(i=1;i<=k;i++)
	{
		sd(l);	sd(r);
		Op[l][3] += 1;	Op[r+1][3] += -1;	
	}

	for(i=1;i<=m;i++)
	{
		Op[i][3] += Op[i-1][3];
		Incr[ Op[i][0] ] += Op[i][3]*Op[i][2];
		Incr[ Op[i][1] + 1 ] -= Op[i][3]*Op[i][2];
	}

	for(i=1;i<=n;i++)
	{
		Incr[i]+=Incr[i-1];
		A[i] += Incr[i];
		printf("%lld ", A[i] );
	}
	printf("\n");

	return 0;
}