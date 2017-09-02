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

char Str[17];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,p,q,r;
	bool flag;
	// ll i,j,k,l,m,n,x,y,z,a,b,p,q,r;
	
	ss(Str);	n = strlen(Str);

	flag = true;
	for(i=0;i<n/2;i++)
	{
		if(Str[i]!=Str[n-1-i])
			a++;
	}
	if( (a==0 && n%2==1) || a==1 )
	{
		printf("YES\n");
		return 0;
	}	
	printf("NO\n");
	return 0;
}