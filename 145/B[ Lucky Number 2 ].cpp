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

	int i,j,k,l,m,n,x,y,z,a1,a2,a3,a4,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(a1);		sd(a2);		sd(a3);		sd(a4);

	if( abs(a3-a4) > 1 )
	{
		printf("-1\n");
		return 0;
	}

	if( abs(a3-a4) == 0 )
	{
		if( a1>=a3+1 && a2>=a3 )
		{
			while(a1>a3)
			{
				printf("4");
				a1--;
			}

			while(a1>1)
			{
				printf("7");	a2--;
				printf("4");	a1--;
			}

			while(a2>0)
			{
				printf("7");	a2--;
			}

			while(a1>0)
			{
				printf("4");	a1--;
			}
			printf("\n");

			return 0;
		}
		else if( a1>=a3 && a2>=a3+1 )
		{
			if(a2>0)
			{
				printf("7");	a2--;
			}
			while(a1>a3)
			{
				printf("4");	a1--;
			}
			while(a3>0)
			{
				printf("4");	a1--;
				printf("7");	a2--;
				a3--;
			}
			while(a2>0)
			{
				printf("7");	a2--;
			}
			printf("\n");
			return 0;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}

	if(a3-a4==1)
	{
		if( a1>=a3 && a2>=a3 )
		{
			while(a1>a3)
			{
				printf("4");	a1--;
			}

			while(a3>0)
			{
				printf("4");	a1--;
				printf("7");	a2--;
				a3--;
			}

			while(a2>0)
			{
				printf("7");	a2--;
			}
			printf("\n");

			return 0;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}

	if(a4-a3==1)
	{
		if( a1>=a4 && a2>=a4 )
		{
			if(a2>0)
			{
				printf("7");	a2--;
			}

			while(a1>a4)
			{
				printf("4");	a1--;
			}

			while(a4>1)
			{
				printf("4");	a1--;
				printf("7");	a2--;
				a4--;
			}

			while(a2>0)
			{
				printf("7");	a2--;
			}

			if(a1>0)
			{
				printf("4");
			}	
			printf("\n");

			return 0;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}	
	
	printf("-1\n");
	return 0;
}