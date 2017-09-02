#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n 

vector<double> V;
double pi = 3.1415926535897932;

double angle(int x,int y)
{
	double xd = x,yd = y;

	if(y==0 && x>0)
		return 0;
	else if(y==0 && x<0)
		return 180;
	else if(x==0 && y>0)
		return 90;
	else if(x==0 && y<0)
		return 270;
	else if(x>0 && y>0)
		return atan(yd/xd) * 180 / pi;
	else if(x<0 && y>0)
		return 180 - atan(-yd/xd) * 180 / pi;
	else if(x<0 && y<0)
		return 180 + atan(yd/xd) * 180 / pi;
	else if(x>0 && y<0)
		return 360 - atan(-yd/xd) * 180 / pi;
	else
		return -1;
}

int main()
{
	int i,j,k,l,m,n,x,y;
	double ans = 0;
	sd(n);

	for(i=0;i<n;i++)
	{
		sd(x);	sd(y);
		V.push_back( angle(x,y) );
	}

	if(n==1)
	{
		printf("0.0000000000\n");
		return 0;
	}

	sort(V.begin(),V.end());

	for(i=1;i < V.size();i++)
	{
		ans = max( ans, V[i]-V[i-1] );
	}

	ans = max( ans, (360-V[ V.size() - 1 ])+V[0] );	

	ans = 360-ans;

	printf("%0.10lf\n", ans  );

	return 0;
}
