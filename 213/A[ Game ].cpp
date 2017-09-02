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

int compReq[207];
bool Depend[207][207];
int DependCnt[207];
bool tempDepend[207][207];
int tempDependCnt[207];

int ans(int strt, int n)
{
	int i, cnt = 0, cur=strt, prevC, newC, ret=0;
	
	while(true)
	{
		prevC = newC = -1;
		while(true)
		{
			for(i=1;i<=n;i++)
			{
				if(tempDependCnt[i]==0 && compReq[i]==cur)
				{
					tempDependCnt[i] = -1;
					newC = i;
					break;
				}
			}

			if(newC==prevC)
				break;

			ret++;
			cnt++;

			for(i=1;i<=n;i++)
			{
				if(tempDepend[i][newC]==true)
				{
					tempDepend[i][newC] = false;
					tempDependCnt[i]--;
				}
			}
			prevC = newC;
		}

		if(cnt==n)
			break;

		ret++;
		cur = 1 + ((cur-1)+1)%3;
	}

	return ret;

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=1;i<=n;i++)
	{
		sd(k);
		compReq[i] = k;
	}

	for(i=1;i<=n;i++)
	{
		sd(k);
		for(j=0;j<k;j++)
		{
			sd(a);
			Depend[i][a] = true;
			DependCnt[i]++;
		}
	}

	for(i=0;i<207;i++)
		for(j=0;j<207;j++)
				tempDepend[i][j] = Depend[i][j];

	a = INT_MAX;
	
	for(k=1;k<=3;k++)
	{
		for(i=0;i<207;i++)
			for(j=0;j<207;j++)
					tempDepend[i][j] = Depend[i][j];

		for(i=0;i<207;i++)
			tempDependCnt[i] = DependCnt[i];		

		a = min(a, ans(k,n));			
	}		
 	
	printf("%d\n", a );

	return 0;
}