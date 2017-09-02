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

string nxt(string x)
{
	string ans = "";

	if( x.at(0) == &#39;z&#39; )
	{
		ans.pb( &#39;A&#39; );
		return ans;
	}
	else
	{
		ans.pb( 1 + x.at(0) );
		return ans;
	}
}

pair<string,string> fun(int n)
{
	if(n==1)
	{
		return mp("a","a");
	}
	
	if(n==2)
	{
		return mp("abb","ab");
	}	

	pair<string,string> temp;	
	string ad;

	if(n%2==0)
	{
		temp = fun(n/2-1);
		ad = nxt( temp.S.substr(temp.S.length()-1,1) );
		return mp( temp.F.substr(0,temp.S.length()) + ad + ad + temp.F.substr( temp.S.length(),temp.F.length()-temp.S.length() ) + ad + ad , temp.S+ad );
	}
	else
	{
		temp = fun(n/2);
		ad = nxt( temp.S.substr(temp.S.length()-1,1) );
		return mp( temp.F.substr(0,temp.S.length()) + ad + temp.F.substr( temp.S.length(),temp.F.length()-temp.S.length() ) + ad + ad , temp.S+ad );
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	pair<string,string> Ans = fun(n);

	cout << Ans.F << " " << Ans.S << endl;
	
	return 0;
}