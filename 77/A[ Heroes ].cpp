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

int encode(string s)
{
	if(s=="Anka")
		return 0;
	if(s=="Chapay")
		return 1;
	if(s=="Cleo")
		return 2;
	if(s=="Troll")
		return 3;
	if(s=="Dracul")
		return 4;
	if(s=="Snowy")
		return 5;
	if(s=="Hexadecimal")
		return 6;												
}

vector< pair<int,int> > V;
string s1,s2,s3;
int it[7];
int p[3];
int powe[3];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	x = INT_MAX;	y = INT_MIN;

	for(i=0;i<n;i++)
	{
		cin >> s1 >> s2 >> s3;
		V.pb( mp(encode(s1),encode(s3)) );
	}

	sd(powe[0]);	sd(powe[1]);	sd(powe[2]);	

	for(it[0]=0;it[0]<3;it[0]++)
	{

		for(it[1]=0;it[1]<3;it[1]++)
		{

			for(it[2]=0;it[2]<3;it[2]++)
			{
				
				for(it[3]=0;it[3]<3;it[3]++)
				{

					for(it[4]=0;it[4]<3;it[4]++)
					{
						for(it[5]=0;it[5]<3;it[5]++)
						{
							
							for(it[6]=0;it[6]<3;it[6]++)
							{

								p[0] = p[1] = p[2] = 0;
								for(i=0;i<7;i++)
								{
									p[ it[i] ]++;
								}

								if(p[0]==0 || p[1]==0 || p[2]==0)
									continue;

								a = 0;	
								for(i=0;i<n;i++)
								{
									if( it[V[i].F]==it[V[i].S] )
										a++;
								}

								c = b = powe[0]/p[0];

								for(i=0;i<3;i++)
								{
									if(b>powe[i]/p[i])
										b = powe[i]/p[i];
									if(c<powe[i]/p[i])
										c = powe[i]/p[i];										 
								}

								k = c-b;

								if(x==k)
								{
									if(y<a)
										y = a;
								}

								if(x>k)
								{
									x = k;
									y = a;
								}


							}

						}		
					}					

				}

			}			
			
		}
		
	}

	printf("%d %d\n", x, y );

	return 0;
}