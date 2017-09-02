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

ll A[200007];
ll M[200007][2]; // 0 -> fwd // 1 ->bwd
bool Add[200007][2];
bool V[200007][2];
ll n;

pair<ll,bool> Solver(int src,int dir)
{
	if(src<1 || src>n)
		return mp(0,false);
	if(src==1 && dir==0)
		return mp(-1,false);
	if(src==1 && dir==1)
		return mp(0,true);
	if(V[src][dir]==true)
		return mp(-1,false);
	if(M[src][dir]!=LLONG_MIN)
		return mp(M[src][dir],Add[src][dir]);

	pair<ll,bool> temp;

	V[src][dir] = true;

	if(dir==0)
	{
		temp = Solver(src+A[src],1);
		if(temp.F == -1)
		{
			M[src][0] = -1;
			V[src][dir] = false;
			return temp;
		}
		else if(temp.S)
		{	
			M[src][0] = A[src] + temp.F;	
			Add[src][0] = true;
			V[src][dir] = false;
			return mp(M[src][0],Add[src][0]);
		}
		else
		{
			M[src][0] = A[src] + temp.F;	
			Add[src][0] = false;
			V[src][dir] = false;
			return mp(M[src][0],Add[src][0]);
		}

	}

	if(dir==1)
	{
		temp = Solver(src-A[src],0);
		if(temp.F == -1)
		{
			M[src][1] = -1;
			V[src][dir] = false;
			return temp;
		}
		else if(temp.S)
		{	
			M[src][1] = A[src] + temp.F;	
			Add[src][1] = true;
			V[src][dir] = false;
			return mp(M[src][1],Add[src][1]); 
		}
		else
		{
			M[src][1] = A[src] + temp.F;	
			Add[src][1] = false;
			V[src][dir] = false;
			return mp(M[src][1],Add[src][1]);
		}		
	}	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);
	ll i,j,k,l,m,x,y,z,a,b,r;
	pair<ll,bool> temp;

	slld(n);
	for(i=2;i<=n;i++)
	{	
		slld(A[i]);	
		M[i][0] = LLONG_MIN;	
		M[i][1] = LLONG_MIN; 
	}
	
	for(i=2;i<=n;i++)
	{
		if(M[i][0]==LLONG_MIN)
		{
			Solver(i,0);
		}
		if(M[i][1]==LLONG_MIN)
		{
			Solver(i,1);
		}	
		// printf("%lld(%d) ", M[i][0] , Add[i][0]?(1):(0) );
	}
	// printf("\n");

	for(i=1;i<=n-1;i++)
	{
		if(M[1+i][1]==-1)
			printf("-1\n");
		else if(Add[1+i][1])
			printf("%lld\n", M[1+i][1] + 2*i );
		else
			printf("%lld\n", M[1+i][1] + i );
	}

	return 0;
}