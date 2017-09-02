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

char S[107];
char Srev[107];

bool chk(int x,int y,int l,int r)
{
	if(l!=0 && r!=0)
	{
		if(x%l!=0 || y%r!=0 || x/l<0 || y/r<0 || x/l!=y/r)
			return false;
	}

	if(l!=0 && r==0)
	{
		if(x%l!=0 || x/l<0 || y!=0)
			return false;
	}

	if(l==0 && r!=0)
	{
		if(y%r!=0 || y/r<0 || x!=0)
			return false;
	}	

	if(l==0 && r==0)
	{
		if(x!=0 || y!=0)
			return false;
	}

	return true;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n,a,b,x,y;

	sd(a);	sd(b);
	ss(S);	n = strlen(S);

	if( a==0 && b==0 )
	{
		printf("Yes\n");
		return 0;
	}	

	l=r=0;

	for(i=0;S[i]!=&#39;\0&#39;;i++)
	{

		if(S[i]==&#39;U&#39;)
			r++;
		else if(S[i]==&#39;D&#39;)
			r--;
		else if(S[i]==&#39;L&#39;)
			l--;
		else
			l++;

		if(S[i]==&#39;R&#39;)
			Srev[n-1-i] = &#39;L&#39;;
		else if(S[i]==&#39;L&#39;)
			Srev[n-1-i] = &#39;R&#39;;
		else if(S[i]==&#39;U&#39;)
			Srev[n-1-i] = &#39;D&#39;;
		else
			Srev[n-1-i] = &#39;U&#39;;
	}
	
	for(i=0;i<n;i++)
	{
		x = a;	y=b;
		for(j=i;j<n;j++)
		{
			if(Srev[j]==&#39;U&#39;)
				y++;
			else if(Srev[j]==&#39;D&#39;)
				y--;
			else if(Srev[j]==&#39;L&#39;)
				x--;
			else
				x++;
		}
		if( chk(x,y,l,r) )
		{
			printf("Yes\n");
			return 0;
		}
	}	
	printf("No\n");
	return 0;
}