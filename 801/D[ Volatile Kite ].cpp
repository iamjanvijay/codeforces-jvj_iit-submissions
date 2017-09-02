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

pair<double,double> P[1007];
int n;

bool chk(double d)
{
	int i;	double dist;
	for(i=0;i<n;i++)
	{
		dist = fabs( (P[(i+1+n)%n].S - P[(i-1+n)%n].S)*(P[i].F) - (P[(i+1+n)%n].F - P[(i-1+n)%n].F)*(P[i].S) + (P[(i+1+n)%n].F)*(P[(i-1+n)%n].S) - (P[(i+1+n)%n].S)*(P[(i-1+n)%n].F) ) / sqrt( ((P[(i+1+n)%n].S)-(P[(i-1+n)%n].S))*((P[(i+1+n)%n].S)-(P[(i-1+n)%n].S)) + ((P[(i+1+n)%n].F)-(P[(i-1+n)%n].F))*((P[(i+1+n)%n].F)-(P[(i-1+n)%n].F)) ) ;
		if(2*d>dist)
			return false;
	}
	return true;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
	{
		slf(P[i].F);	slf(P[i].S);
	}

	double first = 0, last = 4000000000, mid;

	while(last-first>0.000001)
	{
		mid = (first+last)/2;

		if(chk(mid))
			first = mid;
		else
			last = mid;
	}	

	printf("%.8lf\n", (first+last)/2 );

	return 0;
}