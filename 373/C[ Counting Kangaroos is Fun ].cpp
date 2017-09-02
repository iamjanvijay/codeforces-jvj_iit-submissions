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

int s[500007];

bool chk(int k, int n)
{
	int i,j;
	for(i=k-1,j=n-1;i>=0 && j>=k;i--,j--)
		if( !(s[j]>=2*s[i]) )
			return false;
	if(i>=0)
		return false;
	return true;		
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,md,fs,ls;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	sd(n);
	for(i=0;i<n;i++)
		sd(s[i]);

	sort(s, s+n);

	fs = 0;		ls = n/2 + 7;

	while(fs+1<ls)
	{
		md = (fs+ls)/2;
		if( chk(md,n) )
			fs = md;
		else
			ls = md;
	}

	printf("%d\n", n - fs );

	return 0;
}