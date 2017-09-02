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

int A[100007];
int B[100007];
int n,p;

bool chk(double t)
{
	double k=0;
	int i,j;

	for(i=0;i<n;i++)
	{
		if(B[i]-A[i]*t < 0)
		{
			k += (A[i]*t-B[i])/p;
		}
	}

	if(k<=t)
		return true;
	return false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,x,y,z,a,b,r;
	double first = 0,last=100000000000000,mid;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(p);

	for(i=0;i<n;i++)
	{
		sd(A[i]);sd(B[i]);
	}


	if(chk(last))
	{
		printf("-1\n");
		return 0;
	}

	while(last-first > 0.0001)
	{
		mid = (first+last)/2;
		if(chk(mid))
			first = mid;
		else
			last = mid;
	}

	printf("%lf\n", (first+last)/2 );
		
	return 0;
}