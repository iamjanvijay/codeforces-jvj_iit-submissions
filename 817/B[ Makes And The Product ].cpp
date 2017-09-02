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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	sort(A,A+n);

	if(A[0]!=A[1] && A[1]!=A[2])
	{
		a = 1;
		for(i=3;i<n && A[i]==A[i-1];i++)
			a++;
		printf("%d\n", a );
	}
	else if(A[0]==A[1] && A[1]==A[2])
	{
		a = 1;
		for(i=1;i<n && A[i]==A[i-1];i++)
			a++;
		printf("%lld\n", 1LL * a * (a-1) * (a-2) / 6 );
	}
	else if(A[0]==A[1] && A[1]!=A[2])
	{
		a=1;
		for(i=3;i<n && A[i]==A[i-1];i++)
			a++;
		printf("%d\n", a );		
	}
	else if(A[0]!=A[1] && A[1]==A[2])
	{
		a = 1;
		for(i=2;i<n && A[i]==A[i-1];i++)
			a++;
		printf("%lld\n", 1LL * a * (a-1) / 2 );
	}
	else
	{
		printf("-1\n");
	}

	return 0;
}