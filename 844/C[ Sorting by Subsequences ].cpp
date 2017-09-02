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

pair<int, int> A[100007];
int B[100007];
bool isVis[100007];
vector<int> temp;
vector< vector<int> > ans;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(A[i].F);
		A[i].S = i;
	}

	sort(A+1,A+n+1);

	for(i=1;i<=n;i++)
	{
		B[ A[i].S ] = i;
	}

	for(i=1;i<=n;i++)
	{
		if(isVis[i])
			continue;
		isVis[i] = true;
		temp.clear();
		temp.pb(i);
		j = B[i];
		while(j!=i)
		{
			isVis[j] = true;
			temp.pb(j);
			j = B[j];
		}
		ans.pb(temp);
	}

	printf("%d\n", sz(ans) );
	for(i=0;i<sz(ans);i++)
	{
		printf("%d ", sz(ans[i]) );
		for(j=0;j<sz(ans[i]);j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	
	return 0;
}