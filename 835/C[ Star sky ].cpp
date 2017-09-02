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

int A[17][107][107];
vector< int > isStar[107][107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r,q,s,x1,y1,x2,y2,ans,t;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(q);	sd(c);

	for(i=0;i<n;i++)
	{
		sd(x);	sd(y);	sd(s);
		isStar[x][y].pb(s);
		A[0][x][y] += s;
	}
	
	for(t=1;t<=c+1;t++)
	{
		for(i=0;i<=100;i++)
		{
			for(j=0;j<=100;j++)
			{
				for(l=0;l<sz(isStar[i][j]);l++)
				{
					if(isStar[i][j][l]==c)
						isStar[i][j][l] = 0;
					else
						isStar[i][j][l]++;
				}
				for(l=0;l<sz(isStar[i][j]);l++)
				{
					A[t][i][j] += isStar[i][j][l];
				}			
			}
		}
	}

	for(t=0;t<=c+1;t++)
	{
		for(i=1;i<=100;i++)
		{
			for(j=1;j<=100;j++)
			{
				A[t][i][j] = A[t][i][j] + A[t][i-1][j] + A[t][i][j-1] - A[t][i-1][j-1];
			}
		}
	}

	while(q--)
	{
		sd(t);	sd(x1);	sd(y1);	sd(x2);	sd(y2);

		ans = A[t%(c+1)][x2][y2] - A[t%(c+1)][x1-1][y2] - A[t%(c+1)][x2][y1-1] + A[t%(c+1)][x1-1][y1-1];

		printf("%d\n", ans  );
	}

	return 0;
}