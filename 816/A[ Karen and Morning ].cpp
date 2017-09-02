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

char St[7];

bool isPal( char P[] )
{
	int i;
	for(i=0;i<4;i++)
	{
		if(P[i]!=P[3-i])
			return false;
	}
	return true;
}

void next( char P[] )
{
	if(P[3]!=&#39;9&#39;)
	{
		P[3]++;
		return;
	}

	if(P[3]==&#39;9&#39; && P[2]!=&#39;5&#39;)
	{
		P[3] = &#39;0&#39;;	P[2]++;
		return;
	}


	if(P[3]==&#39;9&#39; && P[2]==&#39;5&#39;)
	{
		P[3] = &#39;0&#39;;	P[2] = &#39;0&#39;;

		if(P[0]==&#39;0&#39; && P[1]!=&#39;9&#39;)
			P[1]++;
		else if (P[0]==&#39;0&#39; && P[1]==&#39;9&#39;)
		{
			P[0] = &#39;1&#39;; P[1] = &#39;0&#39;;
		}
		else if(P[0]==&#39;1&#39; && P[1]!=&#39;9&#39;)
			P[1]++;
		else if (P[0]==&#39;1&#39; && P[1]==&#39;9&#39;)
		{
			P[0] = &#39;2&#39;; P[1] = &#39;0&#39;;
		}
		else if(P[0]==&#39;2&#39; && P[1]!=&#39;3&#39;)
			P[1]++;
		else
			P[1] = P[0] = &#39;0&#39;;

		return;
	}

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,t;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(St);

	t = 0;

	for(i=2;i<5;i++)
		St[i] = St[i+1];

	while( !isPal(St) )
	{
		next(St);
		t++;
	}

	printf("%d\n", t );
	
	return 0;
}