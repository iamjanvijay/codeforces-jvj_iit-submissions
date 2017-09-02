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
int R[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=0,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			R[m++] = i;
			if(i*i!=n)
				R[m++] = n/i;
		}
	}

	sort(R,R+m);

	for(i=0;i<m;i++)
	{
		if(n/R[i]<=2)
			continue;
		for(k=0;k<R[i];k++)
		{
			bool flag = true;
			for(j=k;j<n;j+=R[i])
			{
				if(A[j]!=1)
				{
					flag = false;	break;
				}
			}
			if(flag)
			{
				printf("YES\n");	return 0;
			}
		}
	}

	printf("NO\n");
	return 0;
}