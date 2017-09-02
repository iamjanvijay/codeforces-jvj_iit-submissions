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

vector< pair<double, double> > R;
vector< pair<double, double> > temp;

pair<double, double> transform( pair<double, double> P, double cosa, double sina)
{
	double x = P.F, y = P.S;
	return mp( x*cosa - y*sina , x*sina + y*cosa );
}

double area( pair<double, double> P1, pair<double, double> P2)
{
	double x1,x2,x3,y1,y2,y3;
	x1 = 0;	y1 = 0;
	x2 = P1.F;	y2 = P1.S;
	x3 = P2.F;	y3 = P2.S;

	return fabs( x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3 ) / 2;

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	double w,h,a,cosa,sina,pi=3.141592653589793238,ans=0;
	bool insidev1, insidev2;

	slf(w);	slf(h);	slf(a);

	R.pb( mp(w/2,h/2) );
	R.pb( mp(-w/2,h/2) );
	R.pb( mp(-w/2,-h/2) );
	R.pb( mp(w/2,-h/2) );

	cosa = cos( a * pi / 180 );
	sina = sin( a * pi / 180 );

	for(i=0;i<4;i++)
	{
		R[i] = transform(R[i], cosa, sina);
	}	

	// for(i=0;i<4;i++)
	// {
	// 	printf("%lf %lf\n", R[i].F, R[i].S );
	// }
	// printf("DONE\n");

	temp.clear();
	for(i=0;i<sz(R);i++)
	{
		insidev1 = (R[i].F <= w/2);
		insidev2 = (R[(i+1)%sz(R)].F <= w/2);
		if(!insidev1 && insidev2)
		{
			temp.pb( mp(w/2, R[i].S + (w/2 - R[i].F) * (R[(i+1)%sz(R)].S - R[i].S) / (R[(i+1)%sz(R)].F - R[i].F) ) );
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && insidev2)
		{
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && !insidev2)
		{
			temp.pb( mp(w/2, R[i].S + (w/2 - R[i].F) * (R[(i+1)%sz(R)].S - R[i].S) / (R[(i+1)%sz(R)].F - R[i].F) ) );
		}
	}
	R.clear();
	for(i=0;i<sz(temp);i++)
	{
		R.pb(temp[i]);
	}

	// for(i=0;i<sz(R);i++)
	// {
	// 	printf("%lf %lf\n", R[i].F, R[i].S );
	// }
	// printf("DONE\n");	

	temp.clear();
	for(i=0;i<sz(R);i++)
	{
		insidev1 = (R[i].F >= -w/2);
		insidev2 = (R[(i+1)%sz(R)].F >= -w/2);
		if(!insidev1 && insidev2)
		{
			temp.pb( mp(-w/2, R[i].S + (-w/2 - R[i].F) * (R[(i+1)%sz(R)].S - R[i].S) / (R[(i+1)%sz(R)].F - R[i].F) ) );
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && insidev2)
		{
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && !insidev2)
		{
			temp.pb( mp(-w/2, R[i].S + (-w/2 - R[i].F) * (R[(i+1)%sz(R)].S - R[i].S) / (R[(i+1)%sz(R)].F - R[i].F) ) );
		}
	}
	R.clear();
	for(i=0;i<sz(temp);i++)
	{
		R.pb(temp[i]);
	}	

	// for(i=0;i<sz(R);i++)
	// {
	// 	printf("%lf %lf\n", R[i].F, R[i].S );
	// }
	// printf("DONE\n");	

	temp.clear();
	for(i=0;i<sz(R);i++)
	{
		insidev1 = (R[i].S <= h/2);
		insidev2 = (R[(i+1)%sz(R)].S <= h/2);
		if(!insidev1 && insidev2)
		{
			temp.pb( mp( R[i].F + (h/2 - R[i].S) * (R[(i+1)%sz(R)].F - R[i].F) / (R[(i+1)%sz(R)].S - R[i].S) , h/2) );
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && insidev2)
		{
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && !insidev2)
		{
			temp.pb( mp( R[i].F + (h/2 - R[i].S) * (R[(i+1)%sz(R)].F - R[i].F) / (R[(i+1)%sz(R)].S - R[i].S) , h/2) );
		}
	}
	R.clear();
	for(i=0;i<sz(temp);i++)
	{
		R.pb(temp[i]);
	}


	// for(i=0;i<sz(R);i++)
	// {
	// 	printf("%lf %lf\n", R[i].F, R[i].S );
	// }
	// printf("DONE\n");		

	temp.clear();
	for(i=0;i<sz(R);i++)
	{
		insidev1 = (R[i].S >= -h/2);
		insidev2 = (R[(i+1)%sz(R)].S >= -h/2);
		if(!insidev1 && insidev2)
		{
			temp.pb( mp( R[i].F + (-h/2 - R[i].S) * (R[(i+1)%sz(R)].F - R[i].F) / (R[(i+1)%sz(R)].S - R[i].S) , -h/2) );
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && insidev2)
		{
			temp.pb( R[(i+1)%sz(R)] );
		}
		if(insidev1 && !insidev2)
		{
			temp.pb( mp( R[i].F + (-h/2 - R[i].S) * (R[(i+1)%sz(R)].F - R[i].F) / (R[(i+1)%sz(R)].S - R[i].S) , -h/2) );
		}
	}
	R.clear();
	for(i=0;i<sz(temp);i++)
	{
		R.pb(temp[i]);
	}	

	// for(i=0;i<sz(R);i++)
	// {
	// 	printf("%lf %lf\n", R[i].F, R[i].S );
	// }
	// printf("DONE\n");		

	for(i=0;i<sz(R);i++)
	{
		ans +=  area( R[i] , R[(i+1)%sz(R)] ) ;
	}

	printf("%.10lf\n", ans );

	return 0;
}