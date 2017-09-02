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

int  Ans[27][1507];
int  Count[27];
char P[1507];
char Temp[7];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,q;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	ss(P);

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			Count[ P[j] - &#39;a&#39; ]++;
			for(l=0;l<26;l++)
			{
				Ans[l][ (j-i+1)-Count[l] ] = max( Ans[l][ (j-i+1)-Count[l] ] , j-i+1 );
			}
		}

		for(j=0;j<26;j++)
		{
			Count[j] = 0;
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++)
		{
			Ans[j][i] = max(Ans[j][i],Ans[j][i-1]);
		}
	}


	sd(q);

	for(i=0;i<q;i++)
	{
		sd(m);	ss(Temp);

		printf("%d\n", Ans[Temp[0]-&#39;a&#39;][m] );

	}
	
	return 0;
}