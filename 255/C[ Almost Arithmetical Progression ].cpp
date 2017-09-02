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

int A[4007];
set<int> S;
set<int>::iterator it;
pair<int,bool> M[4007][4007];
int Ind[1000007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,maxi=1,n;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(A[i]);
		S.insert(A[i]);
	}

	if(n==1)
	{
		printf("1\n");
		return 0;
	}

	for(j=1,it=S.begin();it!=S.end();++it)
	{
		if(Ind[*it]==0)
		{
			Ind[*it] = j;
			j++;
		}
	}

	m = j;

	for(i=0;i<n;i++)
	{
		for(it=S.begin();it!=S.end();++it)
		{
			j = *it;
			if(j==A[i])
			{

				if( (M[ Ind[ A[i] ] ][ Ind[ j ] ].second) == false )
				{
					(M[ Ind[ A[i] ] ][ Ind[ j ] ].first)++;
					(M[ Ind[ A[i] ] ][ Ind[ j ] ].second) = true;
				}
				else if( (M[ Ind[ j ] ][ Ind[ A[i] ] ].second) == true )
				{
					(M[ Ind[ j ] ][ Ind[ A[i] ] ].first)++;
					(M[ Ind[ j ] ][ Ind[ A[i] ] ].second) = false;
				}

			}
			else
			{
				if( (M[ Ind[ A[i] ] ][ Ind[ j ] ].second) == false )
				{
					(M[ Ind[ A[i] ] ][ Ind[ j ] ].first)++;
					(M[ Ind[ A[i] ] ][ Ind[ j ] ].second) = true;
				}
				if( (M[ Ind[ j ] ][ Ind[ A[i] ] ].second) == true )
				{
					(M[ Ind[ j ] ][ Ind[ A[i] ] ].first)++;
					(M[ Ind[ j ] ][ Ind[ A[i] ] ].second) = false;
				}
			}	
		}
	}

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			maxi = max(maxi,(M[i][j].first));
		}	
	}

	printf("%d\n", maxi );
	return 0;
}