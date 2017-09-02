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

int DB[100007];
int DP[100007];
int CB[100007];
int CP[100007];
int Max[100007];

int MaxBeauty(int B[],int P[],int n,int tot)
{
	int i,j,ans=INT_MIN;
	for(i=0;i<100007;i++)
	{
		Max[i] = -1;
	}
	for(i=0;i<n;i++)
	{
		if( Max[ P[i] ] == -1 )
			Max[ P[i] ] = i;
		else
		{
			if( B[i] > B[ Max[ P[i] ] ] )
				Max[ P[i] ] = i;
		}
	}
	for(i=1;i<100007;i++)
	{
		if(Max[i-1]!=-1)
		{
			if( Max[i] == -1 )
			{
				Max[i] = Max[i-1];
			}
			else if( B[ Max[i] ] < B[ Max[i-1] ] )
			{
				Max[i] = Max[i-1];
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		if( tot >= P[i] )
		{
			if( Max[ tot-P[i] ]!=-1 && Max[ tot-P[i] ]!=i )
			{
				ans = max(ans, B[i]+B[ Max[ tot-P[i] ] ] );
			}
		}
	}
	return ans;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,p,m,n,Dn=0,Cn=0,x,y,z,a,b,c,d,r,ans;
	char type[2];
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(c);	sd(d);

	for(i=0;i<n;i++)
	{
		sd(b);	sd(p);	ss(type);
		if(type[0]==&#39;C&#39;)
		{
			CB[Cn] = b;	CP[Cn] = p;	Cn++;	
		}
		else
		{
			DB[Dn] = b;	DP[Dn] = p;	Dn++;
		}
	}

	ans = max(MaxBeauty(CB,CP,Cn,c),MaxBeauty(DB,DP,Dn,d));

	j = -1;
	for(i=0;i<Cn;i++)
	{
		if( c>=CP[i] )
		{
			j = max(j,CB[i]);
		}
	}

	k = -1;
	for(i=0;i<Dn;i++)
	{
		if( d>=DP[i] )
		{
			k = max(k,DB[i]);
		}
	}	

	if(j!=-1 && k!=-1)
		ans = max(ans,j+k);

	if(ans==INT_MIN)
		printf("0\n");
	else
		printf("%d\n", ans );
	
	return 0;
}