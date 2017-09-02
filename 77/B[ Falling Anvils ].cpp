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

int main()
{
	int i,j,k,a,b,T;
	double ans;
	sd(T);

	while(T--)
	{
		sd(a);	sd(b);

		if(a==0 && b==0)
			ans = 1;
		else if(a==0 && b!=0)
			ans = 0.5;
		else if(a!=0 && b==0)
			ans = 1.0;
		else if(a <= 4*b)
			ans = 0.5 + (double)a/16.0/b;
		else
			ans = ((double)(3.0*b)/(a)) + ((double)(a-4.0*b)/a);
		cout<< ans << endl;
	}

	return 0;
}
