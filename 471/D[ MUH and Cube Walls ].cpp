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

int B[200007];
int E[200007];
int s[400007];
int z[400007];

int Occurances(int n,int p)
{
	int L = 0, R = 0,i;
	for (i = 1; i < n; i++) 
	{
	  if (i > R) 
	  {
	    L = R = i;
	    while (R < n && s[R-L] == s[R]) 
	    	R++;
	    z[i] = R-L; 
	    R--;
	  }
	  else 
	  {
	    int k = i-L;
	    if (z[k] < R-i+1) 
	    	z[i] = z[k];
	    else 
	    {
	      L = i;
	      while (R < n && s[R-L] == s[R]) 
	      	R++;
	      z[i] = R-L; 
	      R--;
	    }
	  }
	}

	int c=0;
	for(i=p+1;i<n;i++)
		if(z[i]==p)
			c++;
	return c;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,w;
	sd(n);	sd(w);

	for(i=0;i<n;i++)
		sd(B[i]);

	for(i=0;i<w;i++)
		sd(E[i]);

	if(w>n)
	{
		printf("0\n");
		return 0;
	}
	if(w==1)
	{
		printf("%d\n",n);
		return 0;
	}

	j=0;
	for(i=0;i<w-1;i++)
		s[j++] = E[i+1]-E[i];	

	s[j++] = INT_MAX;

	for(i=0;i<n-1;i++)
		s[j++] = B[i+1]-B[i];	

	printf("%d\n",Occurances(n+w-1,w-1) );

	return 0;
}