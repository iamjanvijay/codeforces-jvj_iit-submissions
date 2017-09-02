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

vi T[100007];
// int L[100007];
bool L[100007];
int init[100007];
int goal[100007];
int lazy[100007];
int updates[100007];
vi ans; 
queue<int> Q;
int temp;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,r,u,v;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=1;i<=n-1;i++)
	{
		sd(u);	sd(v);
		T[u].pb(v);	T[v].pb(u);
	}

	// Q.push( mp(1,1) );
	// L[1] = 1;

	// while( !Q.empty() )
	// {
	// 	temp = Q.top();	Q.pop();
	// 	for(i=0;i<sz(T[temp.F]);i++)
	// 	{
	// 		if( L[ T[temp.F][i] ] == 0 )
	// 		{
	// 			Q.push( mp( T[temp.F][i] , temp.F + 1 ) );
	// 			L[ T[temp.F][i] ] = temp.F + 1;
	// 		}
	// 	}
	// }

	for(i=1;i<=n;i++)
		sd(init[i]);

	for(i=1;i<=n;i++)
		sd(goal[i]);

	// for(i=1;i<=n;i++)
	// 	if(init[i]!=goal[i])
	// 		updates[i] = 1;


	L[1] = true;	
	Q.push( 1 );

	while( !Q.empty() )
	{
		temp = Q.front();	Q.pop();

		if( (init[temp]!=goal[temp] && updates[temp]%2==0) || (init[temp]==goal[temp] && updates[temp]%2!=0) )
		{
			updates[temp]++;
			ans.pb(temp);
		}

		for(i=0;i<sz(T[temp]);i++)
		{
			if( L[ T[temp][i] ] == false )
			{

				updates[ T[temp][i] ]+=lazy[temp];

				lazy[ T[temp][i] ] += updates[temp];

				Q.push( T[temp][i] );
				L[ T[temp][i] ] = true;	
			}
		}
	}

	printf("%d\n", sz(ans) );

	for(i=0;i<sz(ans);i++)
		printf("%d\n", ans[i] );

	return 0;
}