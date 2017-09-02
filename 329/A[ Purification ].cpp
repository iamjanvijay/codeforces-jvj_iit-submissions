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

char St[107][107];
bool isRow,isCol;
int ans[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		ss(St[i]);

	for(i=0;i<n && (!isRow);i++)
	{
		bool flag = true;
		for(j=0;j<n;j++)
		{
			if(St[i][j]!=&#39;E&#39;)
			{
				ans[i] = j;
				flag = false;
				break;
			}
		}
		isRow = flag;
	}

	if(!isRow)
	{
		for(i=0;i<n;i++)
			printf("%d %d\n", i+1, ans[i]+1 );
		return 0;
	}

	for(i=0;i<n && (!isCol);i++)
	{
		bool flag = true;
		for(j=0;j<n;j++)
		{
			if(St[j][i]!=&#39;E&#39;)
			{
				ans[i] = j;
				flag = false;
				break;
			}
		}
		isCol = flag;
	}

	if(!isCol)
	{
		for(i=0;i<n;i++)
			printf("%d %d\n",ans[i]+1 , i+1 );
		return 0;
	}

	printf("-1\n");	
	
	return 0;
}