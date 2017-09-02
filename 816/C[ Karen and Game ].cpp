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

int Mat[107][107];
vector<int> R;
vector<int> C;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			sd(Mat[i][j]);
		}
	}


	if(m>n)
	{	
		for(i=0;i<n;i++)
		{
			k = INT_MAX;

			for(j=0;j<m;j++)
			{
				k = min(k, Mat[i][j]);
			}

			
			for(j=0;j<k;j++)
				R.pb(i);

			for(j=0;j<m;j++)
			{
				Mat[i][j]-=k;
			}
		}

		for(i=0;i<m;i++)
		{
			k = INT_MAX;

			for(j=0;j<n;j++)
			{
				k = min(k, Mat[j][i]);
			}


			for(j=0;j<k;j++)
				C.pb(i);

			for(j=0;j<n;j++)
			{
				Mat[j][i]-=k;
			}
		}
	}
	else
	{
		for(i=0;i<m;i++)
		{
			k = INT_MAX;

			for(j=0;j<n;j++)
			{
				k = min(k, Mat[j][i]);
			}


			for(j=0;j<k;j++)
				C.pb(i);

			for(j=0;j<n;j++)
			{
				Mat[j][i]-=k;
			}
		}

		for(i=0;i<n;i++)
		{
			k = INT_MAX;

			for(j=0;j<m;j++)
			{
				k = min(k, Mat[i][j]);
			}

			
			for(j=0;j<k;j++)
				R.pb(i);

			for(j=0;j<m;j++)
			{
				Mat[i][j]-=k;
			}
		}
		
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(Mat[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}	

	printf("%d\n", sz(C) + sz(R) );

	for(i=0;i<sz(R);i++)
		printf("row %d\n", R[i]+1 );

	for(i=0;i<sz(C);i++)
		printf("col %d\n", C[i]+1 );	
	
	return 0;
}