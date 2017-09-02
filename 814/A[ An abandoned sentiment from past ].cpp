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

int A[107];
int B[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<k;i++)
		sd(B[i]);

	if(k==1)
	{
		for(i=0;i<n;i++)
		{
			if(A[i]==0)
				A[i] = B[0];
		}

		bool flag = true;

		for(i=1;i<n;i++)
		{
			if(A[i-1]>A[i])
				flag = false;
		}

		if(!flag)
			printf("Yes\n");
		else
			printf("No\n");

	}
	else
		printf("Yes\n");
	
	return 0;
}