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

string Inputs[7];
bool isTaken[7];
int len[7];
vector<string> ans;
vector<string> temp;
string st;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,s11,s12,l1,s21,s22,l2;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	
	bool flag = false;

	cin >> Inputs[0];
	cin >> Inputs[1];
	cin >> Inputs[2];
	cin >> Inputs[3];
	cin >> Inputs[4];
	cin >> Inputs[5];

	len[0] = Inputs[0].length();
	len[1] = Inputs[1].length();
	len[2] = Inputs[2].length();
	len[3] = Inputs[3].length();
	len[4] = Inputs[4].length();
	len[5] = Inputs[5].length();

	for(s11=0;s11<6;s11++)		
	{
		if(isTaken[s11])
			continue;
		isTaken[s11] = true;
		for(s12=0;s12<6;s12++)
		{
			if(isTaken[s12])
				continue;			
			isTaken[s12] = true;
			for(l1=0;l1<6;l1++)
			{
				if(isTaken[l1])
					continue;				
				isTaken[l1] = true;
				for(s21=0;s21<6;s21++)		
				{
					if(isTaken[s21])
						continue;					
					isTaken[s21] = true;
					for(s22=0;s22<6;s22++)
					{
						if(isTaken[s22])
							continue;						
						isTaken[s22] = true;
						for(l2=0;l2<6;l2++)
						{
							if(isTaken[l2])
								continue;							
							isTaken[l2] = true;

							if( len[s11] > 2 && len[s12] > 2 && len[s21] > 2 && len[s22] > 2 && len[s11] + len[s12] == len[l1] + 1 && len[s21] + len[s22] == len[l2] + 1)
							{
								if( Inputs[s11][0] == Inputs[s21][0] && Inputs[s12][len[s12]-1] == Inputs[s22][len[s22]-1] && Inputs[l1][0] == Inputs[s21][len[s21]-1] && Inputs[s22][0] == Inputs[l1][len[l1]-1] && Inputs[l2][0] == Inputs[s11][len[s11]-1] && Inputs[s12][0] == Inputs[l2][len[l2]-1] && Inputs[l1][len[s11]-1] == Inputs[l2][len[s21]-1] )
								{
									flag = true;
									st = "";
									for(j=0;j<len[l1];j++)
									{
										st.pb(&#39;.&#39;);
									}	
									temp.clear();								
									for(i=0;i<len[l2];i++)
									{	
										temp.pb(st);
									}

									for(i=0;i<len[s11];i++)
										temp[0][i] = Inputs[s11][i];
									for(i=0;i<len[s21];i++)
										temp[i][0] = Inputs[s21][i];
									for(i=0;i<len[l1];i++)
										temp[len[s21]-1][i] = Inputs[l1][i];
									for(i=0;i<len[l2];i++)
										temp[i][len[s11]-1] = Inputs[l2][i];
									for(j=len[l1]-1,i=len[s12]-1;i>=0;i--,j--)
										temp[len[l2]-1][j] = Inputs[s12][i];
									for(j=len[l2]-1,i=len[s22]-1;i>=0;i--,j--)
										temp[j][len[l1]-1] = Inputs[s22][i];

									if( sz(ans) == 0 || temp<ans )
										ans = temp;

								}
							}

							isTaken[l2] = false;
						}	
						isTaken[s22] = false;
					}
					isTaken[s21] = false;
				}	
				isTaken[l1] = false;
			}
			isTaken[s12] = false;	
		}
		isTaken[s11] = false;
	}					

	if(!flag)
	{
		printf("Impossible\n");
		return 0;
	}
	else
	{
		for(i=0;i<sz(ans);i++)
			cout << ans[i] << endl;
	}

	return 0;
}