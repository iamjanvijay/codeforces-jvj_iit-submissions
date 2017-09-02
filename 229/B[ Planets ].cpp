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

priority_queue< pair< int,int >, vector< pair< int,int > >, greater< pair< int,int > > > Q;
vector< pair<int,int> > G[100007];
map<int,int> Delay[100007];
int Mintime[100007];
bool Selected[100007];
int T[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,u,v,w,a,b,r;
	pair<int,int> temp;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	for(i=0;i<100007;i++)
		Mintime[i] = INT_MAX;
	
	sd(n);	sd(m);

	for(i=0;i<m;i++)
	{
		sd(u);	sd(v);	sd(w);
		G[u].pb( mp(v,w) );
		G[v].pb( mp(u,w) );
	}

	for(i=1;i<=n;i++)
	{
		sd(k);
		for(j=0;j<k;j++)
			sd(T[j]);
		for(j=k-1;j>=0;j--)
		{
			if(j!=k-1 && T[j]+1==T[j+1])
				l++;
			else
				l = 1;
			Delay[i][T[j]] = l;
		}
	}

	Q.push( mp(0,1) );

	while(!Q.empty())
	{
		temp = Q.top();	Q.pop();
		if(Selected[temp.S])
			continue;
		Selected[temp.S] = true;
		Mintime[temp.S] = temp.F;
		for(i=0;i<sz(G[temp.S]);i++)
		{
			if( !Selected[G[temp.S][i].F] && Mintime[G[temp.S][i].F] > (temp.F)+Delay[temp.S][temp.F]+G[temp.S][i].S )
			{
				Mintime[G[temp.S][i].F] = (temp.F)+Delay[temp.S][temp.F]+G[temp.S][i].S;
				Q.push( mp(Mintime[G[temp.S][i].F],G[temp.S][i].F) );
			}
		}
	}

	if(Mintime[n]==INT_MAX)
	{
		printf("-1\n");
		return 0;
	}

	printf("%d\n", Mintime[n] );

	return 0;
}