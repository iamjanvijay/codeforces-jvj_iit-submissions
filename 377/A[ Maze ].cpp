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

char S[507][507];
bool C[507][507];
int n,m,l;

void dfs(int i,int j)
{
	if(l==0)
		return;
	if(C[i][j]==true)
		return;

	C[i][j] = true;
	l--;

	if(i+1<n && S[i+1][j]==&#39;.&#39;)
	{
		dfs(i+1,j);
	}

	if(j+1<m && S[i][j+1]==&#39;.&#39;)
	{
		dfs(i,j+1);
	}	

	if(i-1>=0 && S[i-1][j]==&#39;.&#39;)
	{
		dfs(i-1,j);
	}

	if(j-1>=0 && S[i][j-1]==&#39;.&#39;)
	{
		dfs(i,j-1);
	}	


}

int main()
{
	int i,j,k,z=0;

	sd(n);	sd(m);	sd(l);

	for(i=0;i<n;i++)
		ss(S[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(S[i][j]==&#39;.&#39;)
			{
				z++;
			}
		}	
	}

	l = z-l;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(S[i][j]==&#39;.&#39;)
			{
				dfs(i,j);
				break;
			}
		}	
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{

			if(S[i][j]==&#39;.&#39; && !C[i][j])
			{
				S[i][j]=&#39;X&#39;;
			}
		}	
	}		

	for(i=0;i<n;i++)
		printf("%s\n", S[i] );

	return 0;
}
