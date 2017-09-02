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

int c[107];
int DP[107][10007];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(x);

	for(i=1;i<=n;i++)
		sd(c[i]);

	for(i=n;i>=1;i--)
	{
		c[i] = (n-i+1)*c[i];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=x;j++)
		{
			if(j+c[i+1]<=x)
				DP[i+1][j+c[i+1]] = max(DP[i+1][j+c[i+1]], 1+DP[i][j]);
			DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
		}
	}

	a = 0;
	for(j=0;j<=x;j++)
		a = max(a, DP[n][j]);

	printf("%d\n", a );

	return 0;
}