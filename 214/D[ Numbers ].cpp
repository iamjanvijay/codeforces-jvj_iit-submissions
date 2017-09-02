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

int Mod=1000000007;
int C[107][107];
int F[107][17];
bool isCalc[107][17];
int A[17];

int ans(int n, int k)
{
	if(isCalc[n][k])
		return F[n][k];

	isCalc[n][k] = true;
	
	if(k==9)
	{
		if(n>=A[k])
			F[n][k] = 1;
		else
			F[n][k] = 0;

		return F[n][k];
	}	
	
	for(int i=A[k];i<=n;i++)
	{
		if(k==0)
			F[n][k] = ( F[n][k] + 1LL * ans(n-i, k+1) * C[n-1][i] )%Mod;
		else
			F[n][k] = ( F[n][k] + 1LL * ans(n-i, k+1) * C[n][i] )%Mod;
	}
	return F[n][k];
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	C[0][0] = 1;
	for(i=1;i<=100;i++)
	{
		C[i][0] = C[i][i] = 1;
		for(j=1;j<i;j++)
		{
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%Mod;
		}
	}

	sd(n);
	for(x=0,i=0;i<10;i++)
	{
		sd(A[i]);
		x += A[i];
	}

	a = 0;
	for(i=x;i<=n;i++)
	{
		a = (a + ans(i, 0))%Mod;
	}

	printf("%d\n", a );

	return 0;
}