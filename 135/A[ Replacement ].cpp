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

int A[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	bool 	all1 = true;

	A[0] = 1;

	sd(n);
	for(i=1;i<=n;i++)
	{
		sd(A[i]);
		if(A[i]!=1)
			all1 = false;
	}

	if(all1)
	{
		for(i=1;i<n;i++)
		{
			printf("1 ");
		}
		printf("2\n");
		return 0;
	}

	sort(A+1,A+n+1);

	for(i=1;i<=n;i++)
	{
		printf("%d ", A[i-1] );
	}
	printf("\n");
	
	return 0;
}