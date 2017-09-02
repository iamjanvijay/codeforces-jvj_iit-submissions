#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sllu(x) scanf("%llu",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n

char S[20];
unsigned ll DP[(1LL<<18)][107];
set<unsigned ll> M[19];
int counts[10];
unsigned ll fact[20];

void init(int n)
{
	int i,j;
	unsigned ll mask=0;

	fact[0] = 1;
	for(i=1;i<=18;i++)
		fact[i] = i*fact[i-1];
	for(i=0;i<n;i++)
		counts[ S[i]-&#39;0&#39; ]++;

	M[0].insert(mask);

	set<unsigned ll>::iterator it;
	for(i=0;i<n;i++)
	{
		for( it = M[i].begin() ; it!=M[i].end() ; it++ )
		{
			mask = *it;

			for(j=0;j<n;j++)
			{
				if( (mask & 1LL<<j) == 0 )
				{
					M[i+1].insert( mask | (1LL<<j) );
				}	
			}

		}
	}

	// for(i=0;i<=n;i++)
	// {
	// 	for( it = M[i].begin() ; it!=M[i].end() ; it++ )
	// 	{
	// 		printf("%llu ", *it );
	// 	}
	// 	printf("\n");
	// }

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	
	unsigned ll mask=0,ans;
	int i,j,k,l,m,n;
	ss(S);	sd(m);
	n = strlen(S);
	init(n);
	for(i=0;i<m;i++)
		DP[mask][i] = 0; 
	DP[mask][0] = 1;

	set<unsigned ll>::iterator it;

	for(i=0;i<=n;i++)
	{
		for( it = M[i].begin() ; it!=M[i].end() ; it++ )
		{
			mask = *it;
			for(j=0;j<n;j++)
			{
				if( ((1LL<<j) & mask) == 0 )
				{
					if(i==0)
					{
						if(S[n-1-j]!=&#39;0&#39;)
						for(l=0;l<m;l++)
						{
							DP[ ((1LL<<j) | mask) ][ (l*10+(S[n-1-j]-&#39;0&#39;))%m ] += DP[ mask ][ l ];
						}


					}
					else
					{
						for(l=0;l<m;l++)
						{
							DP[ ((1LL<<j) | mask) ][ (l*10+(S[n-1-j]-&#39;0&#39;))%m ] += DP[ mask ][ l ];
						}
					}


				}

			}
			// 	for(l=0;l<m;l++)
			// 		printf("%llu %d : %lld   | ", mask,l,DP[ mask ][ l ] );			
			// printf("\n");
		}
	} 
	
	ans = DP[(1LL<<n)-1][0];

	for(i=0;i<10;i++)
		ans/=fact[ counts[i] ];

	printf("%lld\n", ans );

	return 0;
}