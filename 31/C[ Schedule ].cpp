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

vector< pair< pair<int,int> , int > > Groups;
vector<int> ans;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	bool flag;
	int i,j,k,f,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(f);	sd(l);
		Groups.pb( mp(mp(f,l) , i+1) );
	}

	sort(Groups.begin(), Groups.end());

	for(i=0;i<n;i++)
	{
		flag = true;

		for(j=1;j<n;j++)
		{
			if(i==0 && j==1)
				continue;
			if(j==i)
				continue;
			if(j-1==i)
			{
				if(Groups[j].F.F < Groups[j-2].F.S)
				{
					flag = false;
					break;
				}
			}
			else
			{
				if(Groups[j].F.F < Groups[j-1].F.S)
				{
					flag = false;
					break;
				}
			}
		}

		if(flag)
			ans.pb( Groups[i].S );

	}	

	sort(ans.begin(), ans.end());

	printf("%d\n", sz(ans) );
	for(i=0;i<sz(ans);i++)
		printf("%d ", ans[i] );
	if(sz(ans)!=0)
		printf("\n");
	
	return 0;
}