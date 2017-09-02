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

pair<int,int> D[100007];
stack< pair<int,int> > S[100007];
vector< pair<int,int> > E;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(n);	sd(k);

	for(i=1;i<=n;i++)
	{
		sd(D[i].first);
		(D[i].second) = i;
	}

	sort(D+1,D+n+1);

	if(D[1].first != 0)
	{
		printf("-1\n");
		return 0;
	}

	S[ D[1].first ].push(make_pair(D[1].second,k));

	for(i=2;i<=n;i++)
	{
		if((D[i].first)!=0)
		while(!(S[ (D[i].first) - 1 ].empty()) && ( S[ (D[i].first) - 1 ].top() ).second == 0 )
			S[ (D[i].first) - 1 ].pop();

		if( (D[i].first)==0 || S[ (D[i].first) - 1 ].empty() )
		{
			printf("-1\n");
			return 0;
		}

		S[ D[i].first ].push(make_pair(D[i].second,k-1));
		E.push_back( make_pair( D[i].second, ( S[ (D[i].first) - 1 ].top() ).first ) );
		( ( S[ (D[i].first) - 1 ].top() ).second )--;
	}

	printf("%d\n", E.size() );

	for(i=0;i<E.size();i++)
		printf("%d %d\n", E[i].first , E[i].second );
	
	return 0;
}