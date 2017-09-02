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

	int i,j,k,l,m,n,x,y,z,a,b,c,s,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	sd(s);
	sd(a);	sd(b);	sd(c);

	if(a+b+c == 0)
	{
		printf("%0.10lf %0.10lf %0.10lf\n", (double) s / 3, (double) s / 3, (double) s / 3 );	
		return 0;
	}

	printf("%0.10lf %0.10lf %0.10lf\n", (double) s * a / (a+b+c), (double) s * b / (a+b+c), (double) s * c / (a+b+c) );

	return 0;
}