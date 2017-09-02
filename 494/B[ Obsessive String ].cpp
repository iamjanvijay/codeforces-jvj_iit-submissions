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
#define sz(x)       (int)x.size()

ll Mod=1000000007;
char S[100007];
char P[100007];
int A[100007];
int LPS[100007];
// ll DP[100007];
ll DP1[100007];
ll DP2[100007];
ll DP3[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	ll ans = 0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(S);	ss(P);	n=strlen(S);	m=strlen(P);

	LPS[0] = 0;
	for(j=0,i=1;i<m;i++)
	{
		while(P[i]!=P[j])
		{
			if(j==0)
			{
				j = -1;
				break;
			}
			j = LPS[j-1];
		}
		LPS[i] = ++j;
	}

	i = j = 0;
	while(i<n)
	{

		if(S[i]==P[j])
		{
			if(j==m-1)
			{
				A[i] = 1;
				i++;	j = LPS[j];
			}
			else
			{	
				i++;	j++;
			}
		}
		else
		{
			if(j==0)
			{
				i++;
			}
			else
			{
				j = LPS[j-1];
			}
		}
	}

	// for(i=0;i<n;i++)
	// 	printf("%d ", A[i] );
	// printf("\n");

	DP1[0] = 0;	DP3[0] = DP2[0] = 1;
	
	for(i=0;i<n;i++)
	{
		if(A[i]==1)
		{
			DP1[i+1] = DP3[i-m+1];
		}
		else
		{
			DP1[i+1] = DP1[i];
		}
		DP2[i+1] = (DP2[i] + DP1[i+1])%Mod;
		DP3[i+1] = (DP3[i] + DP2[i+1])%Mod;
	}

	for(i=0;i<=n;i++)
		ans = (ans + DP1[i])%Mod;

	// for(i=0;i<=n;i++)
	// 	printf("%d ", DP1[i] );
	// printf("\n");
	// for(i=0;i<=n;i++)
	// 	printf("%d ", DP2[i] );	
	// printf("\n");
	// for(i=0;i<=n;i++)
	// 	printf("%d ", DP3[i] );	
	// printf("\n");	
	
	printf("%lld\n", ans );

	return 0;
}