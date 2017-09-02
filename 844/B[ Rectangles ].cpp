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

int Mat[57][57];
int DP[57][57];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,o,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			sd(Mat[i][j]);
		}
	}
	
	for(i=0;i<n;i++)
	{
		z = 0; o = 0;
		for(j=0;j<m;j++)
		{
			if(Mat[i][j]==0)
				DP[i][j] = z++;
			else
				DP[i][j] = o++;
		}
	}

	ll ans = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ans += 1LL<<(DP[i][j]); 
		}
	}	

	for(j=0;j<m;j++)
	{
		z = 0; o = 0;
		for(i=0;i<n;i++)
		{
			if(Mat[i][j]==0)
				DP[i][j] = z++;
			else
				DP[i][j] = o++;
		}
	}	

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ans += ((1LL<<(DP[i][j]))-1); 
		}
	}	

	printf("%lld\n", ans );

	return 0;
}