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

int Seal[107][7];

int maxArea(int n1, int m1, int n2, int m2, int a, int b)
{
	if( ( a >= max(n1,n2) && b >= m1+m2 ) || ( a >= n1+n2 && b >= max(m1,m2) ) )
		return n1*m1 + n2*m2;
	return 0;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	int ans = 0;

	sd(n);	sd(a);	sd(b);

	for(i=0;i<n;i++)
	{
		sd(Seal[i][0]);		sd(Seal[i][1]);
	}

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			ans = max( ans , maxArea(Seal[i][0], Seal[i][1], Seal[j][0], Seal[j][1], a, b) );
			ans = max( ans , maxArea(Seal[i][0], Seal[i][1], Seal[j][1], Seal[j][0], a, b) );
			ans = max( ans , maxArea(Seal[i][1], Seal[i][0], Seal[j][0], Seal[j][1], a, b) );
			ans = max( ans , maxArea(Seal[i][1], Seal[i][0], Seal[j][1], Seal[j][0], a, b) );
		}
	}

	printf("%d\n", ans );
	
	return 0;
}