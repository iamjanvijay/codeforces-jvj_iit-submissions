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
#define sz(x)       (int)x.size()
#define Mod         1000000007

char S[1000007];
int entr[26];
int exi[26];
pair<int,char> A[100];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	ss(S);

	for(i=0;i<26;i++)
		entr[i] = exi[i] = -1;

	for(i=0;i<n;i++)
	{
		if(entr[S[i]-&#39;A&#39;]==-1)
			entr[S[i]-&#39;A&#39;] = i;
		exi[S[i]-&#39;A&#39;] = i;
	}

	j = 0;
	for(i=0;i<26;i++)
	{
		if(entr[i]!=-1)
			A[j++] = mp(entr[i],&#39;E&#39;);
		if(exi[i]!=-1)
			A[j++] = mp(exi[i],&#39;S&#39;);		
	}
	
	sort(A,A+j);

	x = 0;
	for(i=0;i<j;i++)
	{
		if(A[i].second == &#39;E&#39;)
			x++;
		if(A[i].second == &#39;S&#39;)
			x--;
		if(x>k)
		{
			printf("YES\n");
			return 0;	
		}		
	}

	printf("NO\n");

	return 0;
}