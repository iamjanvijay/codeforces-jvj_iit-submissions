#include <bits/stdc++.h>
using namespace std;
/* wromg */
#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n 

string A[1007][2];
bool isDup[1007];
set<string> S;

int main()
{
	int i,j,k,l,m,n;
	string s1,s2;
	sd(n);

	for(i=0;i<n;i++)
	{
		cin >> s1 >> s2;

		A[i][0] = s1.substr(0,3);
		A[i][1] = s1.substr(0,2) + s2.substr(0,1);
	}

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(A[i][0]==A[j][0])
			{
				isDup[i] = true;	isDup[j] = true;
			}	
		}	
	}	

	for(i=0;i<n;i++)
		if(isDup[i])
			S.insert(A[i][1]);


	for(k=0;k<n;k++)
	{
		bool flag = true;
		for(i=0;i<n;i++)
		{
			if(!isDup[i] && S.count(A[i][0]) == 1)
			{
				flag = false;
				isDup[i] = true;
				S.insert(A[i][1]);
			}	
		}
		if(flag)
			break;	
	}

	for(i=0;i<n;i++)
		if(!isDup[i])
			S.insert(A[i][0]);


	if(S.size()!=n)
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		printf("YES\n");
		for(i=0;i<n;i++)
			if(isDup[i])
				cout << A[i][1] << endl;
			else
				cout << A[i][0] << endl;		
	}				

	return 0;
}
