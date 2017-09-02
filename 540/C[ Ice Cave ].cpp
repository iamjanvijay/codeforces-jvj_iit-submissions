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

char Mat[507][507];
bool reach[507][507];
int n,m;

void DFS(int x2,int y2)
{
	if(reach[x2][y2])
		return;
	reach[x2][y2] = true;

	if(x2-1>=0 && Mat[x2-1][y2]==&#39;.&#39;)
		DFS(x2-1,y2);

	if(x2+1<n && Mat[x2+1][y2]==&#39;.&#39;)
		DFS(x2+1,y2);

	if(y2-1>=0 && Mat[x2][y2-1]==&#39;.&#39;)
		DFS(x2,y2-1);

	if(y2+1<m && Mat[x2][y2+1]==&#39;.&#39;)
		DFS(x2,y2+1);	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,x1,y1,x2,y2;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
		ss(Mat[i]);

	sd(x1);	sd(y1);	x1--;	y1--;
	sd(x2);	sd(y2);	x2--;	y2--;

	k=0;
	if(x2-1>=0 && Mat[x2-1][y2]==&#39;.&#39;)
		k++;
	if(x2+1<n && Mat[x2+1][y2]==&#39;.&#39;)
		k++;
	if(y2-1>=0 && Mat[x2][y2-1]==&#39;.&#39;)
		k++;
	if(y2+1<m && Mat[x2][y2+1]==&#39;.&#39;)
		k++;

	DFS(x1,y1);

	if(Mat[x2][y2]==&#39;.&#39;)
	{
		if( (x2==x1-1 && y2==y1) || (x2==x1+1 && y2==y1) || (x2==x1 && y2==y1-1) || (x2==x1 && y2==y1+1) )
		{
			if(k<1)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
			return 0;
		}	
		else
		{
			if(k<2)
			{
				printf("NO\n");
				return 0;
			}
			else
			{
				if(reach[x2][y2])
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
		return 0;	
	}

	if(Mat[x2][y2]==&#39;X&#39;)
	{
		if( (x2==x1-1 && y2==y1) || (x2==x1+1 && y2==y1) || (x2==x1 && y2==y1-1) || (x2==x1 && y2==y1+1) )
		{
			printf("YES\n");
			return 0;
		}
		else
		{
			if(k<1)
				printf("NO\n");
			else
			{
				if(x2-1>=0 && Mat[x2-1][y2]==&#39;.&#39; && reach[x2-1][y2])
					printf("YES\n");
				else if(x2+1<n && Mat[x2+1][y2]==&#39;.&#39; && reach[x2+1][y2])
					printf("YES\n");
				else if(y2-1>=0 && Mat[x2][y2-1]==&#39;.&#39; && reach[x2][y2-1])
					printf("YES\n");
				else if(y2+1<m && Mat[x2][y2+1]==&#39;.&#39; && reach[x2][y2+1])
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
		return 0;
	}	
	
	return 0;
}