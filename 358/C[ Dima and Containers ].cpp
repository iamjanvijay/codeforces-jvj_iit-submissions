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

priority_queue< pair<int,int> , vector< pair<int,int> >, less< pair<int,int> > > Q;
bool IsPopped[100007];
int Num[100007];
// stack<string> St;
pair<int,int> temp;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,d,r,it;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(Num[i]);

		if(Num[i]==0)
		{
			for(j=0;j<3 && Q.size()!=0;j++)
			{
				temp = Q.top();	Q.pop();
				IsPopped[temp.S] = true;
			}	
			while(Q.size()!=0)
				Q.pop();
		}
		else
		{
			Q.push( mp(Num[i],i) );
		}
	}

	a = 0;	b = 0;	c = 0;	d = 0;
	for(i=0;i<n;i++)
	{
		if(Num[i]==0)
		{
			z = min(3,min(1,a)+min(1,b)+min(1,c));
			printf("%d", z );

			if(z!=0)
				printf(" ");

			for(j=0;j<z;j++)
			{
				if((a+b+c+2)%3==0)
				{
					printf("popStack");
					if(j!=z-1)
						printf(" ");
					a--;
				}
				else if((a+b+c+2)%3==1)
				{
					printf("popQueue");
					if(j!=z-1)
						printf(" ");					
					b--;
				}
				else if((a+b+c+2)%3==2)
				{
					printf("popFront");
					if(j!=z-1)
						printf(" ");					
					c--;
				}
			}
			printf("\n");
		}
		else
		{
			if(IsPopped[i])
			{
				if((a+b+c)%3==0)
				{
					printf("pushStack\n");
					// St.push("popStack");
					a++;
				}
				else if((a+b+c)%3==1)
				{
					printf("pushQueue\n");
					// St.push("popQueue");
					b++;
				}
				else
				{
					printf("pushFront\n");
					// St.push("popFront");
					c++;
				}
			}
			else
			{
				printf("pushBack\n");
				d++;
			}

			// printf("%d %d %d %d\n",a,b,c,d );
		}
	}
	
	return 0;
}