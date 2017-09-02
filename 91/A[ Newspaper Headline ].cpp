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

char S1[10007];
int S1occ[10007][26];
char S2[1000007];
bool has1[26];
bool has2[26];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n1,n2,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(S1);		ss(S2);
	n1 = strlen(S1);	n2 = strlen(S2);

	for(i=0;i<n2;i++)
	{
		has2[ S2[i]-&#39;a&#39; ] = true;
	}

	for(i=0;i<n1;i++)
	{
		has1[ S1[i]-&#39;a&#39; ] = true;
	}

	for(i=0;i<26;i++)
	{
		if(has2[i] && !has1[i])
		{
			printf("-1\n");
			return 0;
		}
	}

	for(j=0;j<26;j++)
		S1occ[n1][j] = n1;	

	for(i=n1-1;i>=0;i--)
	{
		if(i==n1-1)
		{
			for(j=0;j<26;j++)
				S1occ[i][j] = n1;
		}		
		else 
		{
			for(j=0;j<26;j++)
				S1occ[i][j] = S1occ[i+1][j];
		}
		S1occ[i][S1[i]-&#39;a&#39;] = i;
	}

	i = 0;  j = 0; k = 1;

	while(i<n2)
	{
		// while(j<n1 && S1[j]!=S2[i])
		// 	j++;
		j = S1occ[j][S2[i]-&#39;a&#39;];
		// printf("%d %d\n", j , i );
		if( j >= n1 )
		{
			k++;	j=0;
		}
		else if( S1[j]==S2[i] )
		{
			i++;	j++;
		}
	}

	printf("%d\n", k );
	
	return 0;
}