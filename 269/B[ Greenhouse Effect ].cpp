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

vector<int> V;
vector<int>::iterator it;

int main()
{
	int i,j,k,N,M;
	double x;

	sd(N);	sd(M);

	for(i=0;i<N;i++)
	{
		sd(k);	slf(x);
		it = upper_bound(V.begin(),V.end(),k);
		if( it == V.end() )
			V.push_back( k );
		else
			(*it) = k;
	}

	printf("%d\n",N-(V.size()));



	return 0;
}