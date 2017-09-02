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

int A[200007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,q;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);	sd(q);

	for(i=0;i<n;i++)
	{
		sd(l);	sd(r);
		A[l]+=1;	A[r+1]-=1;	
	}

	for(i=1;i<200007;i++)
		A[i] += A[i-1];

	for(i=1;i<200007;i++)
	{
		if(A[i]>=k)
			A[i] = 1;
		else
			A[i] = 0;
		A[i]+=A[i-1];
	}	

	for(i=0;i<q;i++)
	{
		sd(l);	sd(r);

		printf("%d\n", A[r] - A[l-1] );

	}
	
	return 0;
}