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

	int i,j,k,l,m,n,x,y,z,a,b,r,fs, ls, md;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(k);	
	if(k==0)
	{
		printf("a\n");
		return 0;
	}
	i = 0;
	while(k>0)
	{
		fs = 0;	ls = 1000;
		while(fs+1<ls)
		{
			md = (fs+ls)/2;
			if( md*(md-1)/2 <= k )
				fs = md;
			else
				ls = md;
		}

		k-=(fs*(fs-1)/2);
		while(fs--)
			printf("%c", &#39;a&#39;+i );
		i++;
	}

	printf("\n");
	
	return 0;
}