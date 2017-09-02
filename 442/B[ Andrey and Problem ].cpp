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

double P[100],prod,sum;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		slf(P[i]);

	// for(i=0;i<n;i++)
	// 	printf("%0.10lf\n",P[i]);	

	sort(P,P+n);

	if(P[n-1]==1.0)
	{
		printf("%0.10lf\n", 1.0 );
		return 0;
	}

	prod = 1;	sum = 0;

	for(i=n-1;i>=0;i--)
	{
		if(sum<1)
		{
			prod *= (1-P[i]);	sum += (P[i]/(1-P[i]));
		}		
	}
	
	printf("%0.10lf\n",prod*sum);

	return 0;
}