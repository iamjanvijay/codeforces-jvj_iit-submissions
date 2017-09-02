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

	int i,j,k,l,m,n,x,y,z,a,b,r,f;
	double inc = 180,ang;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	slf(ang);

	f = 1; l = n-2;
	while(f+1<l)
	{
		m = (f+l)/2;

		if( inc*m/n <= ang )
			f = m;
		else
			l = m;
	}

	if( fabs(inc*l/n - ang) < fabs(inc*f/n - ang) )
		a = l;
	else
		a = f;

	printf("%d 1 %d\n", n, n-a );
	
	return 0;
}