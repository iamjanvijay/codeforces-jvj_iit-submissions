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

char S1[107];
char S2[107];
char S3[107];
int LPS[107];
int DP[107][107][107];
pair< pair<int,int> , pair<int,char> > P[107][107][107];
stack<char> T;

int state(char c, int j)
{
	while(c!=S3[j])
	{
		if(j==0)
			return 0;
		j = LPS[j-1];
	}
	return j+1;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n1,n2,n3,x,y,z,a,b,r,ai,aj,ak;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(S1);	n1=strlen(S1);
	ss(S2);	n2=strlen(S2);
	ss(S3);	n3=strlen(S3);

	LPS[0] = 0;
	i=1;	j=0;
	while(i<n3)
	{
		if( S3[i]==S3[j] )
		{
			LPS[i++] = ++j;
		}
		else
		{
			if(j==0)
			{
				LPS[i++] = 0;
			}
			else
			{
				j = LPS[j-1];
			}
		}
	}	
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			for(k=0;k<n3;k++)
			{
				if( S1[i]==S2[j] )
				{
					l = state(S1[i], k);
					if( l<n3 )
					{
						if(DP[i][j][k]+1>DP[i+1][j+1][l])
						{
							DP[i+1][j+1][l] = DP[i][j][k]+1;
							P[i+1][j+1][l].F.F = i;		P[i+1][j+1][l].F.S = j;		P[i+1][j+1][l].S.F = k;		P[i+1][j+1][l].S.S = S1[i];
						}
						
					}
				}
				if(DP[i][j][k]>DP[i+1][j][k])
				{
					DP[i+1][j][k] = DP[i][j][k];
					P[i+1][j][k].F.F = i;		P[i+1][j][k].F.S = j;		P[i+1][j][k].S.F = k;	P[i+1][j][k].S.S = &#39;\0&#39;;					
				}
				if(DP[i][j][k]>DP[i][j+1][k])
				{
					DP[i][j+1][k] = DP[i][j][k];
					P[i][j+1][k].F.F = i;		P[i][j+1][k].F.S = j;		P[i][j+1][k].S.F = k;	P[i][j+1][k].S.S = &#39;\0&#39;;	
				}
			}
		}
	}

	a = 0;
	for(i=0;i<=n1;i++)
		for(j=0;j<=n2;j++)
			for(k=0;k<=n3;k++)
				if( a < DP[i][j][k] )
				{
					a = DP[i][j][k];
					ai = i;	aj = j;	ak = k;
				}

	if(a==0)
	{
		printf("%d\n", a );		
		return 0;
	}	

	while(DP[ai][aj][ak]!=0)
	{
		i = ai;	j = aj;	k = ak;
		ai = P[i][j][k].F.F;	aj = P[i][j][k].F.S;	ak = P[i][j][k].S.F;
		if(P[i][j][k].S.S!=&#39;\0&#39;)
			T.push( P[i][j][k].S.S );
	}		

	while(!T.empty())
	{
		printf("%c",T.top());
		T.pop();
	}
	printf("\n");

	return 0;
}