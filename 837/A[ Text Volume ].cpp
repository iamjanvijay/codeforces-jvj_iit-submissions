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

char St[207];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	char c;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	i = 0;
	c = getchar();

	while( (c = getchar()) != &#39;\n&#39; )
	{
		St[i++] = c;
	}
	St[i] = &#39;\0&#39;;

	k = 0;
	for(i=0;i<n;i++)
	{
		a = 0;
		for(j=i;St[j]!=&#39;\0&#39; && St[j]!=&#39; &#39;;j++)
		{
			if(&#39;A&#39;<=St[j] && St[j]<=&#39;Z&#39;)
				a++;
		}
		k = max(k,a);
		i = j;
	}
	
	printf("%d\n", k );

	return 0;
}