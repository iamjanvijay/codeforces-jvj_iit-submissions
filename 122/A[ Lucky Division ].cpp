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
queue<int> T;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,n;
	sd(n);
	
	T.push(4);	T.push(7);

	while(!T.empty())
	{
		V.push_back( T.front() );
		if( (T.front())*10 + 4 <= 1000 )
			T.push( (T.front())*10 + 4 );
		if( (T.front())*10 + 7 <= 1000 )
			T.push( (T.front())*10 + 7 );
		T.pop();		
	}

	for(i=0;i<V.size();i++)
		if(n%V[i]==0)
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}