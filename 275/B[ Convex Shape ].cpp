#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n 

char S[57][57];
bool canReach[57][57][57][57];
vector< pair<int,int> > V;
int n,m;

int main()
{
	int i,j,k,l;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
		ss(S[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(S[i][j]==&#39;B&#39;)
			{
				V.push_back(make_pair(i,j));
			}

			if(S[i][j]==&#39;W&#39; || j==m-1)
			{
				for(k=0;k<V.size();k++)
				{
					for(l=0;l<V.size();l++)
					{
						canReach[ V[l].first ][ V[l].second ][ V[k].first ][ V[k].second ] = true;
					}
				}
				V.clear();	
			}	
		}	
	}

	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			if(S[i][j]==&#39;B&#39;)
			{
				V.push_back(make_pair(i,j));
			}

			if(S[i][j]==&#39;W&#39; || i==n-1)
			{
				for(k=0;k<V.size();k++)
				{
					for(l=0;l<V.size();l++)
					{
						canReach[ V[l].first ][ V[l].second ][ V[k].first ][ V[k].second ] = true;
					}
				}
				V.clear();	
			}	
		}	
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<n;k++)
			{
				for(l=0;l<m;l++)
				{
					if(S[i][j]==&#39;B&#39; && S[k][l]==&#39;B&#39;)
					{
						if(i==k)
						{
							if(!canReach[i][j][k][l])
							{
								printf("NO\n");
								return 0;
							}	
						}
						else if(j==l)
						{
							if(!canReach[i][j][k][l])
							{
								printf("NO\n");
								return 0;
							}
						}
						else
						{
							if( !( (canReach[i][j][k][j] && canReach[k][j][k][l]) || (canReach[i][j][i][l] && canReach[i][l][k][l]) ) )
							{
								printf("NO\n");
								return 0;
							}
						}	
					}	
				}	
			}	
		}	
	}	

	printf("YES\n");

	return 0;
}