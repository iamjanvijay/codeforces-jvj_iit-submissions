#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n

bool hasAppeared[26];
char S[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n=0;
	ss(S);

	for(i=0;S[i]!=&#39;\0&#39;;i++)
		if(!hasAppeared[ S[i]-&#39;a&#39; ])
		{
			n++;
			hasAppeared[ S[i]-&#39;a&#39; ] = true;
		}
	
	if(!(n%2))
		printf("CHAT WITH HER!\n");	
	else
		printf("IGNORE HIM!\n");

	return 0;
}