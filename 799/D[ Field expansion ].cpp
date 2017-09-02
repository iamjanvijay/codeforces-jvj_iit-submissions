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

ll A[100007];
ll DP[100007][2];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r,h,w;

	slld(a);	slld(b);
	slld(h);	slld(w);

	slld(n);

	for(i=0;i<n;i++)
		slld(A[i]);

	if( ( h>=a && w>=b ) || ( h>=b && w>=a ) )
	{
		printf("0\n");
		return 0;
	}

	sort(A,A+n,greater<int>());

	for(i=0;i<100007;i++)
		DP[i][0] = DP[i][1] = LLONG_MIN;

	DP[h][0] = w;
	DP[w][0] = h;

	k = 0;
	for(i=0;i<n && i<35;i++)
	{
		k=1-k;
		for(j=0;j<=100000LL;j++)
		{
			DP[j][k] = max(DP[j][k],DP[j][1-k]);
			if( DP[j][1-k] != LLONG_MIN )
			{
				DP[ min(j*A[i],100001LL) ][k] = max(DP[ min(j*A[i],100001LL) ][k],DP[j][1-k]);
			}
			if( DP[j][1-k] != LLONG_MIN )
			{
				DP[j][k] = max(DP[j][1-k],min(A[i]*DP[j][1-k],100001LL));
			}
			DP[j][1-k] = LLONG_MIN;			
		}

		for(j=0;j<=100001LL;j++)
		{
			if(DP[j][k]!=LLONG_MIN)
			{
				if( ( j>=a && DP[j][k]>=b ) || ( DP[j][k]>=b && j>=a ) )
				{
					printf("%d\n",i+1);
					return 0;
				}
			}
		}

	}

	printf("-1\n");
	
	return 0;
}