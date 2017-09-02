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

	int i,j,k,l,m,n;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(j);	sd(k);
		V.push_back( make_pair(j,k) );
	}

	sort(V.begin(), V.end());

	bool flag = true;

	for(i=n-1;i>0;i--)
	{
		if( V[i].second < V[i-1].second )
		{
			flag = false;
			break;
		}
	}

	if(flag)
	{
		printf("%d\n", V[n-1].second );
		return 0;
	}

	flag = false;
	
	for(i=n-1;i>0;i--)
	{
		if( V[i].second >= V[i-1].first )
		{
			flag = true;
			break;
		}
		if( V[i].second < V[i-1].second )
		{
			flag = false;
			break;
		}		
	}

	if(flag)
	{
		printf("%d\n", V[n-1].second );
		return 0;
	}

	printf("%d\n", V[n-1].first );	
	
	return 0;
}