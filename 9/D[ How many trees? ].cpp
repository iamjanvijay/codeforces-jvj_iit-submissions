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

ll DP[37][37] = {0};

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll h,n,a,ni,hi,li,ri,hli,hri;

	slld(n);	slld(h);

	DP[0][0] = 1;

	for(ni=1;ni<=35;ni++)
	{
		for(hi=1;hi<=35;hi++)
		{
			a = 0;
			for(li=0;li<=ni-1;li++)
			{
				ri = ni-1-li;
				for(hli=hi-1,hri=0;hri<hi-1;hri++)
				{
					a = a + DP[li][hli]*DP[ri][hri];
				}
				for(hri=hi-1,hli=0;hli<hi-1;hli++)
				{
					a = a + DP[li][hli]*DP[ri][hri];
				}
				hli=hi-1;		hri=hi-1;
				a = a + DP[li][hli]*DP[ri][hri];
			}
			DP[ni][hi] = a;
		}
	}

	a = 0;
	for(hi=h;hi<=n;hi++)
	{
		a += DP[n][hi] ;
	}

	printf("%lld\n", a );
	
	return 0;
}