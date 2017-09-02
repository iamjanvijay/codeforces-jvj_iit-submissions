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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,p,q;
	double tmp1,tmp2;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(a);	sd(b);

	for(i=1;i<=1000;i++)	//	x
	{
		if(a*a-i*i > 0)
		{
			tmp1 = sqrt(a*a-i*i);
			if(tmp1==(int)tmp1 && tmp1 > 0)
			{
				j = (int)tmp1;	// y
				for(x=1;x<=1000;x++)
				{
					if(b*b-x*x > 0)
					{
						tmp2 = sqrt(b*b-x*x);
						if(tmp2==(int)tmp2 && tmp2 > 0)
						{
							y = (int)tmp2;
							if( i*x == j*y && y-j!=0)
							{
								p = 0;	q = 0;
								printf("YES\n");
								printf("%d %d\n", p, q);
								p += i;	q -= j;
								printf("%d %d\n", p, q);
								p += x;	q += y;
								printf("%d %d\n", p, q);
								return 0;
							}
						}						
					}
				}	
			}
		}
	}

	printf("NO\n");
	
	return 0;
}