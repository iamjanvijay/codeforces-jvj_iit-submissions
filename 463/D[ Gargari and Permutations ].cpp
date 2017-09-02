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

int A[1007][7];
vector<int> Prev[1007];
vector<int> Cur;
vector<int> Intersect;
int length[1007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,z;
	sd(n);	sd(k);

	for(j=0;j<k;j++)
	{
		for(i=0;i<n;i++)
		{
			sd(A[i][j]);
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			Prev[i].push_back(j);
		}
	}

	for(j=0;j<k;j++)
	{
		for(i=n-1;i>=0;i--)
		{
			Cur.clear();	Intersect.clear();
			for(l=0;l<i;l++)
			{
				Cur.push_back(A[l][j]);
			}
			sort(Cur.begin(), Cur.end());
			m=A[i][j];
			set_intersection(Cur.begin(), Cur.end(),Prev[m].begin(), Prev[m].end(),back_inserter(Intersect));
			Prev[m].clear();
			for(l=0;l<Intersect.size();l++)
				Prev[m].push_back(Intersect[l]);
		}
	}

	for(i=0;i<1007;i++)
		length[i]=-1;

	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(length[A[i][j]]==-1)
			{
				z = 1;
				for(l=0;l<Prev[A[i][j]].size();l++)
				{
					z = max(z,length[ Prev[A[i][j]][l] ]+1);
				}
				length[A[i][j]]	= z;
			}
		}
	}
	
	z=1;
	for(i=1;i<=n;i++)
	{
		z=max(z,length[i]);
	}

	printf("%d\n",z );

	return 0;
}