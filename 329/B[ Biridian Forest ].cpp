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

char Mat[1007][1007];
int DP[1007][1007];
queue< pair<int,int> > Q;

void BFS(int x,int y,int r,int c)
{
	pair<int,int> t1;

	Q.push( mp(x,y) );
	DP[x][y] = 0;

	while(!Q.empty())
	{
		t1 = Q.front(); Q.pop();

		x = t1.F;	y = t1.S;

		if( x-1>=0 && DP[x-1][y]==-1 && Mat[x-1][y]!=&#39;T&#39; )
		{
			Q.push( mp(x-1,y) );
			DP[x-1][y] = DP[x][y] + 1;
		}

		if( x+1<r && DP[x+1][y]==-1 && Mat[x+1][y]!=&#39;T&#39; )
		{
			Q.push( mp(x+1,y) );
			DP[x+1][y] = DP[x][y] + 1;
		}

		if( y-1>=0 && DP[x][y-1]==-1 && Mat[x][y-1]!=&#39;T&#39; )
		{
			Q.push( mp(x,y-1) );
			DP[x][y-1] = DP[x][y] + 1;
		}

		if( y+1<c && DP[x][y+1]==-1 && Mat[x][y+1]!=&#39;T&#39; )
		{
			Q.push( mp(x,y+1) );
			DP[x][y+1] = DP[x][y] + 1;
		}				

	}	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n=0,x,y,z,a,b,r,c;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(r);	sd(c);
	for(i=0;i<r;i++)
		ss(Mat[i]);

	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			DP[i][j] = -1;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(Mat[i][j]==&#39;E&#39;)
			{
				BFS(i,j,r,c);
				break;
			}
		}
		if(j<c)
			break;
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(Mat[i][j]==&#39;S&#39;)
			{
				m = DP[i][j];	break;
			}
		}
		if(j<c)
			break;
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(&#39;0&#39;<=Mat[i][j] && Mat[i][j]<=&#39;9&#39; && DP[i][j]<=m && DP[i][j]!=-1)
			{
				n+=(Mat[i][j]-&#39;0&#39;);
			}
		}
	}	
	
	printf("%d\n", n );

	return 0;
}