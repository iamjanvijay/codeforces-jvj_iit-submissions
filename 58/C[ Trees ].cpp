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
map<int,int> M;
map<int,int>::iterator it;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	for(a=0,i=0;i<n;i++)
	{
		k = min(i, n-1-i);
		if( A[i]-k > 0 )
			M[ A[i]-k ]++;
	}

	a = 0;
	for(it=M.begin();it!=M.end();it++)
	{
		a = max(a, it->second);
	}

	printf("%d\n", n-a );

	return 0;
}