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

char St[1007][1007];
bool Stck[1007][1007];
int Calc[1007][1007];
int n,m;
bool flag = false;

bool isEdge(int i,int j,int x,int y)
{
	return ( St[i][j]==&#39;D&#39; && St[x][y]==&#39;I&#39; ) || ( St[i][j]==&#39;I&#39; && St[x][y]==&#39;M&#39; ) || ( St[i][j]==&#39;M&#39; && St[x][y]==&#39;A&#39; ) || ( St[i][j]==&#39;A&#39; && St[x][y]==&#39;D&#39; );
}

void CalcFun(int i,int j)
{

	if(Stck[i][j])
		flag = true;
	if(flag)
		return;

	if(Calc[i][j])
		return;

	Stck[i][j] = true;

	int cur = 1;

	if(i+1<n && isEdge(i,j,i+1,j))
	{
		CalcFun(i+1,j);
		cur = max(cur,1+Calc[i+1][j]);
	}

	if(i-1>=0 && isEdge(i,j,i-1,j))
	{
		CalcFun(i-1,j);
		cur = max(cur,1+Calc[i-1][j]);
	}	

	if(j+1<m && isEdge(i,j,i,j+1))
	{
		CalcFun(i,j+1);
		cur = max(cur,1+Calc[i][j+1]);
	}

	if(j-1>=0 && isEdge(i,j,i,j-1))
	{
		CalcFun(i,j-1);
		cur = max(cur,1+Calc[i][j-1]);
	}		

	Stck[i][j] = false;

	Calc[i][j] = cur;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,x,y,z,a,b,r,ans=0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);	

	for(i=0;i<n;i++)
		ss(St[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(Calc[i][j]==0)
			{
				CalcFun(i,j);
			}
			if(flag)
				break;
		}
		if(flag)
			break;		
	}

	if(flag)
	{
		printf("Poor Inna!\n");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(St[i][j]==&#39;D&#39;)
				{
					ans = max(ans, Calc[i][j]/4 );
				}
			}
		}

		if(ans==0)
			printf("Poor Dima!\n");
		else
			printf("%d\n", ans );

	}
	
	return 0;
}