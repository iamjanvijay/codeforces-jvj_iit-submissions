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

int A[100007];
int DP[100007];
int S[100007];
set<int> T;
set<int>::iterator it;

void init()
{
	int i,j;
	for(i=2;i*i<=100004;i++)
	{
		if(S[i]==0)
		for(j=i*i;j<=100004;j+=i)
				S[j] = i;
	}
	for(i=2;i<=100004;i++)
	{	
		if(S[i]==0)
			S[i] = i;
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=0,n;
	init();
	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<n;i++)
	{
		if(A[i]==1)
		{
			m = 1;
			continue;
		}

		T.clear();
		j=A[i];
		while(j!=1)
		{
			T.insert(S[j]);
			j = j / S[j];
		}
		m = 0;
		for(it=T.begin();it!=T.end();it++)
		{
			DP[*it]++;
			m = max(m,DP[*it]);
		}
		for(it=T.begin();it!=T.end();it++)
		{
			DP[*it] = m;
		}		
	}
	
	for(i=1;i<=100000;i++)
		m = max(m,DP[i]);

	printf("%d\n", m );

	return 0;
}