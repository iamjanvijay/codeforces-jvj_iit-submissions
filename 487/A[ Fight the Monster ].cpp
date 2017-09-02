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

ll ceils(ll n,ll r)
{
	if(n%r==0)
		return n/r;
	else 
		return n/r+1;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a,b,r,HPY,ATKY,DEFY,HPM,ATKM,DEFM,RY,RM,h,d,C,MC=LLONG_MAX;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(HPY);	slld(ATKY);	slld(DEFY);
	slld(HPM);	slld(ATKM);	slld(DEFM);
	slld(h);	slld(a);	slld(d);

	for(i=0;i<=1000;i++) // ATKY
	{
		RM = max(0LL,(ATKY+i)-DEFM);

		if( RM != 0 )
			for(j=0;j<=100;j++) // DEFY
			{
				RY = max(0LL,ATKM-(DEFY+j));	
				C = j*d + i*a;
				
				if( RY == 0 )
				{
					MC = min(MC,C);
				}
				else
				{
					x = ceils(HPM,RM);
					if( x*RY+1 > HPY )
						MC = min(MC, C+h*(x*RY+1 - HPY) );
					else
						MC = min(MC,C);
				}
				
			}
	}

	printf("%lld\n", MC );
	
	return 0;
}