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

char S[57][57];
bool ischecked[57][57];

int n,m;

bool dfs(int i,int j,int pi,int pj,char X)
{
	if(ischecked[i][j])
		return true;

	ischecked[i][j] = true;
	bool flag = false;

	if(i+1<n && ( pj!=j || pi!=i+1 ) && S[i+1][j]==X)
		flag |= dfs(i+1,j,i,j,X);

	if(i-1>=0 && ( pj!=j || pi!=i-1 ) && S[i-1][j]==X)
		flag |= dfs(i-1,j,i,j,X);

	if(j+1<m && ( pi!=i ||  pj!=j+1 ) && S[i][j+1]==X)
		flag |= dfs(i,j+1,i,j,X);

	if(j-1>=0 &&  ( pi!=i || pj!=j-1 ) && S[i][j-1]==X)
		flag |= dfs(i,j-1,i,j,X);				

	return flag;
}

int main()
{
	int i,j,k,l;
	bool flag = false;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
		ss(S[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!ischecked[i][j])
			{
				flag |= dfs(i,j,-1,-1,S[i][j]);
				// for(k=0;k<n;k++)
				// {
				// 	for(l=0;l<m;l++)
				// 	{
				// 		if(ischecked[k][l])
				// 			printf("T");
				// 		else
				// 			printf("N");
				// 	}
				// 	printf("\n");	
				// }	
			}	
		}	
	}

	if(flag)
		printf("Yes\n");
	else
		printf("No\n");		

	return 0;
}
