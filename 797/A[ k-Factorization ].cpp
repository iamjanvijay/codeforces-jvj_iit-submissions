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

vector<int> V;
 
int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,o,p,q,x,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	x = n;
	for(i=2;i*i<=n;i++)
	{
		while(x%i==0)
		{
			V.pb(i);	x/=i;
		}
	}

	if(x!=1)
		V.pb(x);

	if(sz(V)<k)
	{
		printf("-1\n");
	}
	else
	{
		for(i=0;i<k-1;i++)
			printf("%d ", V[i] );
		a = 1;
		for(i;i<sz(V);i++)
			a *= V[i];

		printf("%d", a );
		printf("\n");
	}
	
	return 0;
}