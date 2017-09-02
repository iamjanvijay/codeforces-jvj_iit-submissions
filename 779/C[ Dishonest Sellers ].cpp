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

struct Pair
{
	int a;
	int b;

	bool operator<(const Pair& Z) const
	{
		if(a != (Z.a))
			return a < (Z.a);
		else
			return b > (Z.b);
	}

};

Pair V[200007]={0};

int main()
{
	int i,j,k,l,n;
	int ans = 0,mini,z;

	sd(n);	sd(k);


	for(i=0;i<n;i++)
	{
		sd(V[i].a);
	}

	for(i=0;i<n;i++)
	{
		sd(V[i].b);
	}

	for(i=0;i<n;i++)
	{
		j = min((V[i].a),(V[i].b));
		ans += j;
		(V[i].a) -= j;
		(V[i].b) -= j;
		// printf("(%d %d)  ",V[i].a,V[i].b );
	}

	sort(V,V+n);

	for(i=1;i<n;i++)
		(V[i].a) += (V[i-1].a);

	for(i=n-2;i>=0;i--)
		(V[i].b) += (V[i+1].b);

	if(k!=n)
	{
		mini = ans + (V[k-1].a) + (V[k].b);
	}
	else
	{
		mini = ans + (V[k-1].a);
	}

	for(i=k;i<n;i++)
	{
		mini = min(mini, ans + (V[i].a) + (V[i+1].b) );
	}	

	cout << mini << endl;

	return 0;
}
