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

char ini[3];
char fin[3];

int cw(char ini,char fin)
{
	if(ini == &#39;^&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 0;
			case &#39;>&#39; : return 1;
			case &#39;v&#39; : return 2;
			case &#39;<&#39; : return 3;
		}
	}
	if(ini == &#39;>&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 3;
			case &#39;>&#39; : return 0;
			case &#39;v&#39; : return 1;
			case &#39;<&#39; : return 2;
		}		
	}
	if(ini == &#39;v&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 2;
			case &#39;>&#39; : return 3;
			case &#39;v&#39; : return 0;
			case &#39;<&#39; : return 1;
		}		
	}
	if(ini == &#39;<&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 1;
			case &#39;>&#39; : return 2;
			case &#39;v&#39; : return 3;
			case &#39;<&#39; : return 0;
		}
	}			
}

int ccw(char ini,char fin)
{
	if(ini == &#39;^&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 0;
			case &#39;<&#39; : return 1;
			case &#39;v&#39; : return 2;
			case &#39;>&#39; : return 3;
		}
	}
	if(ini == &#39;>&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 1;
			case &#39;<&#39; : return 2;
			case &#39;v&#39; : return 3;
			case &#39;>&#39; : return 0;
		}		
	}
	if(ini == &#39;v&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 2;
			case &#39;<&#39; : return 3;
			case &#39;v&#39; : return 0;
			case &#39;>&#39; : return 1;
		}		
	}
	if(ini == &#39;<&#39;)
	{
		switch(fin)
		{
			case &#39;^&#39; : return 3;
			case &#39;<&#39; : return 0;
			case &#39;v&#39; : return 1;
			case &#39;>&#39; : return 2;
		}
	}			
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r,q,t;
	// ll i,j,k,l,m,n,x,y,z,a,b,r,q,t;

	ss(ini);	ss(fin);

	sd(n);

	x = cw(ini[0],fin[0]);	y = ccw(ini[0],fin[0]);	
	
	if( n%4==x && n%4==y )
		printf("undefined\n");
	else if( n%4==x )
		printf("cw\n");
	else if( n%4==y )
		printf("ccw\n");
	return 0;
}