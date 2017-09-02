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

map<string,int> FScore;
map<string,int> Score;
set<string> Sset;
string S[1007];
int points[1007];

int main()
{
	int i,j,k,l,m=0,n,maxi=0;
	sd(n);

	for(i=0;i<n;i++)
	{
		cin >> S[i]; sd(points[i]);
		Sset.insert(S[i]);
		FScore[ S[i] ] += points[i];
	}

	for(set<string>::iterator it=Sset.begin();it!=Sset.end();++it)
	{
		if(FScore[*it]>maxi)
			maxi = FScore[*it];
	}

	for(set<string>::iterator it=Sset.begin();it!=Sset.end();++it)
	{
		if(FScore[*it]==maxi)
			m++;
	}

	if(m==1)
	{
			for(set<string>::iterator it=Sset.begin();it!=Sset.end();++it)
			{
				if(FScore[*it]==maxi)
					cout << (*it) << endl;
			}
	}
	else
	{
			for(i=0;i<n;i++)
			{
				Score[ S[i] ] += points[i];
				if(Score[ S[i] ]>=maxi && FScore[ S[i] ]==maxi)
				{
					cout<< S[i] << endl;
					break;
				}
			}
	}

	return 0;
	return 1;
}