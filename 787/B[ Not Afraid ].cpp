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

map<int,bool> Pos; 
map<int,bool> Neg; 

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x;
	bool flag,overall=false;
	sd(n);	sd(m);

	while(m--)
	{
		flag = true;

		sd(k);
		while(k--)
		{	
			sd(x);
			if(x>0)
			{
				if(Neg[abs(x)])
					flag = false;
				Pos[abs(x)] = true;
			}
			else
			{
				if(Pos[abs(x)])
					flag = false;
				Neg[abs(x)] = true;
			}
		}

		overall |= flag;
		Pos.clear();
		Neg.clear();
	}	
	
	if(overall)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}