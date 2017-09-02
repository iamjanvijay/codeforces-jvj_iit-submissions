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

ll Pow10[20];
ll UpLim[20];

int noOfDig(ll z)
{
	int x=0;
	while(z!=0)
	{
		x++;
		z/=10;
	}
	// printf("%d\n", x );
	return x;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll l,r,i,j,k=0,m=1,x,y;
	int nl=0,nr=0;

	Pow10[0] = 1;
	for(i=1;i<=18;i++)
		Pow10[i]=10*Pow10[i-1];

	UpLim[0] = 0;	UpLim[1] = 9;
	for(i=2;i<=17;i++)
		UpLim[i]=UpLim[i-1]*10+9;

	slld(l);	slld(r);

	nl=noOfDig(l);	nr=noOfDig(r);

	// printf("%d %d\n", nl, nr );

	for(l; (l/Pow10[nl-1])<=9 && (l%10)!=(l/Pow10[nl-1]); l++);

	for(r; (r/Pow10[nr-1])>0 && (r%10)!=(r/Pow10[nr-1]);  r--);	

	// printf("%lld %lld\n", l , r );	

	nl=noOfDig(l);	nr=noOfDig(r);

	// printf("%d %d\n", nl, nr );

	if(l>r)
	{
		printf("0\n");
	}
	else if(nl==nr)
	{
		if(nl==1)
		{
			printf("%lld\n", r-l+1 );
		}
		else if(l%10 == r%10)
			printf("%lld\n", ((r%Pow10[nr-1])/10)-((l%Pow10[nl-1])/10)+1 );
		else
		{
			for(i=(l%10)+1;i<(r%10);i++)
				k+=Pow10[nl-2];
			k+=UpLim[nl-2]-((l%Pow10[nl-1])/10)+1;
			k+=((r%Pow10[nr-1])/10)+1;
			printf("%lld\n", k );
		}
	}
	else
	{
		for(i=nl+1;i<=nr-1;i++)
			k+=9*Pow10[i-2];	
		// printf("1. %lld\n", k );
		for(i=(l%10)+1;i<=9;i++)
		{
			if(nl>=2)
				k+=Pow10[nl-2];
		}
		// printf("2. %lld\n", k );

		if(nl>=2)
			k+=UpLim[nl-2]-((l%Pow10[nl-1])/10)+1;
		else
			k+=9-l+1;
		// printf("3. %lld\n", k );

		for(i=1;i<(r%10);i++)
			k+=Pow10[nr-2];
		// printf("4. %lld\n", k );

		k+=((r%Pow10[nr-1])/10)+1;
		// printf("5. %lld\n", k );

		printf("%lld\n", k );

	}
	
	return 0;
}