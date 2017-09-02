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

string S[1007][2];

int main()
{
	int i,j,k,l,t,n;

	string s1,s2;

	cin>>s1>>s2;

	sd(n);

	for(i=0;i<n;i++)
	{
		cin>>S[i][0]>>S[i][1];
	}

	for(i=0;i<=n;i++)
	{
		cout<<s1<<" "<<s2<<"\n";

		if(S[i][0]==s1)
			s1 = S[i][1];
		else
			s2 = S[i][1];
	}	

	return 0;
}
