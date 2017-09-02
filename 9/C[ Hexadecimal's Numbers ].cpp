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

int A[10];
vi V;
int baseConv(int x)
{
	int i=0,n=0;
	
	while(i<=9)
	{
		if( ( (1<<i) & x ) != 0 )
			n+=A[i];
		i++;
	}

	return n;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	A[0] = 1;
	for(i=1;i<=9;i++)
		A[i]=10*A[i-1];

	i=1;	
	while(i<=513)
	{
		k = baseConv(i);
		// if(i<=10)
		// printf("%d ", k );
		V.pb(k);	i++;
	}

	sd(n);

	vi::iterator it = upper_bound(V.begin(), V.end(),n);	

	printf("%d\n", (it - V.begin() ) );
	
	return 0;
}