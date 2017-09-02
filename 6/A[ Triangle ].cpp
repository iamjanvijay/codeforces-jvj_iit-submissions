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

int main()
{
	int i,j,k,s[4],ans=-1;

	for(i=0;i<4;i++)
		sd(s[i]);

	sort(s,s+4);

	for(i=0;i<4;i++)
		for(j=i+1;j<4;j++)
			for(k=j+1;k<4;k++)
				if(s[k] < s[i]+s[j])
					ans = 1;
				else if(ans==-1 && s[k] == s[i]+s[j])
					ans = 0;

	if(ans==0)
		printf("SEGMENT\n");
	else if(ans==1)
		printf("TRIANGLE\n");
	else
		printf("IMPOSSIBLE\n");		

	return 0;
}