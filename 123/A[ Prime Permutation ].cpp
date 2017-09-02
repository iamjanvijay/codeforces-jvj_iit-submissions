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

char St[1007];

int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);	
}

bool vis[1007];
int Count[26];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,x,y,xc,yc,z,a,b,r,n;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(St); n = strlen(St);

	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(gcd(i,j)!=1)
				vis[i] = vis[j] = true;
		}
	}

	for(i=0;i<n;i++)
		Count[ St[i] - &#39;a&#39; ]++;

	k = 0;	
	for(i=1;i<=n;i++)
		if(vis[i])
			k++;

	bool flag = false;

	for(i=0;i<26;i++)
		if(Count[i]>=k)
		{
			flag = true;	break;
		} 

	if(!flag)
	{
		printf("NO\n");
		return 0;
	}	

	k = i;				

	for(i=0;i<n;i++)
		if(vis[i+1])
		{
			St[i] = &#39;a&#39;+k;
			Count[k]--;
		}

	for(j=0,i=0;i<n;i++)
		if(!vis[i+1])
		{
			while(Count[j]==0)
				j++;
			St[i] = &#39;a&#39;+j;
			Count[j]--;	
		}	

	printf("YES\n");
	printf("%s\n",St);


	return 0;
}