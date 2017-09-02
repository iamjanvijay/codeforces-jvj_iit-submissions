#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

char St[100007];
stack< pair<char,int> > S1;
stack< pair<int,int> > S2;
vector< pair<int,int> > V;
int Pre[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,ans;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(St);		n = strlen(St);

	for(i=0;i<n;i++)
	{
		if( (S1.empty()) || (St[i]==&#39;(&#39; || St[i]==&#39;[&#39;) )
		{
			S1.push( mp(St[i],i+1) );
		}
		else 
		{
			if((S1.top().F == &#39;(&#39; && St[i]==&#39;)&#39;) || (S1.top().F == &#39;[&#39; && St[i]==&#39;]&#39;))
			{
				x = S1.top().S;		y = i+1;
				S1.pop();
				while( !S2.empty() && x <= S2.top().F && S2.top().S <= y )
					S2.pop();

				S2.push( mp(x,y) );
			}
			else
			{
				S1.push( mp(St[i],i+1) );
			}
		}
	}

	for(i=1;i<=n;i++)
	{
		if(St[i-1]==&#39;[&#39;)
			Pre[i] = 1;
		Pre[i] += Pre[i-1];
	}

	ans = 0;

	while(!S2.empty())
	{
		// printf("*->%d %d\n", S2.top().F, S2.top().S);
		V.pb( S2.top() );
		S2.pop();
	}

	reverse(V.begin(), V.end());

	for(i=0;i<sz(V);i++)
	{
		if(S2.empty())
			S2.push(V[i]);
		else
		{
			if(S2.top().S+1 == V[i].F)
			{
				x = S2.top().F; y = V[i].S;
				S2.pop();	S2.push(mp(x,y));
			}
			else
			{
				S2.push(V[i]);
			}
		}
	}

	x = y = 0;
	while(!S2.empty())
	{
		// printf("->%d %d\n", S2.top().F, S2.top().S);
		if(ans<Pre[S2.top().S]-Pre[S2.top().F - 1])
		{
			ans = Pre[S2.top().S]-Pre[S2.top().F - 1];
			x = S2.top().F;		y =S2.top().S;
		}
		S2.pop();
	}

	printf("%d\n", ans );
	
	St[y] = &#39;\0&#39;;
	if(ans!=0)
		printf("%s\n",St+x-1);

	return 0;
}