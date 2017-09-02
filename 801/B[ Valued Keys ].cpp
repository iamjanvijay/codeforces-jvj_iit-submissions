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

char S1[107],S2[107],S3[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	ss(S1);	ss(S2);	n=strlen(S1);

	for(i=0;i<n;i++)
	{
		if(S1[i]==S2[i])
		{
			S3[i] = S2[i];
		}
		else if(S1[i]<S2[i])
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			S3[i] = S2[i];
		}
	}

	S3[i] = &#39;\0&#39;;

	printf("%s\n", S3 );

	return 0;
}