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
#define sz(x)       (int)x.size()
#define Mod         1000000007

char S[57][107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,ans = INT_MAX;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
	{
		ss(S[i]);
	}

	m = strlen(S[0]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			S[i][j+m] = S[i][j];
		}
		S[i][j+m] = &#39;\0&#39;;	
	}

	for(j=0;j<m;j++)
	{
		a = j;
		for(i=1;i<n;i++)
		{
			for(l=0;l<m;l++)
			{
				for(k=0;k<m;k++)
				{
					if(S[i][l+k]!=S[0][j+k])
						break;
				}
				if(k>=m)
				{
					a+=l;
					break;
				}
			}
			if(l>=m)
			{
				printf("-1\n");
				return 0;
			}
		}
		ans = min(a,ans);
	}

	printf("%d\n", ans );
	
	return 0;
}