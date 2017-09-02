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

char a[107];
char c[107];
int nexts[107][27];
int temp[27];
bool state[107][107];
pair<int, int> stateVal[107][107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,b,r,na,nc,la,d,lc,ans;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(b);			sd(d);
	ss(a);			ss(c);
	na = strlen(a);	nc = strlen(c);

	for(i=0;i<26;i++)
		temp[i] = -1;

	for(i=na-1;i>=0;i--)
	{
		temp[ a[i]-&#39;a&#39; ] = i;
	}

	for(i=na-1;i>=0;i--)
	{
		for(j=0;j<26;j++)
			nexts[i][j] = temp[j];
		temp[ a[i]-&#39;a&#39; ] = i;
	}

	la = lc = 0;
	j = 0;			// string c
	if(a[0]==c[0])
		i = 0;
	else
		i = nexts[0][c[0]-&#39;a&#39;];

	while( i!=-1 && !state[i][j] )
	{
		state[i][j] = true;
		stateVal[i][j] = mp(la, lc);

		j =  (j+1);
		if(j>=nc)
			lc++;
		j %= nc;

		if( nexts[i][c[j]-&#39;a&#39;] <= i )
			la++;
		i =  nexts[i][c[j]-&#39;a&#39;];
	}
	if(i==-1)
	{
		printf("0\n");
		return 0;
	}
	// printf("-> %d %d %d %d %d %d\n", la, lc, i , j, stateVal[i][j].F, stateVal[i][j].S );

	if(b < stateVal[i][j].F)
	{
		k = b;
		la = lc = 0;
		j = 0;			// string c
		if(a[0]==c[0])
			i = 0;
		else
			i = nexts[0][c[0]-&#39;a&#39;];		
		while( la < k )
		{
			j =  (j+1);
			if(j>=nc)
				lc++;
			j %= nc;

			if( nexts[i][c[j]-&#39;a&#39;] <= i )
				la++;
			i =  nexts[i][c[j]-&#39;a&#39;];
		}	
		printf("%d\n", lc, d );	
		return 0;
	}

	b -= stateVal[i][j].F;
	b -= 2;
	ans =  stateVal[i][j].S;
	ans += b/(la-stateVal[i][j].F) * (lc-stateVal[i][j].S);

	// printf("-> %d\n", ans );

	k = b%(la-stateVal[i][j].F) + 2;
	// k = 6;

	la = lc = 0;
	while( la < k )
	{
		j =  (j+1);
		if(j>=nc)
			lc++;
		j %= nc;

		if( nexts[i][c[j]-&#39;a&#39;] <= i )
			la++;
		i =  nexts[i][c[j]-&#39;a&#39;];
	}	
	// printf("la : %d lc : %d\n", la, lc );
	ans += lc;

	printf("%d\n", ans / d );
	
	return 0;
}