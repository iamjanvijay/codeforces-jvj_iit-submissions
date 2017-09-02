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

bool exists[2000007];
int A[100007];

set<int> S[2];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=0,n;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	l = 0;
	set<int>::iterator it;
	for(i=0;i<n;i++)
	{
		S[l].clear();
		for(it=S[1-l].begin();it!=S[1-l].end();it++)
		{
			S[l].insert( (*it) | A[i] );
			exists[ (*it) | A[i] ] = true;
		}
		S[l].insert( A[i] );
		exists[ A[i] ] = true;
		l=1-l;
	}

	for(i=0;i<=2000000;i++)
		if(exists[i])
			m++;

	printf("%d\n", m );	
	
	return 0;
}