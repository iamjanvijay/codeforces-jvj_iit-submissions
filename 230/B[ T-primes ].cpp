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

bool isPrime[1000007]={false};

void init()
{
	int i,j,k,l;
	isPrime[1] = isPrime[0] = true;
	for(i=2;i*i<1000007;i++)
	{
		if(!isPrime[i])
		{
			for(j=i*i;j<1000007;j+=i)
			{
				isPrime[j] = true;
			}	
		}	
	}	
}

int main()
{
	init();
	int n,i,j,l;
	ll k; double z;
	sd(n);

	while(n--)
	{
		slld(k);
		z = sqrt(k);
		if( z == (int)z )
		{
			if(!isPrime[ (int)z ])
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			printf("NO\n");
		}	
	}	

	return 0;
}
