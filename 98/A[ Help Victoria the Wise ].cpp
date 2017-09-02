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

set<string> Perms;
set<string> Ans;
set<string>::iterator it;
string temp(6,&#39;0&#39;);
vector<int> tempV;

void allPerm(set<string> &ans, string &S, int curInd)
{
	if(curInd==S.length())
	{
		ans.insert(S);
		return;
	}

	for(int i=curInd;i<S.length();i++)
	{
		swap( S[i] , S[curInd] );
		allPerm(ans, S, curInd+1);
		swap( S[i] , S[curInd] );
	}

}

void assigntemp(string &temp, string &s, vector<int> &Ind)
{
	for(int i=0;i<s.length();i++)
		temp[ i ] = s[ Ind[i] ];
}

bool liesInAns(string s)
{
	bool flag = false;

	tempV.clear(); tempV.pb(0); tempV.pb(1); tempV.pb(2); tempV.pb(3); tempV.pb(4); tempV.pb(5);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;
	tempV.clear(); tempV.pb(0); tempV.pb(4); tempV.pb(1); tempV.pb(2); tempV.pb(3); tempV.pb(5);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(0); tempV.pb(3); tempV.pb(4); tempV.pb(1); tempV.pb(2); tempV.pb(5);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(0); tempV.pb(2); tempV.pb(3); tempV.pb(4); tempV.pb(1); tempV.pb(5);
	assigntemp(temp, s, tempV);			
	if( Ans.count(temp) )
		flag = true;

	tempV.clear(); tempV.pb(5); tempV.pb(1); tempV.pb(4); tempV.pb(3); tempV.pb(2); tempV.pb(0);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;
	tempV.clear(); tempV.pb(5); tempV.pb(2); tempV.pb(1); tempV.pb(4); tempV.pb(3); tempV.pb(0);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(5); tempV.pb(3); tempV.pb(2); tempV.pb(1); tempV.pb(4); tempV.pb(0);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(5); tempV.pb(4); tempV.pb(3); tempV.pb(2); tempV.pb(1); tempV.pb(0);
	assigntemp(temp, s, tempV);			
	if( Ans.count(temp) )
		flag = true;

	tempV.clear(); tempV.pb(1); tempV.pb(5); tempV.pb(2); tempV.pb(0); tempV.pb(4); tempV.pb(3);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;
	tempV.clear(); tempV.pb(1); tempV.pb(4); tempV.pb(5); tempV.pb(2); tempV.pb(0); tempV.pb(3);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(1); tempV.pb(0); tempV.pb(4); tempV.pb(5); tempV.pb(2); tempV.pb(3);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(1); tempV.pb(2); tempV.pb(0); tempV.pb(4); tempV.pb(5); tempV.pb(3);
	assigntemp(temp, s, tempV);			
	if( Ans.count(temp) )
		flag = true;	

	tempV.clear(); tempV.pb(3); tempV.pb(5); tempV.pb(4); tempV.pb(0); tempV.pb(2); tempV.pb(1);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;
	tempV.clear(); tempV.pb(3); tempV.pb(2); tempV.pb(5); tempV.pb(4); tempV.pb(0); tempV.pb(1);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(3); tempV.pb(0); tempV.pb(2); tempV.pb(5); tempV.pb(4); tempV.pb(1);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(3); tempV.pb(4); tempV.pb(0); tempV.pb(2); tempV.pb(5); tempV.pb(1);
	assigntemp(temp, s, tempV);			
	if( Ans.count(temp) )
		flag = true;		

	tempV.clear(); tempV.pb(2); tempV.pb(1); tempV.pb(5); tempV.pb(3); tempV.pb(0); tempV.pb(4);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;
	tempV.clear(); tempV.pb(2); tempV.pb(0); tempV.pb(1); tempV.pb(5); tempV.pb(3); tempV.pb(4);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(2); tempV.pb(3); tempV.pb(0); tempV.pb(1); tempV.pb(5); tempV.pb(4);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(2); tempV.pb(5); tempV.pb(3); tempV.pb(0); tempV.pb(1); tempV.pb(4);
	assigntemp(temp, s, tempV);			
	if( Ans.count(temp) )
		flag = true;		

	tempV.clear(); tempV.pb(4); tempV.pb(1); tempV.pb(0); tempV.pb(3); tempV.pb(5); tempV.pb(2);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;
	tempV.clear(); tempV.pb(4); tempV.pb(5); tempV.pb(1); tempV.pb(0); tempV.pb(3); tempV.pb(2);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(4); tempV.pb(3); tempV.pb(5); tempV.pb(1); tempV.pb(0); tempV.pb(2);
	assigntemp(temp, s, tempV);
	if( Ans.count(temp) )
		flag = true;	
	tempV.clear(); tempV.pb(4); tempV.pb(0); tempV.pb(3); tempV.pb(5); tempV.pb(1); tempV.pb(2);
	assigntemp(temp, s, tempV);			
	if( Ans.count(temp) )
		flag = true;

	return flag;						
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	string S;
	cin >> S;
	
	allPerm(Perms, S, 0);

	for(it=Perms.begin();it!=Perms.end();++it)
	{
		if( Ans.empty() || !liesInAns(*it) )
			Ans.insert(*it);
	}

	printf("%d\n", sz(Ans) );

	return 0;
}