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

char S[100007];
int coun[17];

int ceils(int x, int y)
{
	if(x%y==0)
		return x/y;
	return x/y+1;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(k);	ss(S);	n = strlen(S);

	x = 0;
	for(i=0;i<n;i++)
	{
		x += (S[i]-&#39;0&#39;);
		coun[S[i]-&#39;0&#39;]++;
	}

	if(x>=k)
	{
		printf("0\n");
		return 0;
	}

	x = k-x;

	for(i=0;i<9 && x>0;i++)
	{
		l = ceils(x,(9-i));
		m = min(l,coun[i]);
		a += m;
		x -= m*(9-i);
	}
	
	printf("%d\n", a );

	return 0;
}