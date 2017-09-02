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
	int x,y;
	int absx,absy;
	Pair(int a,int b)
	{
		x=a;	y=b;
		absx = abs(a);	absy = abs(b);
	}
	bool operator<(const Pair &b) const
	{
		if(absx!=b.absx)
			return absx < b.absx;
		return absy < b.absy;
	}
};

vector<Pair> V;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,x,y,m=0,n;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(x);	sd(y);
		k = 0;
		if(x!=0)
			k++;
		if(y!=0)
			k++;
		m += 2*k + 2;
		V.push_back( Pair(x,y) );
	}

	sort(V.begin(), V.end());
	printf("%d\n", m );
	for(i=0;i<n;i++)
	{
		if((V[i].x) != 0)
		{
			if((V[i].x) > 0)
			{
				printf("1 %d R\n", V[i].absx );
			}
			if((V[i].x) < 0)
			{
				printf("1 %d L\n", V[i].absx );
			}			
		}

		if((V[i].y) != 0)
		{
			if((V[i].y) > 0)
			{
				printf("1 %d U\n", V[i].absy );
			}
			if((V[i].y) < 0)
			{
				printf("1 %d D\n", V[i].absy );
			}			
		}
		printf("2\n");
		if((V[i].y) != 0)
		{
			if((V[i].y) > 0)
			{
				printf("1 %d D\n", V[i].absy );
			}
			if((V[i].y) < 0)
			{
				printf("1 %d U\n", V[i].absy );
			}			
		}		

		if((V[i].x) != 0)
		{
			if((V[i].x) > 0)
			{
				printf("1 %d L\n", V[i].absx );
			}
			if((V[i].x) < 0)
			{
				printf("1 %d R\n", V[i].absx );
			}			
		}
		printf("3\n");	

	}

	return 0;
}