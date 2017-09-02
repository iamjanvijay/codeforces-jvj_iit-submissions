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

	int i,j,k,l,m,n,x,y,z,a,b,r,t,s,v1,v2,t1,t2;
	// ll i,j,k,l,m,n,x,y,z,a,b,r,t;

	sd(s);	sd(v1);	sd(v2);	sd(t1);	sd(t2);

	x = t1 + v1*s + t1;
	y = t2 + v2*s + t2;

	if(x==y)
		printf("Friendship\n");
	else if(x<y)
		printf("First\n");
	else
		printf("Second\n");
	
	return 0;
}