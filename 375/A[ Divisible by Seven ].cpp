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

int Mod = 1000000007;
char Num[1000007];
int Count[10];

void process(char Num[],int l,int x)
{
	x = (10000*x)%7;
	x = (7-x)%7;
	if(x==0) //1869
	{
		Num[l++] = &#39;1&#39;;	Num[l++] = &#39;8&#39;;	Num[l++] = &#39;6&#39;;	Num[l++] = &#39;9&#39;;
	}
	else if(x==1) // 1968
	{
		Num[l++] = &#39;1&#39;;	Num[l++] = &#39;9&#39;;	Num[l++] = &#39;6&#39;;	Num[l++] = &#39;8&#39;;
	}
	else if(x==2) // 6981
	{
		Num[l++] = &#39;6&#39;;	Num[l++] = &#39;9&#39;;	Num[l++] = &#39;8&#39;;	Num[l++] = &#39;1&#39;;
	}
	else if(x==3) // 6198
	{
		Num[l++] = &#39;6&#39;;	Num[l++] = &#39;1&#39;;	Num[l++] = &#39;9&#39;;	Num[l++] = &#39;8&#39;;
	}
	else if(x==4) // 1698
	{
		Num[l++] = &#39;1&#39;;	Num[l++] = &#39;6&#39;;	Num[l++] = &#39;9&#39;;	Num[l++] = &#39;8&#39;;
	}
	else if(x==5) // 1986
	{
		Num[l++] = &#39;1&#39;;	Num[l++] = &#39;9&#39;;	Num[l++] = &#39;8&#39;;	Num[l++] = &#39;6&#39;;
	}	
	else  // 1896
	{
		Num[l++] = &#39;1&#39;;	Num[l++] = &#39;8&#39;;	Num[l++] = &#39;9&#39;;	Num[l++] = &#39;6&#39;;
	}
	Num[l++] = &#39;\0&#39;;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l=0,m,n,x=0,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(Num);	n = strlen(Num);

	for(i=0;i<n;i++)
	{
		Count[ Num[i]-&#39;0&#39; ]++;
	}

	if(Count[0]==n-4)
	{
		printf("1869");
		while(Count[0]--)
			printf("0");
		printf("\n");
		return 0;
	}

	for(i=9;i>=0;i--)
	{
		if(i==1 || i==6 || i==8 || i==9)
		{
			while(Count[i]>1)
			{
				x = (x*10 + i)%7;
				Num[l++] = &#39;0&#39;+i;
				Count[i]--;
			}
		}
		else
		{
			while(Count[i]>0)
			{
				x = (x*10 + i)%7;
				Num[l++] = &#39;0&#39;+i;
				Count[i]--;
			}
		}		
	}

	process(Num,l,x);

	printf("%s\n", Num );
	
	return 0;
}