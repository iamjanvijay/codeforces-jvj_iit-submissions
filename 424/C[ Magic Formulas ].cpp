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

int A[1000007];

int fun(int k,int n)
{
	if(n%k==0)
	{
		if((n/k)%2==0)
		{
			// printf("Returning XOR upto : %d\n", 0);
			return 0;
		}
		else
		{
			// printf("Returning XOR upto : %d\n", k-1 );
			return A[ k-1 ];
		}
	}
	else if((n/k)%2==0)
	{
		// printf("Returning XOR upto : %d\n", n - (n/k)*k );
		return A[ n - (n/k)*k ];
	}
	else
	{
		// printf("Returning XOR upto : %d ^ %d\n", k-1, n - (n/k)*k );
		return A[ k-1 ]^A[ n - (n/k)*k ];
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	// while(true)
	// {
	// 	sd(n);	sd(k);
	// 	printf("%d\n", fun(k,n) );
	// }

	sd(n);

	for(i=1;i<=n;i++)
		A[i]=i^A[i-1];

	for(i=1;i<=n;i++)
	{
		sd(k);	a^=k;
	}

	// printf("*** %d\n", a );

	for(i=1;i<=n;i++)
	{
		// printf("***(%d %d) %d\n", i, n,fun(i,n) );
		a^=fun(i,n);
	}

	printf("%d\n", a );
	
	return 0;
}