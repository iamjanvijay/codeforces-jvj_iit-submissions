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
	int T,X=0;
	string S;
	sd(T);

	while(T--)
	{
		cin >> S;
		if(S=="X++" || S=="++X")
			X++;
		else
			X--;

	}

	printf("%d\n",X);

	return 0;
}