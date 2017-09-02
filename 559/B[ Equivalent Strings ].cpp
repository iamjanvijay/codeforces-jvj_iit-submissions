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

string lexigraphSmall(string s)
{
	if(s.length()%2==1)
		return s;
	string s1 = lexigraphSmall( s.substr( 0 , s.length()/2 ) ) ;
	string s2 = lexigraphSmall( s.substr( s.length()/2 , s.length() ) );
	if(s1<s2)
		return s1+s2;
	else
		return s2+s1;
}

int main()
{
	string s1,s2,lss1,lss2;

	cin >> s1 >> s2;

	lss1 = lexigraphSmall(s1);
	lss2 = lexigraphSmall(s2);

	if(lss1 == lss2)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}