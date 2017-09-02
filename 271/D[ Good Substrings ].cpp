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

char S[1507];
int DP[1507];
int Code[1507][1507];
int Code1[1507][1507];
ll Pow[1507];
ll Pow1[1507];
char G[30];
ll base = 31;
ll base1 = 10103;
ll Mod = 1000000007;
ll Mod1 = 100060001;
set<pair<int,int> > Coll[1507];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,ans=0;

	ll p=1;
	for(i=0;i<1507;i++)
	{
		Pow[i] = p;
		p = (p*base)%Mod;
	}

	p=1;
	for(i=0;i<1507;i++)
	{
		Pow1[i] = p;
		p = (p*base1)%Mod1;
	}	

	ss(S+1);	
	ss(G);
	sd(k);

	for(i=1;S[i]!=&#39;\0&#39;;i++)
	{
		DP[i] = 1 - (G[ S[i] - &#39;a&#39; ]-&#39;0&#39;);
		DP[i] += DP[i-1];
	}

	n = i-1;

	for(l=1;l<=n;l++)
	{
		p = 0;
		for(i=1;i<=l;i++)
		{
			p = (p + Pow[l-i] * ( (ll)S[i] -&#39;a&#39; )) %Mod; 
		}
		Code[1][l] = p;
		// printf("* %d %d : %lld\n", 1,l,p );
		for(j=1,i;i<=n;i++,j++)
		{
			p = (p - ( Pow[l-1] * ((ll)S[j] -&#39;a&#39; ) )%Mod + Mod) %Mod;
			p = (p*base)%Mod;
			p = (p + Pow[0] * ((ll)S[i] -&#39;a&#39; ) ) %Mod;
			Code[j+1][i] = p;
			// printf("* %d %d : %lld\n", j+1,i,p );
		}	
	}	

	for(l=1;l<=n;l++)
	{
		p = 0;
		for(i=1;i<=l;i++)
		{
			p = (p + Pow1[l-i] * ( (ll)S[i] )) %Mod1; 
		}
		Code1[1][l] = p;
		// printf("* %d %d : %lld\n", 1,l,p );
		for(j=1,i;i<=n;i++,j++)
		{
			p = (p - ( Pow1[l-1] * ((ll)S[j] ) )%Mod1 + Mod1) %Mod1;
			p = (p*base1)%Mod1;
			p = (p + Pow1[0] * ((ll)S[i] ) ) %Mod1;
			Code1[j+1][i] = p;
			// printf("* %d %d : %lld\n", j+1,i,p );
		}	
	}		

	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if( DP[j]-DP[i-1] <= k )
			{
				// printf("* %d %d\n", i, j );
				if( Coll[j-i+1].count( make_pair(Code[i][j],Code1[i][j]) ) == 0 )
				{
					ans++;
					Coll[j-i+1].insert( make_pair(Code[i][j],Code1[i][j]) );
				}
			}
		}	
	}	
	
	printf("%d\n", ans );

	return 0;
}



