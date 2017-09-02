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

double x2,y2,z2;

bool inside(double x, double y, double z)
{
	if( 0<=x && x<=x2 && 0<=y && y<=y2 &&  0<=z && z<=z2 )
		return true;
	return false;
}

bool chk(double x,double y,double z,double x1,double y1,double z1)
{
	while( (x1-x)*(x1-x) + (y1-y)*(y1-y) + (z1-z)*(z1-z) > 0.00001 )
	{
		if( inside(x,y,z) )
			return false;
		x = (x1+x)/2;	y = (y1+y)/2;	z = (z1+z)/2;
	}
	return true;
}

int A[10];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,a,b;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	double x,y,z;

	slf(x);	slf(y);	slf(z);
	slf(x2);	slf(y2);	slf(z2);

	for(i=0;i<6;i++)
		sd(A[i]);

	a = 0;

	if( chk(x,y,z,x2/2,0,z2/2) )
	{
		// printf("*1\n");
		a += A[0];
	}

	if( chk(x,y,z,x2/2,y2,z2/2) )
	{
		// printf("*2\n");
		a += A[1];
	}

	if( chk(x,y,z,x2/2,y2/2,0) )
	{
		// printf("*3\n");
		a += A[2];
	}

	if( chk(x,y,z,x2/2,y2/2,z2) )
	{
		// printf("*4\n");
		a += A[3];
	}

	if( chk(x,y,z,0,y2/2,z2/2) )
	{
		// printf("*5\n");
		a += A[4];
	}

	if( chk(x,y,z,x2,y2/2,z2/2) )
	{
		// printf("*6\n");
		a += A[5];
	}

	printf("%d\n", a );										
	
	return 0;
}