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

int A[4][4];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,o,p,q,w,x,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	bool flag = false;

	for(i=0;i<4;i++)
	{
		sd(A[i][0]);	sd(A[i][1]);	sd(A[i][2]);	sd(A[i][3]);
	}

	for(i=0;i<4;i++)
	{
		if(A[i][3] && (A[i][1] || A[i][0] || A[i][2] || A[(i+1)%4][0] || A[(i+2)%4][1] || A[(i+3)%4][2]))
			flag = true;
	}

	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}