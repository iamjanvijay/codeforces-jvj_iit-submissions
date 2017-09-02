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

pair< pair<int,int> , pair<int,int> > P[7];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	bool flag = false;

	x = y = 0;

	for(i=0;i<4;i++)
	{
		sd(P[i].F.F);	sd(P[i].F.S);	sd(P[i].S.F);	sd(P[i].S.S);

		if( P[i].F.F == P[i].S.F )
			y++;
		else if( P[i].F.S == P[i].S.S )
			x++;
		else
			flag = true;
		if( ( P[i].F.F == P[i].S.F ) && ( P[i].F.S == P[i].S.S ) )
			flag = true;
	}

	if(!(x==2 && y==2) || flag)
	{
		printf("NO\n");
		return 0;
	}

	bool flagx,flagy;
	flagx = flagy = false;
	int ymax,ymin,xmax,xmin;

	for(i=0;i<4;i++)
	{

		if( P[i].F.F == P[i].S.F ) // y
		{
			if(!flagy)
			{
				ymin = min(P[i].F.S,P[i].S.S);
				ymax = max(P[i].F.S,P[i].S.S);
				flagy = true;
			}
			else
			{
				if(ymin!=min(P[i].F.S,P[i].S.S) || ymax!=max(P[i].F.S,P[i].S.S))
					flag = true;
			}
		}
		else if( P[i].F.S == P[i].S.S )
		{
			if(!flagx)
			{
				xmin = min(P[i].F.F,P[i].S.F);
				xmax = max(P[i].F.F,P[i].S.F);
				flagx = true;
			}
			else
			{
				if(xmin!=min(P[i].F.F,P[i].S.F) || xmax!=max(P[i].F.F,P[i].S.F))
					flag = true;
			}
		}
	}

	if(flag)
	{
		printf("NO\n");
		return 0;
	}

	bool bxmin,bxmax,bymin,bymax;

	bxmin = bxmax = bymin = bymax = false; 

	for(i=0;i<4;i++)
	{

		if( P[i].F.F == P[i].S.F ) // y
		{
			if( !bxmin && xmin==P[i].F.F)
			{
				bxmin = true;
			}
			else if( !bxmax && xmax==P[i].F.F)
			{
				bxmax = true;
			}
			else
				flag = true;
		}
		else if( P[i].F.S == P[i].S.S )
		{
			if( !bymin && ymin==P[i].F.S)
			{
				bymin = true;
			}
			else if( !bymax && ymax==P[i].F.S)
			{
				bymax = true;
			}
			else
				flag = true;
		}
	}

	if(flag)
	{
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	
	return 0;
}