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

vector< pair<int, int> > G[300007];
vector< pair<int, pair<int, int> > > E;
vector< pair<int,int> > temp;
int DP[300007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,w,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=1;i<=n;i++)
		DP[i] = 0;

	for(i=0;i<m;i++)
	{
		sd(x);	sd(y);	sd(w);
		G[x].pb( mp(y,w) );
		E.pb( mp( w , mp(x,y) ) );
	}

	sort(E.begin(), E.end());
	reverse(E.begin(), E.end());

	for(i=0;i<m;i++)
	{
		for(j=i;j<m && E[j].F==E[i].F;j++)
		{
			x = E[j].S.F;	y = E[j].S.S;	w = E[j].F;
			temp.pb( mp(x, DP[y]+1) );
		}
		i = j-1;
		for(j=0;j<sz(temp);j++)
			DP[temp[j].F] = max(DP[temp[j].F], temp[j].S);
		temp.clear();
	}
	
	a = 0;
	for(i=1;i<=n;i++)
		a = max(a, DP[i]);

	printf("%d\n", a );

	return 0;
}