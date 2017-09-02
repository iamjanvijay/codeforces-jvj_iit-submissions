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



char S[107];
bool var[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=0,n,x=0,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(S);	n=strlen(S);

	for(i=0;i<n;i++)
	{
		// printf("*%d\n", i );
		if(S[i]==&#39;V&#39; && i+1<n && S[i+1]==&#39;K&#39;)
		{
			var[i] = var[i+1] = true;	m++;
		}
	}

	for(i=0;i<n-1;i++)
	{
		if(S[i]==&#39;K&#39; && S[i+1]==&#39;K&#39; && !var[i] && !var[i+1])
		{
			x++; 
		}
		else if(S[i]==&#39;V&#39; && S[i+1]==&#39;V&#39; && !var[i] && !var[i+1])
		{
			x++;	
		}	
	}

	if(x==0)
		printf("%d\n", m );
	else
		printf("%d\n", m+1 );
	
	return 0;
}