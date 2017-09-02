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

struct  Pair
{
	int p;
	int t;

	bool operator<(const Pair& B) const
	{
		if(p != B.p)
		{
			return p > B.p ;
		}
		else
		{
			return t < B.t ;
		}	
	}

	bool operator==(const Pair& B) const
	{
		return ( p == B.p ) && ( t == B.t );
	}
};

vector< Pair > V;

int main()
{
	int i,j,l,n,k;
	Pair temp;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
	{
		sd(temp.p);	sd(temp.t);
		V.push_back(temp);		
	}

	sort(V.begin(),V.end());
	
	i = k-1; j = k-1;

	while(true)
	{
		if( j+1<n && V[j+1] == V[k-1] )
			j++;
		else
			break;		
	}

	while(true)
	{
		if( i-1>=0 && V[i-1] == V[k-1] )
			i--;
		else
			break;		
	}

	printf("%d\n", j-i+1 );			

	return 0;
}
