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

char S[100007];
int Pair[26];
char temp[7];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,ans=0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	for(i=0;i<26;i++)
		Pair[i] = -1;

	ss(S);	m = strlen(S);

	sd(n);
	for(i=0;i<n;i++)
	{
		ss(temp);
		Pair[temp[0]-&#39;a&#39;] = temp[1]-&#39;a&#39;;
		Pair[temp[1]-&#39;a&#39;] = temp[0]-&#39;a&#39;;
	}

	// for(i=0;i<26;i++)
		// printf("%d %d\n", i , Pair[i] );

	for(i=0;i<m;i++)
	{
		// printf("***%d\n", i );
		if(Pair[S[i]-&#39;a&#39;]!=-1)
		{
			x = y = 0;
			for(j=i;j<m;j++)
			{
				if(!( (S[j] == (Pair[S[i]-&#39;a&#39;]+&#39;a&#39;)) || (S[j] == S[i])  ))
					break;
				if(S[j]==(Pair[S[i]-&#39;a&#39;]+&#39;a&#39;))
					x++;
				if((S[j] == S[i]))
					y++;				
			}
			ans+=min(x,y);
			// printf("*%d %d\n", i , j-1 );
			i = j-1;
		}
	}
	
	printf("%d\n", ans );

	return 0;
}