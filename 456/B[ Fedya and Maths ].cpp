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

char S1[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(S1);		n = strlen(S1);

	if(n==1)
		k = S1[0]-&#39;0&#39;;
	else
		k = (S1[n-2]-&#39;0&#39;)*10 + (S1[n-1]-&#39;0&#39;);

	if(k%4==0)
		a += 1;
	else if(k%4==1)
		a += 3;
	else if(k%4==2)
		a += 4;
	else	
		a += 2;

	if(k%4==0)
		a += 1;
	else if(k%4==1)
		a += 2;
	else if(k%4==2)
		a += 4;
	else	
		a += 3;

	if(k%2==0)
		a += 1;
	else 
		a += 4;	

	a++;
	
	printf("%d\n", a%5 );		

	
	return 0;
}