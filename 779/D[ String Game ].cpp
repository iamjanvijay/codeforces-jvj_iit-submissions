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

char P[200007]; // Pattern
char S[200007]; // temp string
char T[200007]; // input string
int A[200007]; // order
set<int> Cont;
int n,m;

bool exists(int k) // after removing k elements possibility
{
	int i,j,l=0;
	for(i=0;i<k;i++)
		Cont.insert(A[i]);
	for(i=0;i<n;i++)
	{
		if(Cont.count(i)==0)
			S[l++] = T[i];
	}
	// S[l] = &#39;\0&#39;; printf("S :%s\n", S );
	Cont.clear();

	for(i=0,j=0;i<l&&j<m;)
	{
		if(S[i]==P[j])
		{
			i++;	j++;
		}
		else
		{
			i++;
		}	
	}

	if(j==m)
		return true;
	else
		return false;		

}

int binary()
{
	int mid,first = 0, last = n;

	while(first+1 < last)
	{
		mid = (first+last)/2;
		if( exists(mid) )
		{
			first = mid;
		}
		else
		{
			last = mid;
		}	
	}

	if(exists(last))
		return last;
	else
		return first;		

}

int main()
{
	int i,j,k,l;

	ss(T);
	ss(P);

	n = strlen(T);
	m = strlen(P);

	for(i=0;i<n;i++)
	{
		sd(A[i]);
		A[i]--;
	}

	printf("%d\n", binary() );
	// if( exists(4) )
	// 	printf("True\n");
	// else
	// 	printf("NO\n");;


	return 0;
}
