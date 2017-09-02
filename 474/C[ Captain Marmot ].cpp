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

int X[7],Y[7],A[7],B[7];
ll D[7];
pair<int,int> P[4];

ll distSq( pair<int,int> p1, pair<int,int> p2 )
{
	return (ll)((p1.F) - (p2.F))*(ll)((p1.F) - (ll)(p2.F)) + ((p1.S) - (ll)(p2.S))*((p1.S) - (p2.S));  
}

bool isSquare( )
{
	if(P[0]==P[1] && P[1]==P[2] && P[2]==P[3])
		return false;
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			D[j] = distSq( P[i], P[j] );
			// if(D[j]<0)
			// 	printf("%d : %d,%d\n", D[j], (P[i].F) - (P[j].F), (P[i].S) - (P[j].S) );
		}
		sort(D,D+4);
		if( !( D[0]==0 && D[1]==D[2] && 2*D[1]==D[3] ) )
			return false;
	}
	return true;
} 

int miniCalc()
{
	int m1,m2,m3,m4,ans=INT_MAX,x,y;
	for(m1=0;m1<4;m1++)
	{
		for(m2=0;m2<4;m2++)
		{
			for(m3=0;m3<4;m3++)
			{
				for(m4=0;m4<4;m4++)
				{
					P[0].F = X[0];	P[0].S = Y[0];
					P[1].F = X[1];	P[1].S = Y[1];
					P[2].F = X[2];	P[2].S = Y[2];
					P[3].F = X[3];	P[3].S = Y[3];	
					
					if(isSquare())
					{
						// printf("YES\n");
						ans = min(ans,m1+m2+m3+m4);
					}
					x = -(Y[3]-B[3])+A[3];	y = (X[3]-A[3])+B[3];
					X[3] = x;	Y[3] = y;					
				}
				x = -(Y[2]-B[2])+A[2];	y = (X[2]-A[2])+B[2];
				X[2] = x;	Y[2] = y;				
			}
			x = -(Y[1]-B[1])+A[1];	y = (X[1]-A[1])+B[1];
			X[1] = x;	Y[1] = y;			
		}
		x = -(Y[0]-B[0])+A[0];	y = (X[0]-A[0])+B[0];
		X[0] = x;	Y[0] = y;		
	}
	return ans;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=1;i<=n;i++)
	{
		sd(X[0]);	sd(Y[0]);	sd(A[0]);	sd(B[0]);
		sd(X[1]);	sd(Y[1]);	sd(A[1]);	sd(B[1]);
		sd(X[2]);	sd(Y[2]);	sd(A[2]);	sd(B[2]);
		sd(X[3]);	sd(Y[3]);	sd(A[3]);	sd(B[3]);	

		r = miniCalc();

		if(r==INT_MAX)
			printf("-1\n");
		else
			printf("%d\n",r );
	}
	
	return 0;
}

// 1
// -1 1 -9999 9999
// 3 3 10000 10000
// 3 -3 10000 -10000
// -1 -1 -9999 -9999