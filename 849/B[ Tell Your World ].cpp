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

ll y[1007];
bool inSet[1007];

bool check(int seed, int fs, int n)
{
	int i;
	for(i=0;i<1007;i++)
		inSet[i] = false;

	ll dx = fs-seed;
	ll dy = y[fs]-y[seed];

	for(i=0;i<n;i++)
	{
		if(i==seed || dy*(i-seed) == dx*(y[i]-y[seed]))
			inSet[i] = true;
	}

	int coun = 0;

	for(i=0;i<n;i++)
	{
		if(!inSet[i])
			coun++;
	}
	if(coun==1)
		return true;
	if(coun==0)
		return false;
	int prev = -1;
	for(i=0;i<n;i++)
	{
		if(!inSet[i])
		{
			if(prev==-1)
			{
				prev = i;
			}
			else
			{
				if(! (dy*(i-prev) == dx*(y[i]-y[prev])) )
					return false;
			}
		}
	}
	return true;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,z,a,b,r;

	slld(n);
	for(i=0;i<n;i++)
		slld(y[i]);

	for(i=1;i<n;i++)
	{
		if( check(0,i,n) )
		{
			printf("Yes\n");
			return 0;
		}
		if( i+1<n && check(1,i+1,n) )
		{
			printf("Yes\n");
			return 0;
		}		
	}
	printf("No\n");
	return 0;
}