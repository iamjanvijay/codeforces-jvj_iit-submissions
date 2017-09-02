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

char S[17];
char T[17];

ll fact[11];
double Pow5[11];

int main()
{
	ss(S);
	ss(T);

	int i,j,k,countS=0,countT=0,countQ=0,N = strlen(S);

	fact[0] = 1;	Pow5[0] = 1;
	for(i=1;i<11;i++)
	{
		fact[i] = i*fact[i-1];
		Pow5[i] = 0.5*Pow5[i-1];
	}

	for(i=0;i<N;i++)
	{
		if(S[i]==&#39;+&#39;)
			countS++;
		else
			countS--;
	}

	for(i=0;i<N;i++)
	{
		if(T[i]==&#39;+&#39;)
			countT++;
		else if(T[i]==&#39;-&#39;)
			countT--;
		else
			countQ++;
	}

	if(countQ == 0)
	{
		if(countT == countS)
			printf("%0.9lf\n",1.0 );
		else
			printf("%0.9lf\n",0.0 );
		return 0;
	}

	for(i=0,j=countQ;i<=countQ;i++,j--)
	{
		if( i-j == countS - countT )
			break;
	}

	if( i > countQ )
		printf("%0.9lf\n",0.0);
	else
	{
		printf("%0.9lf\n", Pow5[countQ]*fact[countQ]/fact[i]/fact[j]);
	}

	return 0;
}
