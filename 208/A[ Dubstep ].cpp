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
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i;
	string S;
	string ANS = "";

	cin >> S ;	

	while(S!="")
	{	
		while(S.substr(0,3)=="WUB")
			S = S.substr(3,S.length()-3);
		i = 0;
		while( S.substr(i,3) != "" && S.substr(i,3)!="WUB")
			i++;
		if(ANS!="" && S.substr(0,i)!="")
			ANS += " ";
		ANS += S.substr(0,i);
		S = S.substr(i,S.length()-i);
	}

	cout << ANS << endl;
	
	return 0;
}