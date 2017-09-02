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

ll A[100007] = {0};
map<ll,ll> M;
ll P[400] = {0};

int main()
{
	ll i,j,k,l,t,n,n1,ans=0;

	slld(n); slld(k);

	if(k==1)
	{
		P[0] = 1;
		n1 = 1;
	}
	else if(k==-1)
	{
		P[0] = 1;
		P[1] = -1;
		n1 = 2;
	}	
	else
	{	
		i=0;
		j=1;

		while(j<=100000000000000LL && -100000000000000LL<=j)
		{
			P[i++] = j;
			j=j*k;
		}

		n1 = i;

	}

	for(i=0;i<n;i++)
		slld(A[i]);

	M[0] = 1;

	k = 0;

	for(i=0;i<n;i++)
	{
		k += A[i];

		for(j=0;j<n1;j++)
		{
			ans += M[ k-P[j] ];
		}

		M[k]++;
	}

	printf("%lld\n",ans);	

	return 0;
}
