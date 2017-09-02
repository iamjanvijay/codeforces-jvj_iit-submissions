#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

char M[107][107];
bool Vis[107][107];
char Buf[10007];
char Ans[10007];
int nAns,n,m;
bool sUD,sLR,fUD,fLR;

void DFS(int x,int y,int i)
{
	if(Vis[x][y])
		return;

	Vis[x][y] = true;

	if(M[x][y]==&#39;F&#39;)
	{
		int j;
		for(j=0;j<i;j++)
			Ans[j] = Buf[j];
		nAns = i;
		return;
	}

	if(M[x][y]==&#39;*&#39;)
	{
		return;
	}

	if(M[x][y]==&#39;.&#39;)
	{
		if(x+1<n)	// D
		{
			Buf[i] = &#39;D&#39;;
			DFS(x+1,y,i+1);
		}
		if(x-1>=0)	// U
		{
			Buf[i] = &#39;U&#39;;
			DFS(x-1,y,i+1);	
		}
		if(y+1<m)	// R
		{
			Buf[i] = &#39;R&#39;;
			DFS(x,y+1,i+1);
		}
		if(y-1>=0) // L
		{
			Buf[i] = &#39;L&#39;;
			DFS(x,y-1,i+1);	
		}						
	}
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,x,y,xc,yc,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
		ss(M[i]);

	DFS(0,0,0);

	x = 1;	y = 1;
	fUD = fLR = false;
	for(i=0;i<nAns;i++)
	{
		if( (Ans[i]==&#39;U&#39; || Ans[i]==&#39;D&#39;) )
		{
			if(!fUD)
			{
				printf("%c\n", Ans[i] );
				fflush(stdout);
				sd(xc);	sd(yc);
				if(xc==x && yc==y)
				{
					sUD = true;
					if(Ans[i]==&#39;U&#39;)
						printf("D\n");
					else
						printf("U\n");
					fflush(stdout);	
					sd(xc);	sd(yc);				
				}
				else
				{
					sUD = false; 
				}
				fUD = true;
			}
			else
			{
				if(!sUD)
				{
					if(Ans[i]==&#39;U&#39;)
						printf("U\n");
					else
						printf("D\n");
					fflush(stdout);
					sd(xc);	sd(yc);	
				}
				else
				{
					if(Ans[i]==&#39;U&#39;)
						printf("D\n");
					else
						printf("U\n");
					fflush(stdout);
					sd(xc);	sd(yc);	
				}
			}
		}

		if( (Ans[i]==&#39;L&#39; || Ans[i]==&#39;R&#39;) )
		{
			if(!fLR)
			{
				printf("%c\n", Ans[i] );
				fflush(stdout);
				sd(xc);	sd(yc);
				if(xc==x && yc==y)
				{
					sLR = true;
					if(Ans[i]==&#39;L&#39;)
						printf("R\n");
					else
						printf("L\n");
					fflush(stdout);	
					sd(xc);	sd(yc);				
				}
				else
				{
					sLR = false; 
				}
				fLR = true;
			}
			else
			{
				if(!sLR)
				{
					if(Ans[i]==&#39;L&#39;)
						printf("L\n");
					else
						printf("R\n");
					fflush(stdout);
					sd(xc);	sd(yc);	
				}
				else
				{
					if(Ans[i]==&#39;L&#39;)
						printf("R\n");
					else
						printf("L\n");
					fflush(stdout);
					sd(xc);	sd(yc);	
				}
			}
		}
		x = xc;	y = yc;
	}

	return 0;
}