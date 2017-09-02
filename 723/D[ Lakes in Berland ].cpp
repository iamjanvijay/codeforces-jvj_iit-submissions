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

char S[57][57];
bool isVis[57][57];
vector< pair<int, pair<int, int> > > lakes;

pair<int,bool> dfs(int i, int j, int &n, int &m)
{
	if(i<0 || j<0 || i>=n || j>=m)
		return mp(0, false);

	if(S[i][j]==&#39;*&#39; || isVis[i][j])
		return mp(0, true);

	isVis[i][j] = true;

	int water=1, islake=true;	pair<int,bool> temp;

	temp = dfs(i+1, j, n, m);
	water += temp.F;	islake &= temp.S;
	temp = dfs(i, j+1, n, m);
	water += temp.F;	islake &= temp.S;
	temp = dfs(i-1, j, n, m);
	water += temp.F;	islake &= temp.S;
	temp = dfs(i, j-1, n, m);
	water += temp.F;	islake &= temp.S;

	return mp(water, islake);
}

void floodFill(int i, int j, int &n, int &m)
{
	if(i<0 || j<0 || i>=n || j>=m || S[i][j]==&#39;*&#39;)
		return;

	S[i][j] = &#39;*&#39;;

	floodFill(i+1, j, n, m);
	floodFill(i, j+1, n, m);
	floodFill(i-1, j, n, m);
	floodFill(i, j-1, n, m);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);	sd(k);
	
	for(i=0;i<n;i++)
		ss(S[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(S[i][j]==&#39;.&#39; && !isVis[i][j])
			{
				pair<int,bool> temp = dfs(i, j, n, m);
				if(temp.S)
					lakes.pb( mp(temp.F, mp(i, j) ) );
			}
		}
	}

	sort(lakes.begin(), lakes.end());

	a = 0;
	for(i=0;i<sz(lakes)-k;i++)
	{
		a += lakes[i].F;
		floodFill(lakes[i].S.F, lakes[i].S.S, n, m);
	}

	printf("%d\n", a );
	for(i=0;i<n;i++)
		printf("%s\n", S[i] );

	return 0;
}