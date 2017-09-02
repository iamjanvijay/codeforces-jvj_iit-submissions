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

char St[17];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,d,r;
	bool flag;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(St);

	sort(St, St+3);
	sort(St+3, St+6);

	l = (St[0]-&#39;0&#39;) + (St[1]-&#39;0&#39;) + (St[2]-&#39;0&#39;);
	r = (St[3]-&#39;0&#39;) + (St[4]-&#39;0&#39;) + (St[5]-&#39;0&#39;);

	if(l==r)
		printf("0\n");
	else
	{
		if(l>r)
		{
			d = l-r;
			
			if( St[2]-&#39;0&#39; >= d || &#39;9&#39;-St[3] >= d )
				printf("1\n");
			else if( St[2]-&#39;0&#39; + &#39;9&#39;-St[3] >= d || St[2]-&#39;0&#39; + St[1]-&#39;0&#39; >= d || &#39;9&#39;-St[3] + &#39;9&#39;-St[4] >= d  )
				printf("2\n");
			else
				printf("3\n");
		}
		else // if(r>l)
		{
			d = r-l;

			if( St[5]-&#39;0&#39; >= d || &#39;9&#39;-St[0] >= d )
				printf("1\n");
			else if( St[5]-&#39;0&#39; + &#39;9&#39;-St[0] >= d || St[5]-&#39;0&#39; + St[4]-&#39;0&#39; >= d || &#39;9&#39;-St[0] + &#39;9&#39;-St[1] >= d  )
				printf("2\n");
			else
				printf("3\n");
		}
	}
	
	return 0;
}