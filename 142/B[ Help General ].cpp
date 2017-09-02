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
	
	sd(n);	sd(m);

	if(n==1 || m==1)
	{
		printf("%d\n", max(n,m) );
		return 0;
	}

	if(n==2 || m==2)
	{
		printf("%d\n",  2*(2*(max(m,n)/4) + min(max(m,n)%4, 2)) );
		return 0;
	}

	if( (n*m)%2==0 )
		printf("%d\n", (n*m)/2 );
	else
		printf("%d\n", (n*m)/2+1 );

	return 0;
}