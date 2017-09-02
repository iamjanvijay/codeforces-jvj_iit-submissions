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

vector< pair<int,int> > V;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,x,y,s,n;

	sd(s);	sd(n);

	for(i=0;i<n;i++)
	{
		sd(x);	sd(y);
		V.push_back( make_pair(x,y) );
	}

	sort(V.begin(), V.end());

	for(i=0;i<n;i++)
	{
		if( s > V[i].first )
			s += V[i].second;
		else
		{
			printf("NO\n");
			return 0;
		}
	}	
	printf("YES\n");
	return 0;
}