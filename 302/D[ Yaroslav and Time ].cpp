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

pair<int, int> P[107];
int A[107];
int Dist[107];

int wt(pair<int, int> &X, pair<int, int> &Y, int &d)
{
	return ( abs(X.F - Y.F) + abs(X.S - Y.S) ) * d;
}

bool chk(int start, int &d, int &n)
{
	int i,j,k;

	for(i=1;i<=n;i++)
		Dist[i] = INT_MIN;

	Dist[1] = start;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(j!=k)
				{
					if( Dist[j] >= 0 && Dist[j] - wt(P[j], P[k], d) >= 0 && Dist[j] - wt(P[j], P[k], d) + A[k] >= 0 && Dist[k] < Dist[j] - wt(P[j], P[k], d) + A[k] )
					{
						Dist[k] = Dist[j] - wt(P[j], P[k], d) + A[k];
					}
				}
			}
		}
	}

	if( Dist[n] >= 0 )
		return true;
	return false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,d,r,fs,ls,md;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(d);

	for(i=2;i<=n-1;i++)
	{
		sd(A[i]);
	}

	for(i=1;i<=n;i++)
	{
		sd(x);	sd(y);
		P[i] = mp(x, y);
	}

	fs = 0;		ls = d*400;

	while( fs+1 < ls )
	{
		md = (fs+ls)/2;

		if( chk(md, d, n) )
			ls = md;
		else
			fs = md;

	}

	if( chk(fs, d, n) )
		printf("%d\n", fs );
	else
		printf("%d\n", ls );
	
	return 0;
}