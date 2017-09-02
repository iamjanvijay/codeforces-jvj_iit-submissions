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

char M[1007][1007];
char tempM[1007][1007];
vector< pair<int,int> > V;
vector< pair<int,pair<int,int> > > ANS;
int A[1007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,x,y,xc,yc,z,a,b,r,n;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n-1;i++)
	{
		sd(x);	sd(y);
		M[x][y] = 1;
	}

	for(i=1;i<=n;i++)
	{
		a = 0;
		for(j=1;j<=n;j++)
		{
			if(M[i][j]==1)
				a = j;
		}
		V.pb(mp(a,i));
	}

	sort(V.begin(),V.end());

	for(i=1;i<=n;i++)
		A[i] = i;

	for(i=1;i<=n;i++)
	{
		if(A[i]!=V[i-1].S)
		{
			for(j=i;j<=n;j++)
				if(A[j]==V[i-1].S)
					break;
			swap(A[i],A[j]);
			ANS.pb(mp(1,mp(i,j)));	
		}
		for(j=1;j<=n;j++)
		{
			tempM[i][j] = M[V[i-1].S][j];
		}
	}
	

	V.clear();

	for(j=1;j<=n;j++)
	{
		a = n+1;
		for(i=n;i>=1;i--)
		{
			if(tempM[i][j]==1)
				a = i;
		}
		V.pb(mp(a,j));
	}

	sort(V.begin(),V.end());

	for(i=1;i<=n;i++)
		A[i] = i;

	for(j=1;j<=n;j++)
	{
		if(A[j]!= V[j-1].S)
		{
			for(i=j;i<=n;i++)
				if(A[i]==V[j-1].S)
					break;
			swap(A[i],A[j]);
			ANS.pb(mp(2,mp(i,j)));	
		}
		for(i=1;i<=n;i++)
		{
			M[i][j] = tempM[i][V[j-1].S];
		}		
	}

	

	printf("%d\n",sz(ANS));
	for(i=0;i<sz(ANS);i++)
		printf("%d %d %d\n",ANS[i].F,ANS[i].S.F,ANS[i].S.S);

	return 0;
}