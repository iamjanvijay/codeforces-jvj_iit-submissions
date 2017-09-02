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

vector<int> A[107];

int Parent[107];
int Rank[107];

int find(int x)
{
	if(Parent[x]==x)
		return x;
	Parent[x] = find(Parent[x]);
	return Parent[x];
}

bool Union(int x,int y)
{
	int P_x = find(x);int P_y = find(y);

	if(P_x==P_y)
		return false;
	if(Rank[P_x] > Rank[P_y])
		Parent[P_y] = P_x;
	else if(Rank[P_y] > Rank[P_x])
		Parent[P_x] = P_y;
	else
	{
		Parent[P_y] = P_x;
		Rank[P_x]++;
	}
	return true;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l=0,m,n;
	bool flag = false;
	sd(n);	sd(m);

	for(i=1;i<=n;i++)
	{
		sd(k);
		if(k!=0)
			flag = true;
		while(k--)
		{
			sd(l);
			A[l].push_back(i);
		}
		Parent[i] = i;
		Rank[i] = 1;
	}	

	// printf("* %d %d %d %d %d\n", Parent[1], Parent[2], Parent[3], Parent[4], Parent[5] );
	// if( Union(1,2) )
	// printf("* %d %d %d %d %d\n", Parent[1], Parent[2], Parent[3], Parent[4], Parent[5] );
	if(!flag)
	{
		printf("%d\n", n );
		return 0;
	}

	k = n;

	for(i=1;i<=m;i++)
	{
		// printf("%d ",i );
		for(j=0;j<A[i].size();j++)
		{
			// printf("%d ", A[i][j] );
			if( Union(A[i][0],A[i][j]) )
				k--;
		}
		// printf("\n");
	}	
		
	printf("%d\n", k-1 );

	return 0;
}