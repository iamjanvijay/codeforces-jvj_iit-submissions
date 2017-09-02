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

int seieve[1007] = {0};
vector<int> ans;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	seieve[0] = seieve[1] = 1;
	for(i=2;i*i<=n;i++)
		if(seieve[i]==0)
			for(j=i*i;j<=n;j+=i)
				seieve[j] = 1;

	
	for(i=2;i<=n;i++)
		if(seieve[i]==0)
		{
			j = i;
			while(j<=n)
			{
				ans.pb(j);
				j *= i;
			}	
		}
	
	printf("%d\n", sz(ans) );
	for(i=0;i<sz(ans);i++)
		printf("%d ", ans[i] );
	if(sz(ans))
	printf("\n");	

	return 0;
}