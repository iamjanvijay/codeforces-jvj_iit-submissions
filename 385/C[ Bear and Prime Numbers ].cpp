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

int Count[10000007] = {0};
int Seieve[10000007] = {0};
set<int> S; 
set<int> T; 
ll Ans[10000007] = {0};

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(k);	Count[k]++;
		S.insert(k);
	}

	for(i=2;i*i<10000007;i++)
	{
		if(!Seieve[i])
			for(Seieve[i]=i,j=2*i;j<10000007;j+=i)
			{
				Seieve[j] = i;
			}
	}

	for(i;i<10000007;i++)
	{
		if( !Seieve[i] )
			Seieve[i] = i;
	}

	set<int>::iterator it,Tit;
	for(it=S.begin();it!=S.end();++it)
	{
		l = k = *it;
		while(k!=1)
		{
			T.insert(Seieve[k]);
			k = k / Seieve[k];
		}
		for(Tit=T.begin();Tit!=T.end();++Tit)
			Ans[ *Tit ] += Count[l];
		T.clear();
	}

	for(i=2;i<10000007;i++)
		Ans[i] += Ans[i-1];

	sd(m);
	while(m--)
	{
		sd(l);	sd(r);
		if(l>10000000)
			printf("0\n");
		else if(r>10000000)
			printf("%lld\n", Ans[10000000] - Ans[l-1] );
		else
			printf("%lld\n", Ans[r] - Ans[l-1] );
	}
	
	return 0;
}