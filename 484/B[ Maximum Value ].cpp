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

int A[200007];
int L[1000007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	if(n==1)
	{
		printf("0\n");
		return 0;
	}

	sort(A,A+n);

	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			for(j=0;j<=A[i];j++)
				L[j] = 1;
		}
		else
		{
			for(j=A[i-1]+1;j<=A[i];j++)
				L[j] = A[i-1];			
		}	
	}

	for(j=A[n-1]+1;j<=1000000;j++)
		L[j] = A[n-1];

	for(i=0;i<n;i++)
	{
		if(i==0|| A[i-1]!=A[i])
		{
			for(j=A[i];j<=A[n-1];j+=A[i])
			{
				if( L[j] >= A[i] )
				{
					a = max(a,L[j]%A[i]);
				}
			}
			a = max(a,A[n-1]%A[i]);
		}
	}

	printf("%d\n", a );
	
	return 0;
}