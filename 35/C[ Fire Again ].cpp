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

queue< pair< pair<int,int> , int > > Q;
int Count[2007][2007];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	pair< pair<int,int> , int > temp;

	for(i=0;i<2007;i++)
		for(j=0;j<2007;j++)
			Count[i][j] = INT_MAX;

	sd(n);	sd(m);

	sd(k);

	for(i=0;i<k;i++)
	{
		sd(x);	sd(y);
		Q.push( mp( mp(x,y) , 0 ) );
		Count[x][y] = 0;
	}

	while(!Q.empty())
	{
		temp = Q.front();	Q.pop();

		x = temp.F.F;	y = temp.F.S;	a = temp.S;

		if( x+1<=n && Count[x+1][y]==INT_MAX)
		{
			Q.push( mp( mp(x+1,y) , a+1 ) );
			Count[x+1][y] = a+1;
		}

		if( y+1<=m && Count[x][y+1]==INT_MAX)
		{
			Q.push( mp( mp(x,y+1) , a+1 ) );
			Count[x][y+1] = a+1;
		}

		if( x-1>=1 && Count[x-1][y]==INT_MAX)
		{
			Q.push( mp( mp(x-1,y) , a+1 ) );
			Count[x-1][y] = a+1;
		}

		if( y-1>=1 && Count[x][y-1]==INT_MAX)
		{
			Q.push( mp( mp(x,y-1) , a+1 ) );
			Count[x][y-1] = a+1;
		}

	}

	a = -1;	

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if( Count[i][j] > a )
			{
				a = Count[i][j];
				x = i;	y = j;
			}
		}
	}

	printf("%d %d\n", x, y );

	return 0;
}