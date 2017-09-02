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

int DP[2][507][507];
int A[507];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r,mod;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	sd(n);	sd(m);	sd(b);	sd(mod);

	for(i=1;i<=n;i++)
		sd(A[i]);

	c = 0;
	DP[0][0][0] = 1;

	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			for(k=0;k<=b;k++)
				DP[1-c][j][k] = 0;
		for(j=0;j<=m;j++)
			for(k=0;k<=b;k++)
			{
				DP[1-c][j][k] = (DP[1-c][j][k] + DP[c][j][k])%mod;
				if(k+A[i]<=b)
					DP[c][j+1][k+A[i]] = (DP[c][j+1][k+A[i]] + DP[c][j][k])%mod;
			}
		c=1-c;	
	}

	a = 0;
	for(k=0;k<=b;k++)
		a = (a + DP[c][m][k])%mod;

	printf("%d\n", a );

	return 0;
}