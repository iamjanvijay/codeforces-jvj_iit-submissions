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
set<ll> S;
set<ll> S1;

int main()
{
	ll n,l,x,y,i,j,k;
	bool canMeasX = false,canMeasY = false; 

	slld(n);	slld(l);	slld(x);	slld(y);

	for(i=0;i<n;i++)
	{
		slld( A[i] );
		S.insert( A[i] );
	}

	for(i=0;i<n;i++)
	{
		if( S.count(A[i]-x) == 1 || S.count(A[i]+x) == 1 )
			canMeasX = true;
		if( S.count(A[i]-y) == 1 || S.count(A[i]+y) == 1 )
			canMeasY = true;		
	}	

	if(canMeasX && canMeasY)
	{
		printf("0\n");
		return 0;
	}
	else if(canMeasX && !canMeasY)
	{
		printf("1\n%lld\n",y);
		return 0;
	}
	else if(!canMeasX && canMeasY)
	{
		printf("1\n%lld\n",x);
		return 0;
	}
	else	
	{
		for(i=0;i<n;i++)
		{
			if( 0 <= A[i]-x && A[i]-x <= l)
				S1.insert( A[i]-x );
			if( 0 <= A[i]+x && A[i]+x <= l)
				S1.insert( A[i]+x );			
		}

		for(i=0;i<n;i++)
		{
			if( S1.count( A[i]-y ) == 1 )
			{
				printf("1\n%lld\n", A[i]-y );
				return 0;
			}
			if( S1.count( A[i]+y ) == 1 )
			{
				printf("1\n%lld\n", A[i]+y );
				return 0;
			}			
		}

		printf("2\n%lld %lld\n",x,y);	
		return 0;
	}	

	return 0;
}