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

vector< pair<int, char> > V;	

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(l);	sd(r);
		V.push_back( mp(l,&#39;L&#39;) );
		V.push_back( mp(r,&#39;R&#39;) );
	}

	sort(V.begin(), V.end());

	c = 0;
	for(i=0;i<sz(V);i++)
	{
		if(V[i].S==&#39;L&#39;)
			c++;
		else
			c--;
		if(c>2)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}