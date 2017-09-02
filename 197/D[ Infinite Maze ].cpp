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

char s[1507][1507];
pair<int, int> isVis[1507][1507];

bool dfs(int i, int j, int &n, int &m)
{
	int x = (i>=0)?(i%n):(((n-1)*((-i)%n))%n);
	int y = (j>=0)?(j%m):(((m-1)*((-j)%m))%m);

	if(s[x][y]==&#39;#&#39; || isVis[x][y]==mp(i,j))
		return false;
	if(isVis[x][y]!=mp(-1,-1))
		return true;
	isVis[x][y] = mp(i,j);
	bool isInf = false;
	isInf |= dfs(i-1, j, n, m);
	isInf |= dfs(i+1, j, n, m);
	isInf |= dfs(i, j-1, n, m);
	isInf |= dfs(i, j+1, n, m);
	return isInf;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	bool isInf;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			isVis[i][j] = mp(-1, -1);

	for(i=0;i<n;i++)
		ss(s[i]);

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(s[i][j]==&#39;S&#39;)
				isInf = dfs(i, j, n, m);

	if(isInf)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}