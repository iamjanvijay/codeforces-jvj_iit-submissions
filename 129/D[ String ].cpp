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

string st;
string temp;
pair<string, int> temp2;
priority_queue < pair<string, int> , vector< pair<string, int> >, greater< pair<string, int> > > s;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	cin >> st;	n = st.length();
	sd(k);

	for(i=0;i<n;i++)
	{
		temp.clear();
		temp.pb(st[i]);
		s.push( mp( temp, i+1 ) );
	}
	
	while( s.size() > 0 && k-1 > 0 )
	{
		temp2 = s.top();
		// cout << "Popping " << temp2.F << endl;
 		s.pop();
		k--;
		if(temp2.S < n)
		{
			temp2.F.pb( st[temp2.S] );
			(temp2.S)++;
			s.push(temp2);
		}
	}

	if(s.size()==0)
		printf("No such line.\n");
	else
	{
		cout << s.top().F << endl;
	}

	return 0;
}