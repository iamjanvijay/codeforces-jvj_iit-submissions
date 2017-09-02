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

vector<int> V;
vector<int>::iterator it;

int gcd(int divisor,int dividend)
{
	if(divisor==0)
		return dividend;
	return gcd(dividend%divisor,divisor);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int a,b,n,m,l,r,i,j;	

	sd(a);	sd(b);
	sd(n);

	m = gcd(min(a,b),max(a,b));

	for(i=1;i*i<=m;i++)
	{
		if(m%i==0)
		{
			if(i*i==m)
				V.push_back(i);
			else
			{
				V.push_back(i);	V.push_back(m/i);
			}
		}
	}

	sort(V.begin(), V.end());

	while(n--)
	{
		sd(l);	sd(r);
		it = upper_bound(V.begin(), V.end(),r);
		if(it==V.begin())
		{
			printf("-1\n");
		}
		else
		{
			--it;
			if( l<=(*it) && (*it)<=r )
				printf("%d\n", (*it) );
			else
				printf("-1\n");
		}
	}
	
	return 0;
}