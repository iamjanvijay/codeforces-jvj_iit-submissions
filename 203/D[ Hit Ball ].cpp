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


void modify(double &x, double &y, double &z, double &vx, double &vy, double &vz, double &a, double &b)
{
	double tempx, tempy, tempz, t, mint;

	mint = DBL_MAX;

	if(vz!=0)
	{
		t = -z/vz;
		if(t>0)
			mint = min(t, mint);
	}

	if(vz!=0)
	{
		t = (b-z)/vz;
		if(t>0)
			mint = min(t, mint);
	}

	if(vx!=0)
	{
		t = -x/vx;
		if(t>0)
			mint = min(t, mint);
	}

	if(vx!=0)
	{
		t = (a-x)/vx;
		if(t>0)
			mint = min(t, mint);
	}

	if(vy!=0)
	{
		t = -y/vy;
		if(t>0)
			mint = min(t, mint);		
	}

	t = mint;

	x = x + t*vx;	y = y + t*vy;	z = z + t*vz;

	if( x==a )
		vx = -fabs(vx);
	else if(fabs(x)<0.000000000001)
		vx = fabs(vx);

	if( z==b )
		vz = -fabs(vz);
	else if(fabs(z)<0.000000000001)
		vz = fabs(vz);	

	if(fabs(y)<0.000000000001)
		vy = fabs(vy);					
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,n,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	double a, b, m, vx, vy, vz, x, y, z;

	slf(a);	slf(b);	slf(m);
	slf(vx);	slf(vy);	slf(vz);

	x = a/2;		y = m;		z = 0;
	// i = 0;
	while( fabs(y)>0.000000000001 )
	{
		// if(++i>10)
		// 	break;
		// printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf FabsY : %.10lf\n", x, y, z, vx, vy, vz, fabs(y) );
		modify(x, y, z, vx, vy, vz, a, b);
	}
	// printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, z, vx, vy, vz );
	
	printf("%.10lf %.10lf\n", x, z );

	return 0;
}