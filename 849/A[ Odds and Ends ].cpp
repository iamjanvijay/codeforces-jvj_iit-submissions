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
bool DP[107];
bool iscalc[107];

bool fun(int i,int n,int k)
{
	if(i==n && k==0)
		return true;
	if(A[i]%2==0)
		return false;

	if(iscalc[i])
		return DP[i];

	bool ans = false;
	for(int j=i;j<n;j++)
	{
		if((j-i+1)%2==1 && A[j]%2==1)
		{
			ans |= fun(j+1, n, 1-k);
		}
	}
	DP[i] = ans;	iscalc[i] = true;
	return ans;	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	if(A[0]%2==0)
	{
		printf("No\n");
		return 0;
	}
	else
	{
		if(fun(0,n,1)%2==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}