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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	if( (n==1 && k!=0) || (n/2 > k) )
	{
		printf("-1\n");
		return 0;
	}

	if(n==1 && k==0)
	{
		printf("%d\n",1000000000 );
		return 0;
	}	

	for(i=1,j=1;i<(n/2);i++,j+=2)
	{
		printf("%d %d ", j,j+1 );
		k--;
	}

	printf("%d %d", ( (j%k==0)?(j/k):(j/k+1) )*k , ( ((j%k==0)?(j/k):(j/k+1)) + 1 )*k );

	if(n%2!=0)
		printf(" %d\n",1000000000 );
	else
		printf("\n");
		
	return 0;
}