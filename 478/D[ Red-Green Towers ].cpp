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
int Mod=1000000007;
int M[200007][2];
int r0,g0,h0;

int answer()
{

	int r,h,i=0,j=1;
	ll z = ((ll)h0*(h0+1)/2);
	ll ways,g;
	for(h=0;h<=h0;h++)
	{
		z -= h;
		for(r=0;r<=r0;r++)
		{
			if(h==0)
			{
				M[r][i] = 1;
			}
			else
			{
				
				g=g0-( z - (r0-r) );
				if(r>=h)
					M[r][i] = M[r-h][j];
				else
					M[r][i] = 0;
				if(g0>=g && g>=h)
					M[r][i] += M[r][j];
				M[r][i]%=Mod;
			}	
		}
		i=1-i;
		j=1-j;
	}	
	return M[r0][1-i];
	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(r0);	sd(g0);

	int first=1,last=1000,mid;

	while(first+1<last)
	{
		mid = (first+last)/2;
		if( mid*(mid+1)/2 <= (r0+g0) )
			first = mid;
		else
			last = mid;
	}
	mid = last;
	if( mid*(mid+1)/2 <= (r0+g0) )
		h0 = last;
	else
		h0 = first;

	// printf("%d\n", h0 );

	printf("%d\n", answer() );	

	return 0;
}