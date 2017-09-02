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

int V[100007];
stack<int> S;
int T[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(n);
	for(i=0;i<n;i++)
		sd(V[i]);

	T[ V[0] ] = -1;
	S.push(V[0]);

	// printf("*** %d : %d\n", V[0] , T[ V[0] ] );	

	for(i=1;i<n;i++)
	{
		m = 0;
		while( !S.empty() && S.top() <= V[i] )
		{
			m = max(m,T[ S.top() ]+1);
			S.pop();
		}

		if(S.empty())
			T[ V[i] ] = -1;
		else
			T[ V[i] ] = m;

		// printf("*** %d : %d\n", V[i] ,T[ V[i] ] );
		S.push( V[i] );
	}

	m = T[V[0]];
	for(i=0;i<n;i++)
		m = max(m,T[V[i]]);

	printf("%d\n", m+1 );

	return 0;
}