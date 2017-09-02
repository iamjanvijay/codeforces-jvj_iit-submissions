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

vector< pair<int, int> > Events;
stack< int > Stk;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,curspeed;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(x);
		if(x==1 || x==3)
		{
			sd(y);
			Events.pb( mp(x, y) );
		}
		else
		{
			Events.pb( mp(x, -1) );
		}
	}

	a = curspeed = 0;

	Stk.push(INT_MAX);

	for(i=0;i<n;i++)
	{
		if( Events[i].F == 1 )
		{
			curspeed = Events[i].S;
			while(curspeed > Stk.top())
			{
				a++;
				Stk.pop();
			}
		}

		if( Events[i].F == 5 )
		{
			Stk.push( INT_MAX );
		}	

		if( Events[i].F == 3 )
		{
			if(curspeed > Events[i].S)
				a++;
			else
				Stk.push( Events[i].S );
		}		
	}

	while(!Stk.empty())
		Stk.pop();

	Stk.push(1);

	for(i=0;i<n;i++)
	{
		if( Events[i].F == 2 )
		{
			while(Stk.top()!=1)
			{
				a++;
				Stk.pop();
			}
		}

		if( Events[i].F == 4 )
		{
			Stk.push( 1 );
		}	

		if( Events[i].F == 6 )
		{
			Stk.push( 0 );
		}		
	}

	printf("%d\n", a );
	
	return 0;
}