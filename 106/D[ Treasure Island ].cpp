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

char S[1007][1007];
bool Filter[1007][1007];
bool isVis[1007][1007];
char Temp[7];
pair<char, int> Dir[100007];
vector<char> ans; 

bool chk(int filx, int fily, int x, int y, int &n, int &m)
{
	if(isVis[x][y])
		return true;
	isVis[x][y] = true;
	if(!Filter[filx][fily])
		return true;
	if(x<0 || x>=n || y<0 || y>=m)
		return false;
	if(S[x][y]==&#39;#&#39;)
		return false;
	else
	{
		bool ans = true;
		ans = ans && chk(filx-1,fily,x-1,y,n,m);
		ans = ans && chk(filx,fily-1,x,y-1,n,m);
		ans = ans && chk(filx+1,fily,x+1,y,n,m);
		ans = ans && chk(filx,fily+1,x,y+1,n,m);
		return ans;
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,maxl,maxr,maxu,maxd,curx,cury,filx,fily;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	sd(n);	sd(m);

	for(i=0;i<n;i++)
		ss(S[i]);

	curx=cury=maxl = maxr = maxu = maxd = 0;
	sd(k);
	for(i=0;i<k;i++)
	{
		ss(Temp);	sd(x);
		Dir[i] = mp(Temp[0], x);
		if(Temp[0]==&#39;N&#39;)
		{
			cury+=x;
		}
		else if(Temp[0]==&#39;S&#39;)
		{
			cury-=x;
		}
		else if(Temp[0]==&#39;E&#39;)
		{
			curx+=x;
		}
		else 
		{
			curx-=x;
		}	
		if(curx>0)
			maxr = max(maxr, curx);
		if(curx<0)
			maxl = min(maxl, curx);	
		if(cury>0)
			maxu = max(maxu, cury);
		if(cury<0)
			maxd = min(maxd, cury);							
	}

	if( maxu-maxd+1 > n || maxr-maxl+1 > m )
	{
		printf("no solution\n");
		return 0;
	}

	filx = maxu+1; fily = -maxl+1;

	Filter[filx][fily] = true;
	x = filx;	y = fily;
	for(i=0;i<k;i++)
	{
		l = Dir[i].S;
		if(Dir[i].F==&#39;N&#39;)
		{
			while(l>0)
			{
				x--;	l--;
				Filter[x][y] = true;
			}
		}
		else if(Dir[i].F==&#39;S&#39;)
		{
			while(l>0)
			{
				x++;	l--;
				Filter[x][y] = true;
			}
		}
		else if(Dir[i].F==&#39;E&#39;)
		{
			while(l>0)
			{
				y++;	l--;
				Filter[x][y] = true;
			}
		}
		else 
		{
			while(l>0)
			{
				y--;	l--;
				Filter[x][y] = true;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(S[i][j]>=&#39;A&#39; && S[i][j]<=&#39;Z&#39;)
			{
				for(a=0;a<1007;a++)
					for(b=0;b<1007;b++)
						isVis[a][b] = false;
				if( chk(filx, fily, i, j, n, m) )
					ans.pb( S[i][j] );
			}
		}
	}

	if(sz(ans)==0)
	{
		printf("no solution\n");
		return 0;
	}

	sort(ans.begin(), ans.end());
	for(i=0;i<sz(ans);i++)
	{
		printf("%c", ans[i]);
	}
	printf("\n");

	return 0;
}