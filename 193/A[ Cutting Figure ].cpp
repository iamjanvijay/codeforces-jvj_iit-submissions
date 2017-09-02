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

char M[57][57];
bool vis[57][57];

void dfs(int i, int j, int &n, int &m)
{
	if(vis[i][j] || M[i][j]!=&#39;#&#39;)
		return;

	vis[i][j] = true;

	if(i-1>=0)
		dfs(i-1,j,n,m);
	if(i+1<n)
		dfs(i+1,j,n,m);
	if(j-1>=0)
		dfs(i,j-1,n,m);
	if(j+1<m)
		dfs(i,j+1,n,m);
}

bool isConnected(int n, int m)
{
	int i,j; bool connect=true;

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			vis[i][j] = false;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(M[i][j]==&#39;#&#39;)
				break;
		}
		if(j<m)
			break;
	}

	dfs(i,j,n,m);

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(vis[i][j]==false && M[i][j]==&#39;#&#39;)
				connect = false;
	return connect;				
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
		ss(M[i]);

	a = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(M[i][j]==&#39;#&#39;)
				a++;
		}
	}

	if(a==0 || a==1 || a==2)
	{
		printf("-1\n");
		return 0;
	}

	bool answerIs1 = false;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(M[i][j]==&#39;#&#39;)
			{
				M[i][j] = &#39;.&#39;;
				if( !isConnected(n,m) )
				{
					answerIs1 = true;
					break;
				}
				M[i][j] = &#39;#&#39;;
			}
		}
		if(answerIs1)
			break;
	}

	if(answerIs1)
		printf("1\n");
	else
		printf("2\n");
	
	return 0;
}