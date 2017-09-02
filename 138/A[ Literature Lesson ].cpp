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

char S1[7][10007];
int Ind[7];

bool isvowel(char x)
{
	return (x==&#39;a&#39;)||(x==&#39;e&#39;)||(x==&#39;i&#39;)||(x==&#39;o&#39;)||(x==&#39;u&#39;);
}

int typ()
{
	// printf("0.%s\n1.%s\n2.%s\n3.%s\n", (((char*)S1[0])+Ind[0]),(((char*)S1[1])+Ind[1]),(((char*)S1[2])+Ind[2]),(((char*)S1[3])+Ind[3]) );
	if( strcmp( (((char*)S1[0])+Ind[0]) , (((char*)S1[1])+Ind[1]) ) == 0 && strcmp( (((char*)S1[2])+Ind[2]) , (((char*)S1[1])+Ind[1]) ) == 0 && strcmp( (((char*)S1[2])+Ind[2]) , (((char*)S1[3])+Ind[3]) ) == 0 )
		return 0;
	if( strcmp( (((char*)S1[0])+Ind[0]) , (((char*)S1[3])+Ind[3]) ) == 0 && strcmp( (((char*)S1[2])+Ind[2]) , (((char*)S1[1])+Ind[1]) ) == 0 )
		return 1;	
	if( strcmp( (((char*)S1[0])+Ind[0]) , (((char*)S1[2])+Ind[2]) ) == 0 && strcmp( (((char*)S1[3])+Ind[3]) , (((char*)S1[1])+Ind[1]) ) == 0 )
		return 2;	
	if( strcmp( (((char*)S1[0])+Ind[0]) , (((char*)S1[1])+Ind[1]) ) == 0 && strcmp( (((char*)S1[2])+Ind[2]) , (((char*)S1[3])+Ind[3]) ) == 0 )
		return 3;	
	return -1;				
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,cur=0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	bool flag = true;

	sd(n);	sd(k);

	for(j=0;j<n;j++)
	{
		Ind[0] = Ind[1] = Ind[2] = Ind[3] = -1;

		for(i=0;i<4;i++)
		{
			ss(S1[i]);	m = strlen(S1[i]);	x=0;

			for(l=m-1;l>=0 && flag;l--)
			{
				if(isvowel(S1[i][l]))
					x++;
				if(x==k)
					break;
			}

			if(l<0 && flag)
			{
				Ind[i] = -1;
				flag = false;
			}

			if(l>=0 && flag)
			{
				Ind[i] = l;
			}
		}

		if(flag)
		{
			a = typ();
			if(a==-1)
				flag = false;
			else if(cur==0)
				cur = a;
			else if( (a!=0 && cur!=0 && a!=cur) )
				flag = false;
		}	

	}

	if(!flag)
	{
		printf("NO\n");
	}
	else
	{
		if(cur==0)
			printf("aaaa\n");
		else if(cur==1)
			printf("abba\n");
		else if(cur==2)
			printf("abab\n");
		else if(cur==3)
			printf("aabb\n");
	}
	
	return 0;
}