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

char S[1007][1007];
char ANS[30];
bool G[26][26];
bool hasParent[26];
bool iswritten[26];
bool temp[26];
bool temp2[26];
bool checked[26];

bool hascycle(int src)
{
	if(temp[src])
		return true;
	if(checked[src])
		return false;

	int i;
	bool has = false;
	temp[src] = true;
	for(i=0;i<26;i++)
	{
		if( G[src][i] )
		{
			has |= hascycle(i);
		}	
	}
	temp[src] = false;
	checked[src] = true;
	return has;	
}

void write(int src,int &a)
{
	if(temp2[src])
		return;

	temp2[src] = true;

	int i;
	for(i=0;i<26;i++)
	{
		if(G[src][i])
		{
			write(i,a);
		}	
	}

	iswritten[src] = true;
	ANS[a++] = &#39;a&#39;+src;
}

int main()
{
	int i,j,k,l,m,n;

	sd(n);

	for(i=0;i<n;i++)
	{
		ss(S[i]);
	}

	for(i=0;i<n-1;i++)
	{
		for(j=0;S[i][j]!=&#39;\0&#39; && S[i+1][j]!=&#39;\0&#39;;j++)
		{
			if( S[i][j] != S[i+1][j] )
			{
				hasParent[ S[i][j] - &#39;a&#39; ] = true;
				G[ S[i+1][j] - &#39;a&#39; ][ S[i][j] - &#39;a&#39; ] = true;
				break;
			}	
		}
		if(S[i][j]!=&#39;\0&#39; && S[i+1][j]==&#39;\0&#39;)
		{
			printf("Impossible\n");
			return 0;
		}	
	}

	bool chk = false;

	for(i=0;i<26;i++)
		if(hascycle(i))
			chk = true;

	if(chk)
	{
		printf("Impossible\n");
	}
	else
	{
		j=0;
		for(i=0;i<26;i++)
		{
			if(!hasParent[i])
				write(i,j);
		}
		for(i=0;i<26;i++)
		{
			if(!iswritten[i])
				ANS[j++] = i+&#39;a&#39;;	
		}
		ANS[j] = &#39;\0&#39;;
		printf("%s\n", ANS );	
	}


	return 0;
}
