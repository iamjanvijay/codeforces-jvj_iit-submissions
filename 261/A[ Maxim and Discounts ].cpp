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

int Q[100007];
int A[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,ans=0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(m);
	for(i=0;i<m;i++)
		sd(Q[i]);

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	sort(A,A+n,greater<int>());
	sort(Q,Q+m);

	k = Q[0];

	i = 0;
	while(i<n)
	{
		for(j=i;j<i+k && j<n;j++)
			ans+=A[j];
		i = j+2;
	}	

	printf("%d\n", ans );
		
	return 0;
}