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

char s[5007];
int nxt[5007][5007];
int dp[5007][5007];
int temp[5007];

void init_nxt()
{
	int i,j,k,l;
	for(i=0;i<5007;i++)
	{
		for(j=0;j<5007;j++)
		{
			nxt[i][j] = -1;
		}
	}
}

int dp_nxt(int i,int j,int n)
{
	if(nxt[i][j]==-1)
	{
		int retVal;
		if(s[i]!=s[j])
			retVal = 0;
		else
			if(i==n-1 || j==n-1)
				retVal = 1;
			else
				retVal = 1+dp_nxt(i+1,j+1,n);
		nxt[j][i] = nxt[i][j] = retVal;

	}
	return nxt[i][j];
}

bool isless(int i,int j,int len)// true if s with i is less
{
	if(i<0 || j<0)
		return false;
	if(nxt[i][j]>=len)
		return false;
	if(s[i+nxt[i][j]] < s[j+nxt[i][j]])
		return true;
	return false;
}

void dp_init(int n)
{
	int i,j,k,l;
	for(i=0;i<n;i++) // start
	{
		for(j=0;j<=n;j++) // len
		{
			if(s[i]==&#39;0&#39;)
				dp[i][j] = 0;
			else if(j==0)
				dp[i][j] = 0;
			else
			{
				if(i==0)
					dp[i][j] = 1;
				else
				{
					// for(k=0; k<j ; k++)
					// {
					// 	if(i-k>=0)
					// 		dp[i][j] += dp[i-k][k];
					// }
					dp[i][j] = temp[j-1];
					if( isless(i-j,i,j) )
						dp[i][j] = (dp[i][j] + dp[i-j][j])%1000000007;
				}
			}
		}

		temp[0] = 0;
		for(j=1;j<=n;j++)
		{
			if(i-j+1>=0)
				temp[j] = (temp[j-1] + dp[i-j+1][j])%1000000007;
			else
				temp[j] = temp[j-1];
		}

	}
}

int main()
{
	int i,j,k,l,p,n;
	sd(n);	ss(s);

	init_nxt();

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(nxt[i][j]==-1)
				if(s[i]!=s[j])
					nxt[j][i] = nxt[i][j] = 0;
				else
					nxt[j][i] = nxt[i][j] = dp_nxt(i,j,n);


    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         printf("%d ",nxt[i][j]);
    //     }
    //     printf("\n");
    // }

	dp_init(n);

	printf("%d\n",temp[n] );

	return 0;
}
