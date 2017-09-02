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

ll M = 1000000007;

char str[600007];
set<ll>  LenSet[600007];
ll PowOf257[600007];
ll NegPowOf257[600007];

void init()
{
	int i;
	PowOf257[0] = 1;
	for(i=1;i<600007;i++)
	{
		PowOf257[i] = ( 257LL * PowOf257[i-1] )%M;
	}
	for(i=0;i<600007;i++)
	{
		NegPowOf257[i] = ( M - PowOf257[i] )%M;
	}
}

void insertString()
{
	int i,N = strlen(str);

	ll hashCode = 0;

	for(i=0;i<N;i++)
	{
		hashCode = ( hashCode + ( (ll)(str[N-1-i]) * (PowOf257[i]) ) )%M;
	}

	LenSet[N].insert(hashCode);
}

bool checkString()
{
	int i,N = strlen(str);

	ll hashCode = 0;
	ll tempCode = 0;

	for(i=0;i<N;i++)
	{
		hashCode = ( hashCode + ( (ll)(str[N-1-i]) * (PowOf257[i]) ) )%M;
	}

	for(i=0;i<N;i++)
	{
		if(str[N-1-i]!=&#39;a&#39;)
		{
			tempCode = ( hashCode + ( (ll)(str[N-1-i]) * ( NegPowOf257[i]) ) + ( &#39;a&#39; * (PowOf257[i]) ) )%M;
			if( LenSet[N].count(tempCode) )
				return true;
		}
		if(str[N-1-i]!=&#39;b&#39;)
		{
			tempCode = ( hashCode + ( (ll)(str[N-1-i]) * ( NegPowOf257[i]) ) + ( &#39;b&#39; * (PowOf257[i]) )  )%M;
			if( LenSet[N].count(tempCode) )
				return true;
		}
		if(str[N-1-i]!=&#39;c&#39;)
		{
			tempCode = ( hashCode + ( (ll)(str[N-1-i]) * ( NegPowOf257[i]) ) + ( &#39;c&#39; * (PowOf257[i]) ) )%M;
			if( LenSet[N].count(tempCode) )
				return true;
		}
	}

	return false;
}

int main()
{
	init();
	int n,m,i,j,k;

	sd(n);	sd(m);

	while(n--)
	{
		ss(str);
		insertString();
	}

	while(m--)
	{
		ss(str);
		if(checkString())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
